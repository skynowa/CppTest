/**
 * \file  Backtrace_libunwind.cpp
 * \brief Bactrace with libunwind
 *
 * \code{.console}
 *
 * \endcode
 *
 * \todo
 */


//--------------------------------------------------------------------------------------------------
#include <StdStream/StdStream.h>
#include <StdTest/StdTest.h>
//#include <Stl.h>

#include <cxxabi.h>
#include <dlfcn.h>

#define UNW_LOCAL_ONLY
#include <libunwind.h>
//--------------------------------------------------------------------------------------------------
void printStackTrace()
{
    unw_cursor_t cursor;
    unw_context_t context;

    // Initialize context and cursor
    unw_getcontext(&context);
    unw_init_local(&cursor, &context);

    // Iterate over the stack frames
    while (unw_step(&cursor) > 0) {
        unw_word_t ip, sp;
        char funcName[256];
        unw_word_t offset;

        // Get instruction pointer (IP) and stack pointer (SP)
        unw_get_reg(&cursor, UNW_REG_IP, &ip);
        unw_get_reg(&cursor, UNW_REG_SP, &sp);

        // Get function name
        if (unw_get_proc_name(&cursor, funcName, sizeof(funcName), &offset) == 0) {
            int status;
            char *demangledName = abi::__cxa_demangle(funcName, nullptr, nullptr, &status);
            std::cout << "Function: " << (status == 0 ? demangledName : funcName) << " (0x" << std::hex << ip << ")";

            // Use dladdr to get file name for the address
            Dl_info dlInfo;
            if (dladdr(reinterpret_cast<void*>(ip), &dlInfo)) {
                // Construct addr2line command
                std::string command = "addr2line -e " + std::string(dlInfo.dli_fname) + " " + std::to_string(ip);
                FILE *pipe = popen(command.c_str(), "r");
                if (pipe) {
                    char buffer[128];
                    if (fgets(buffer, sizeof(buffer), pipe) != nullptr) {
                        std::cout << " [" << buffer << "]";
                    }
                    pclose(pipe);
                }
            } else {
                std::cout << " [unknown source location]";
            }

            if (demangledName) free(demangledName);
            std::cout << "\n";
        } else {
            std::cout << "Unable to get function name (0x" << std::hex << ip << ")\n";
        }
    }
}
//--------------------------------------------------------------------------------------------------
void funcC()
{
    printStackTrace();
}
//--------------------------------------------------------------------------------------------------
void funcB()
{
    funcC();
}
//--------------------------------------------------------------------------------------------------
void funcA()
{
    funcB();
}
//--------------------------------------------------------------------------------------------------
int
main(int, char** argv)
{
    funcA();

    return 0;
}
//--------------------------------------------------------------------------------------------------
