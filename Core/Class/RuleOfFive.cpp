/**
 * \file  RuleOfFive.cpp
 * \brief Rule of five
 */


#include <StdStream.h>
#include <StdTest.h>
#include <Stl.h>

#include "RuleOfFive.h"
//--------------------------------------------------------------------------------------------------
int main(int, char **)
{
	std::cout << std::endl;
	std::cout << "------------------------------" << std::endl;

	{
		std::cout << "Ctor {}:\n" << std::endl;

		RuleOfFive a{"a"};
	}
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

	{
		std::cout << "Ctor move:\n" << std::endl;

		RuleOfFive a("a");
		RuleOfFive b = std::move(a);
	}
	std::cout << "------------------------------" << std::endl;

	{
		std::cout << "Op copy:\n" << std::endl;

		RuleOfFive a("a");
		RuleOfFive b("b");

		b = a;
	}
	std::cout << "------------------------------" << std::endl;

	{
		std::cout << "Op move:\n" << std::endl;

		RuleOfFive a("a");
		RuleOfFive b("b");

		b = std::move(a);
	}
	std::cout << "------------------------------" << std::endl;

	return EXIT_SUCCESS;
}
//--------------------------------------------------------------------------------------------------


#if OUTPUT

------------------------------
Ctor {}:

RuleOfFive(const char *): a
~RuleOfFive(): nullptr
------------------------------
Ctor default:

RuleOfFive(): nullptr
~RuleOfFive(): nullptr
------------------------------
Ctor 1 param:

RuleOfFive(const char *): a
~RuleOfFive(): nullptr
------------------------------
Ctor copy:

RuleOfFive(const char *): b
RuleOfFive(const char *): b
RuleOfFive(const RuleOfFive &): b
~RuleOfFive(): nullptr
~RuleOfFive(): nullptr
------------------------------
Ctor move:

RuleOfFive(const char *): a
RuleOfFive(RuleOfFive &&a_other): a
~RuleOfFive(): nullptr
~RuleOfFive(): nullptr
------------------------------
Op copy:

RuleOfFive(const char *): a
RuleOfFive(const char *): b
RuleOfFive(const char *): a
RuleOfFive(const RuleOfFive &): a
operator = (RuleOfFive &&): a
~RuleOfFive(): nullptr
operator = (const RuleOfFive &): a
~RuleOfFive(): nullptr
~RuleOfFive(): nullptr
------------------------------
Op move:

RuleOfFive(const char *): a
RuleOfFive(const char *): b
operator = (RuleOfFive &&): a
~RuleOfFive(): nullptr
~RuleOfFive(): nullptr
------------------------------


#endif
