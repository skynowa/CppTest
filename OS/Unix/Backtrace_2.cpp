/**
 * \file  Backtrace.cpp
 * \brief Bactrace
 *
 * \code{.console}
 *
 * \endcode
 *
 * \todo
 */


//-------------------------------------------------------------------------------------------------
#include <StdStream/StdStream.h>
#include <StdTest/StdTest.h>
// #include <Stl.h>
#include <fstream>

#if __cpp_lib_stacktrace
    #include <stacktrace>
#else
    #include <dlfcn.h>
    #include <execinfo.h>
    #include <cxxabi.h>
#endif
//-------------------------------------------------------------------------------------------------
struct mapping_entry_t
{
    uintptr_t start = 0;
    uintptr_t end = 0;
    uintptr_t offset_from_base = 0;

    inline bool contains_addr(const void* addr) const
    {
        uintptr_t addr_uint = reinterpret_cast<uintptr_t>(addr);
        return addr_uint >= start && addr_uint < end;
    }
};
//-------------------------------------------------------------------------------------------------
inline uintptr_t hex_str_to_int(const std::string& str)
{
    uintptr_t out;
    std::stringstream ss;
    ss << std::hex << str;
    ss >> out;
    if(ss.eof() && !ss.fail()) { // whole stream read, with no errors
        return out;
    } else {
        throw std::invalid_argument(std::string("can't convert '") + str + "' to hex");
    }
}
//-------------------------------------------------------------------------------------------------
inline mapping_entry_t parse_proc_maps_line(const std::string& line)
{
    std::string mapping_range_str, permissions_str, offset_from_base_str;
    std::istringstream line_stream(line);
    if(!std::getline(line_stream, mapping_range_str, ' ') ||
        !std::getline(line_stream, permissions_str, ' ') ||
        !std::getline(line_stream, offset_from_base_str, ' ')) {
        return mapping_entry_t{};
    }
    std::string mapping_start_str, mapping_end_str;
    std::istringstream mapping_range_stream(mapping_range_str);
    if(!std::getline(mapping_range_stream, mapping_start_str, '-') ||
        !std::getline(mapping_range_stream, mapping_end_str)) {
        return mapping_entry_t{};
    }
    mapping_entry_t mapping{};
    try {
        mapping.start = hex_str_to_int(mapping_start_str);
        mapping.end = hex_str_to_int(mapping_end_str);
        mapping.offset_from_base = hex_str_to_int(offset_from_base_str);
        return mapping;
    } catch(std::invalid_argument& e) {
        return mapping_entry_t{};
    }
}
//-------------------------------------------------------------------------------------------------
std::uintptr_t
get_own_proc_addr_base(
	const void* addr
)
{
    std::ifstream maps_file("/proc/self/maps");
    STD_TEST(maps_file.is_open());

    for (std::string line; std::getline(maps_file, line); ) {
        const mapping_entry_t mapping = parse_proc_maps_line(line);
        if (mapping.contains_addr(addr)) {
            return mapping.start - mapping.offset_from_base;
        }
    }

    STD_TEST(false);

    return {};
}
//-------------------------------------------------------------------------------------------------
// Function to execute addr2line and get file and line number
std::string
getFileLine(
    const void *a_frame
)
{
    std::string result;

    char addrStr[20 + 1] {};
    std::sprintf(addrStr, "%p", a_frame);
	// std::cout << "\t" << STD_TRACE_VAR(addrStr) << std::endl;

    // Prepare the command: addr2line -e <executable> <address>
    const std::string cmd =
    	"addr2line --exe=./Backtrace_2.exe "
    	"--functions --demangle --inlines --pretty-print " +
    	std::string(addrStr);
    // std::cout << STD_TRACE_VAR(cmd) << std::endl;

    FILE *pipe = ::popen(cmd.c_str(), "r");
    STD_TEST_PTR(pipe);

    char buffer[256] {};
    while (std::fgets(buffer, sizeof(buffer), pipe) != nullptr) {
        result += buffer;
    }

    ::pclose(pipe);

    // Trimming
    while (!result.empty() && (result[result.size() - 1] == '\n' || result[result.size() - 1] == '\r')) {
    	result.erase(result.size() - 1);
    }

    return result;
}
//-------------------------------------------------------------------------------------------------
std::string
source_location(const void* addr, bool position_independent)
{
    uintptr_t addr_base = 0;
    if (position_independent) {
        addr_base = ::get_own_proc_addr_base(addr);
    }
    const void* offset = reinterpret_cast<void*>(reinterpret_cast<uintptr_t>(addr) - addr_base);


#if 0
	std::string source_line = boost::stacktrace::detail::addr2line("-Cpe", reinterpret_cast<const void*>(offset));
	if (source_line.empty() || source_line[0] == '?') {
		return "";
	}

    return source_line;
#else
    std::string source_line = ::getFileLine(offset);
	if (source_line.empty() || source_line[0] == '?') {
		return "";
	}

	return source_line;
#endif
}
//-------------------------------------------------------------------------------------------------
void
printStackTrace()
{
#if __cpp_lib_stacktrace
    #warning "__cpp_lib_stacktrace - defined"

    auto trace = std::stacktrace::current();
    std::cout << std::to_string(trace) << std::endl;
#else
    const int  frames_max = 10;
    void      *frames[frames_max] {};

    // Capture the stack trace
    int addr_size = ::backtrace(frames, frames_max);
    if (addr_size == 0) {
        std::cerr << "No stack trace available" << std::endl;
        return;
    }

    for (int i = 0; i < addr_size; ++i) {
        const void *frame = frames[i];

        Dl_info info {};
        int iRv = ::dladdr(frame, &info);
        if (iRv == 0) {
            std::printf("%-3d %p: [no symbol]\n", i, frame);
            continue;
        }

        // Func name
		{
			int status {-1};
			char *demangledName = abi::__cxa_demangle(info.dli_sname, nullptr, nullptr, &status);
			if (status        == 0 &&
				demangledName != nullptr)
			{
				std::printf("%-3d %p: %s (+%ld) [%s]",
					i,
					frame,
					demangledName,
					(char *)frame - (char *)info.dli_saddr,
					info.dli_fname);

				std::free(demangledName);
				demangledName = nullptr;
			} else {
				std::printf("%-3d %p: %s [%s]",
					i,
					frame,
					"[n/a]",
					info.dli_fname);
			}
		}

        // Get file and line information from addr2line
		{
			// const std::string &fileLine = ::getFileLine(frame);
			std::string fileLine = ::source_location(frame, false);
			if ( fileLine.empty() ) {
				fileLine = ::source_location(frame, true);
			}

			if (fileLine.empty()) {
				fileLine = "[0]";
			}

			std::cout << "\t" << STD_TRACE_VAR(fileLine) << std::endl;
		}
    }
#endif
}
//-------------------------------------------------------------------------------------------------
void
testFunction()
{
    ::printStackTrace();
}
//-------------------------------------------------------------------------------------------------
int
main(int, char** argv)
{
    std::cout << STD_TRACE_VAR(argv[0]) << std::endl;

    ::testFunction();

    return EXIT_SUCCESS;
}
//-------------------------------------------------------------------------------------------------


#if OUTPUT

#endif
