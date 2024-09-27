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
#include <Stl.h>

#include <dlfcn.h>
#include <execinfo.h>
#include <cxxabi.h>
//-------------------------------------------------------------------------------------------------

/**************************************************************************************************
*   MappingEntry
*
**************************************************************************************************/

//-------------------------------------------------------------------------------------------------
class MappingEntry
	/// \see /proc/self/maps
{
public:
///\name ctors, dtor
///\{
	MappingEntry() = default;
	MappingEntry(const std::string &startStr, const std::string &endStr,
		const std::string &offsetFromBaseStr);
	~MappingEntry() = default;
///\}

	bool      containsAddr(const std::uintptr_t addr) const;
	uintptr_t addr() const;

private:
	const uintptr_t _start {};
	const uintptr_t _end {};
	const uintptr_t _offsetFromBase {};

	uintptr_t _hexStrToInt(const std::string &str) const;
};
//-------------------------------------------------------------------------------------------------
MappingEntry::MappingEntry(
	const std::string &a_startStr,
	const std::string &a_endStr,
	const std::string &a_offsetFromBaseStr
) :
	_start          { _hexStrToInt(a_startStr) },
	_end            { _hexStrToInt(a_endStr) },
	_offsetFromBase { _hexStrToInt(a_offsetFromBaseStr) }
{
}
//-------------------------------------------------------------------------------------------------
bool
MappingEntry::containsAddr(
	const std::uintptr_t a_addr
) const
{
	STD_TEST(a_addr != 0);

	return (a_addr >= _start && a_addr < _end);
}
//-------------------------------------------------------------------------------------------------
uintptr_t
MappingEntry::addr() const
{
	return (_start - _offsetFromBase);
}
//-------------------------------------------------------------------------------------------------
uintptr_t
MappingEntry::_hexStrToInt(
	const std::string &a_str
) const
{
	STD_TEST(!a_str.empty());

	uintptr_t out {};

	std::stringstream ss;
	ss << std::hex << a_str;
	ss >> out;

	// whole stream read, with no errors
	if (ss.eof() &&
		!ss.fail())
	{
		return out;
	}

	throw std::invalid_argument(std::string("can't convert '") + a_str + "' to hex");
}
//-------------------------------------------------------------------------------------------------


/**************************************************************************************************
*   Mappings
*
**************************************************************************************************/

//-------------------------------------------------------------------------------------------------
class Mappings
	/// \see /proc/self/maps
{
public:
///\name ctors, dtor
///\{
	Mappings() = delete;
	Mappings(const std::uintptr_t addr, const bool position_independent);
	~Mappings() = default;
///\}

	std::uintptr_t offset() const;

private:
	const std::uintptr_t _addr {};
	const bool           _position_independent {};

	std::uintptr_t _get_own_proc_addr_base(const std::uintptr_t addr) const;
	MappingEntry   _parse_proc_maps_line(const std::string &map_entry) const;
};
//-------------------------------------------------------------------------------------------------
Mappings::Mappings(
	const std::uintptr_t a_addr,
	const bool           a_position_independent
) :
	_addr                 {a_addr},
	_position_independent {a_position_independent}
{
	STD_TEST(a_addr != 0);
}
//-------------------------------------------------------------------------------------------------
std::uintptr_t
Mappings::offset() const
{
	std::uintptr_t addr_base {};

	if (_position_independent) {
		addr_base = _get_own_proc_addr_base(_addr);
	}

	const uintptr_t offset = _addr - addr_base;

	return offset;
}
//-------------------------------------------------------------------------------------------------
std::uintptr_t
Mappings::_get_own_proc_addr_base(
	const std::uintptr_t a_addr
) const
{
	std::ifstream maps_file("/proc/self/maps");
	STD_TEST(maps_file.is_open());

	for (std::string map_entry; std::getline(maps_file, map_entry); ) {
		MappingEntry mapping = _parse_proc_maps_line(map_entry);
		if ( mapping.containsAddr(a_addr) ) {
			return mapping.addr();
		}
	}

	STD_TEST(false);

	return {};
}
//-------------------------------------------------------------------------------------------------
MappingEntry
Mappings::_parse_proc_maps_line(
	const std::string &a_map_entry
) const
{
	std::string mapping_range_str;
	std::string permissions_str;
	std::string offset_from_base_str;
	{
		std::istringstream line_stream(a_map_entry);
		if (!std::getline(line_stream, mapping_range_str, ' ') ||
			!std::getline(line_stream, permissions_str, ' ') ||
			!std::getline(line_stream, offset_from_base_str, ' '))
		{
			return {};
		}
	}

	std::string mapping_start_str;
	std::string mapping_end_str;
	{
		std::istringstream mapping_range_stream(mapping_range_str);
		if (!std::getline(mapping_range_stream, mapping_start_str, '-') ||
			!std::getline(mapping_range_stream, mapping_end_str))
		{
			return {};
		}
	}

	try {
		MappingEntry mapping(mapping_start_str, mapping_end_str, offset_from_base_str);

		return mapping;
	}
	catch (const std::invalid_argument &e) {
		return {};
	}
}
//-------------------------------------------------------------------------------------------------


