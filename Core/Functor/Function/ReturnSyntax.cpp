/**
 * \file  ReturnSyntax.cpp
 * \brief
 */


#include <StdStream/StdStream.h>
#include <StdTest/StdTest.h>
#include <Stl.h>
//--------------------------------------------------------------------------------------------------
std::string
fooStr()
{
	return __FUNCTION__;
}
//--------------------------------------------------------------------------------------------------
auto
fooAuto() -> std::string
{
	return __FUNCTION__;
}
//--------------------------------------------------------------------------------------------------
int main(int, char **)
{
    std::cout << TRACE_VAR(fooStr()) << std::endl;
    std::cout << TRACE_VAR(fooAuto()) << std::endl;

    return EXIT_SUCCESS;
}
//--------------------------------------------------------------------------------------------------


#if OUTPUT

fooStr():  fooStr
fooAuto(): fooAuto

#endif
