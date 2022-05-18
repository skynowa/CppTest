/**
 * \file  main_Var2.cpp
 * \brief
 */


#include <StdStream/StdStream.h>
#include <StdTest/StdTest.h>
#include <Stl.h>

#include "CxVars.h"
#include "module.h"
//--------------------------------------------------------------------------------------------------
int main(int, char **)
{
	::foo();

	std::cout << __FUNCTION__ << ": " << STD_TRACE_VAR(CxVars::var.value) << std::endl;

    return EXIT_SUCCESS;
}
//--------------------------------------------------------------------------------------------------


#if OUTPUT

	::: Var :::
foo:  CxVars::var.value: aaa
main: CxVars::var.value: aaa
	::: ~Var :::

#endif
