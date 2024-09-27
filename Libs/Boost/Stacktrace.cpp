/**
 * \file  Stacktrace.cpp
 * \brief boost::stacktrace
 *
 * g++ -DBOOST_STACKTRACE_USE_ADDR2LINE  -ggdb -rdynamic Stacktrace.cpp -o bb -lboost_stacktrace_addr2line -ldl -O0 -fno-omit-frame-pointer -lboost_stacktrace_addr2line && ./bb
 */


#include <StdStream/StdStream.h>
#include <StdTest/StdTest.h>
#include <Stl.h>

#if __has_include(<boost/version.hpp>)
	#include <boost/version.hpp>
#endif

#if 1 || (BOOST_VERSION > 0)
	// NOTE: BOOST_STACKTRACE_USE_ADDR2LINE - not working
	#define BOOST_STACKTRACE_USE_BACKTRACE 1
	#include <boost/stacktrace.hpp>
#endif
//-------------------------------------------------------------------------------------------------
std::string
executableName(
	const boost::stacktrace::frame &a_frame
)
{
	// The first frame usually represents the main function or entry point
	if ( a_frame.empty() ) {
		return "Unknown executable";  // Fallback if unable to determine
	}

	const auto addr = a_frame.address();
	if (addr == nullptr) {
		return {};
	}

	Dl_info info {};
	if (::dladdr(addr, &info) == 0) {
		return {};
	}

	if (info.dli_fname == nullptr) {
		return {};
	}

	return info.dli_fname;
}
//-------------------------------------------------------------------------------------------------
int main(int , char **)
{
#if 1 || (BOOST_VERSION > 0)
	const auto &stackTrace = boost::stacktrace::stacktrace();

	for (const auto &it_frame : stackTrace.as_vector()) {
		std::cout << "------------------------------" << std::endl;

		if (0) {
			std::cout << STD_TRACE_VAR(it_frame) << '\n' << std::endl;
		} else {
			std::cout
				<< "module: " << ::executableName(it_frame) << "\n"
				<< "\n"
				<< STD_TRACE_VAR(it_frame.name()) << "\n"
				<< STD_TRACE_VAR(it_frame.address()) << "\n"
				<< STD_TRACE_VAR(it_frame.source_file()) << "\n"
				<< STD_TRACE_VAR(it_frame.source_line()) << std::endl;
		}
	}
#else
	std::cout << "Boost - not instaled, skip" << std::endl;
#endif

	return EXIT_SUCCESS;
}
//-------------------------------------------------------------------------------------------------

#if OUTPUT


#endif