/**************************************************************************************************
*   Impl
*
**************************************************************************************************/

//-------------------------------------------------------------------------------------------------
// Function to execute addr2line and get file and line number
std::string
getAddr2line(
	const void *a_frame
)
{
	STD_TEST_PTR(a_frame);

	std::string result;

	std::string cmd;
	{
		char addrStr[20 + 1] {};
		std::sprintf(addrStr, "%p", a_frame);

		cmd =
			"addr2line "
			"--exe=Backtrace_2.exe "
			// "--functions --demangle --inlines --pretty-print "
			+ std::string(addrStr);
	}

	{
		FILE *pipe = ::popen(cmd.c_str(), "r");
		STD_TEST_PTR(pipe);

		char buffer[256] {};
		while (std::fgets(buffer, sizeof(buffer), pipe) != nullptr) {
			result += buffer;
		}

		::pclose(pipe);
	}

	// Trimming
	while (
		!result.empty() &&
		(result[result.size() - 1] == '\n' || result[result.size() - 1] == '\r')
	)
	{
		result.erase(result.size() - 1);
	}

	return result;
}
//-------------------------------------------------------------------------------------------------
std::string
getFileLine(
	const void *a_addr,
	const bool  a_position_independent
)
{
	STD_TEST_PTR(a_addr);

	Mappings mappings(reinterpret_cast<std::uintptr_t>(a_addr), a_position_independent);

	const std::string sRv = ::getAddr2line( reinterpret_cast<void *>(mappings.offset()) );
	if (sRv.empty() ||
		sRv[0] == '?')
	{
		return {};
	}

	return sRv;
}
//-------------------------------------------------------------------------------------------------

/**************************************************************************************************
*   Test
*
**************************************************************************************************/

//-------------------------------------------------------------------------------------------------
void
printStackTrace()
{
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

		// SourceInfoOption::funcName
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
					reinterpret_cast<std::uintptr_t>(frame) - reinterpret_cast<std::uintptr_t>(info.dli_saddr),
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

		// SourceInfoOption::filePath, SourceInfoOption::lineNum
		{
			std::string fileLine = ::getFileLine(frame, false);
			if ( fileLine.empty() ) {
				fileLine = ::getFileLine(frame, true);
			}

			if (fileLine.empty()) {
				fileLine = "[n/a]";
			}

			std::cout << "\t" << "at " << fileLine << std::endl;
		}
	}
}
//-------------------------------------------------------------------------------------------------
void
testFunction()
{
	::printStackTrace();
}
//-------------------------------------------------------------------------------------------------
int
main(int, char**)
{
	::testFunction();

	return EXIT_SUCCESS;
}
//-------------------------------------------------------------------------------------------------


#if OUTPUT

#endif
