/**
 * \file  Stacktrace.cpp
 * \brief boost::stacktrace
 *
 * g++ -DBOOST_STACKTRACE_USE_ADDR2LINE  -ggdb -rdynamic Stacktrace.cpp -o bb -lboost_stacktrace_addr2line -ldl -O0 -fno-omit-frame-pointer -lboost_stacktrace_addr2line && ./bb
 */


#include <StdStream/StdStream.h>
#include <StdTest/StdTest.h>
// #include <Stl.h>

#if __has_include(<boost/version.hpp>)
	#include <boost/version.hpp>
#endif

#if (BOOST_VERSION > 0)
    // NOTE: BOOST_STACKTRACE_USE_ADDR2LINE - not working
	#define BOOST_STACKTRACE_USE_BACKTRACE 1
	#include <boost/stacktrace.hpp>
#endif
//-------------------------------------------------------------------------------------------------
int main(int , char **)
{
#if (BOOST_VERSION > 0)
    const auto &stackTrace = boost::stacktrace::stacktrace();

	for (const auto &it_frame : stackTrace.as_vector()) {
		std::cout <<
			STD_TRACE_VAR(it_frame.name()) << "\n"
			STD_TRACE_VAR(it_frame.address()) << "\n"
			STD_TRACE_VAR(it_frame.source_file()) << "\n"
			STD_TRACE_VAR(it_frame.source_line()) << std::endl;

		std::cout << STD_TRACE_VAR(it_frame) << '\n' << std::endl;
	} // for (vars)
#else
	std::cout << "Boost - not instaled, skip" << std::endl;
#endif

    return EXIT_SUCCESS;
}
//-------------------------------------------------------------------------------------------------

#if OUTPUT


#endif
