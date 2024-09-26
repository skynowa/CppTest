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
getFileLine(void* addr)
{
    char addrStr[20] = {0};
    sprintf(addrStr, "%p", addr);

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
    const int max_frames = 10;
    void* addrlist[max_frames];

    // Capture the stack trace
    int addrlen = ::backtrace(addrlist, max_frames);

    if (addrlen == 0) {
        std::cerr << "No stack trace available" << std::endl;
        return;
    }

    for (int i = 0; i < addrlen; ++i) {
    	Dl_info info {};
    	int iRv = dladdr(addrlist[i], &info);
        if (iRv == 0) {
            std::printf("%-3d %p: [no symbol]\n", i, addrlist[i]);
            continue;
        }

		const char* demangled_name = nullptr;
		int status = -1;

		if (info.dli_sname) {
			demangled_name = abi::__cxa_demangle(info.dli_sname, nullptr, 0, &status);
			if (status == 0 && demangled_name) {
				std::printf("%-3d %p: %s (+%ld) [%s]\n", i, addrlist[i], demangled_name,
							(char*)addrlist[i] - (char*)info.dli_saddr, info.dli_fname);
				std::free((void*)demangled_name);
			}
		}

		if (status == 0 && demangled_name) {
			std::printf("%-3d %p: %s (+%ld) [%s]\n", i, addrlist[i], demangled_name,
						(char*)addrlist[i] - (char*)info.dli_saddr, info.dli_fname);
			std::free((void*)demangled_name);
		}
        else if (info.dli_sname) {
			std::printf("%-3d %p: %s (+%ld) [%s]\n", i, addrlist[i], info.dli_sname,
						(char*)addrlist[i] - (char*)info.dli_saddr, info.dli_fname);
		}
        else {
			std::printf("%-3d %p: ?? [%s]\n", i, addrlist[i], info.dli_fname);
		}

		// Get file and line information from addr2line
		const std::string &file_line = getFileLine(addrlist[i]);

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
