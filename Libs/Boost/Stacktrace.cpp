/**
 * \file  Stacktrace.cpp
 * \brief boost::stacktrace
 */


#include <StdStream/StdStream.h>
#include <StdTest/StdTest.h>
#include <Stl.h>

#if __has_include(<boost/version.hpp>)
	#include <boost/version.hpp>
#endif

#if defined(BOOST_VERSION)
	#define BOOST_STACKTRACE_USE_ADDR2LINE 1
	#include <boost/stacktrace.hpp>
#endif
//-------------------------------------------------------------------------------------------------
int main(int , char **)
{
#if defined(BOOST_VERSION)
    const auto &aRv = boost::stacktrace::stacktrace();

    std::cout << aRv.as_vector() << std::endl;
#else
	std::cout << "Boost - not instaled, skip" << std::endl;
#endif

    return EXIT_SUCCESS;
}
//-------------------------------------------------------------------------------------------------

#if OUTPUT


#endif
