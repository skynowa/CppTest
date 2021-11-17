/**
 * \file  ReturnSyntax.cpp
 * \brief
 */


#include <StdStream.h>
#include <StdTest.h>
#include <Stl.h>
//--------------------------------------------------------------------------------------------------
std::string
fooStr()
{
	std::string sRv = __FUNCTION__;

	return sRv;
}
//--------------------------------------------------------------------------------------------------
auto
fooAuto() -> std::string
{
	std::string sRv = __FUNCTION__;

	return sRv;
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
