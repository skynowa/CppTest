/**
 * \file  main_Var1.cpp
 * \brief
 */


#include "header.h"
#include "module.h"
//--------------------------------------------------------------------------------------------------
int main(int, char **)
{
	{
		::foo();

		Test test;
	}

    return EXIT_SUCCESS;
}
//--------------------------------------------------------------------------------------------------


#if OUTPUT

	::: Init :::
	::: ~Init :::

#endif
