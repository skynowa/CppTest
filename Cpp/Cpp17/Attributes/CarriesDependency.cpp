/**
 * \file  CarriesDependency.cpp
 * \brief
 *
 * Indicates that dependency chain in release-consume std::memory_order propagates in and
 * out of the function, which allows the compiler to skip unnecessary memory fence instructions.
 *
 * \see std::kill_dependency https://en.cppreference.com/w/cpp/atomic/kill_dependency
 */


#include <StdStream/StdStream.h>
#include <StdTest/StdTest.h>
#include <Stl.h>
//-------------------------------------------------------------------------------------------------
int main(int, char **)
{
    return EXIT_SUCCESS;
}
//-------------------------------------------------------------------------------------------------


#if OUTPUT



#endif
