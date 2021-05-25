/**
 * \file  RuleOfFive.cpp
 * \brief Rule of five
 */


#include <StdStream.h>
#include <StdTest.h>
#include <Stl.h>

#include "Core/Class/RuleOfFive.h"
//--------------------------------------------------------------------------------------------------
int main(int, char **)
{
	std::cout << std::endl;
	std::cout << "------------------------------" << std::endl;

	{
		std::cout << "Ctor default:\n" << std::endl;

		RuleOfFive a;
	}
	std::cout << "------------------------------" << std::endl;

	{
		std::cout << "Ctor 1 param:\n" << std::endl;

		RuleOfFive a("a");
	}
	std::cout << "------------------------------" << std::endl;

	{
		std::cout << "Ctor copy:\n" << std::endl;

		RuleOfFive b("b");

		RuleOfFive a = b;
	}
	std::cout << "------------------------------" << std::endl;

	return EXIT_SUCCESS;
}
//--------------------------------------------------------------------------------------------------


#if OUTPUT



#endif
