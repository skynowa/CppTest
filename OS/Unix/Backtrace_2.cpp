/**
 * \file  Backtrace.cpp
 * \brief Bactrace
 *
 * \code{.console}

 * \endcode
 */


//-------------------------------------------------------------------------------------------------
#include <iostream>
#include <dlfcn.h>
#include <execinfo.h>
#include <cxxabi.h>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <unistd.h>
//-------------------------------------------------------------------------------------------------
// Function to execute addr2line and get file and line number
std::string
getFileLine(
	const void *a_frame
)
{
    char addrStr[20] = {0};
    sprintf(addrStr, "%p", a_frame);

    // Prepare the command: addr2line -e <executable> <address>
    std::string command = "/usr/bin/addr2line -e /proc/self/exe -f -p ";
    command += addrStr;

    // Run addr2line command to get file and line number
    FILE* fp = popen(command.c_str(), "r");
    if (!fp) return "??";

    char buffer[256];
    std::string result = "";
    while (fgets(buffer, sizeof(buffer), fp) != nullptr) {
        result += buffer;
    }
    pclose(fp);

    return result;
}
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

		const char* demangled_name = nullptr;
		int status = -1;

		if (info.dli_sname) {
			demangled_name = abi::__cxa_demangle(info.dli_sname, nullptr, 0, &status);
			if (status == 0 && demangled_name) {
				std::printf("%-3d %p: %s (+%ld) [%s]\n", i, frame, demangled_name,
							(char*)frame - (char*)info.dli_saddr, info.dli_fname);
				std::free((void*)demangled_name);
			}
		}

		if (status == 0 && demangled_name) {
			std::printf("%-3d %p: %s (+%ld) [%s]\n", i, frame, demangled_name,
						(char*)frame - (char*)info.dli_saddr, info.dli_fname);
			std::free((void*)demangled_name);
		}
        else if (info.dli_sname) {
			std::printf("%-3d %p: %s (+%ld) [%s]\n", i, frame, info.dli_sname,
						(char*)frame - (char*)info.dli_saddr, info.dli_fname);
		}
        else {
			std::printf("%-3d %p: ?? [%s]\n", i, frame, info.dli_fname);
		}

		// Get file and line information from addr2line
		const std::string &file_line = ::getFileLine(frame);

		std::cout << "    " << file_line;
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
