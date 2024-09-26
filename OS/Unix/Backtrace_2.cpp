/**
 * \file  Backtrace.cpp
 * \brief Bactrace
 *
 * \code{.console}

* \endcode
*/


//-------------------------------------------------------------------------------------------------
#include <StdStream/StdStream.h>
#include <StdTest/StdTest.h>
//#include <Stl.h>

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
    char addrStr[20 + 1] {};
    std::sprintf(addrStr, "%p", a_frame);

    // Prepare the command: addr2line -e <executable> <address>
    const std::string cmd = "addr2line -e Backtrace_2.exe -f -p " + std::string(addrStr);
    // std::cout << STD_TRACE_VAR(cmd) << std::endl;

    // Run addr2line command to get file and line number
    FILE *pipe = ::popen(cmd.c_str(), "r");
    STD_TEST_PTR(pipe);

    std::string result;

    char buffer[256] {};
    while (std::fgets(buffer, sizeof(buffer), pipe) != nullptr) {
        result += buffer;
    }

    ::pclose(pipe);

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

        // Get file and line information from addr2line
        const std::string &fileLine = ::getFileLine(frame);
        std::cout << "    " << STD_TRACE_VAR(fileLine);
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
