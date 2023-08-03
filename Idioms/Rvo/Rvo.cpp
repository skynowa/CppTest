/**
 * \file  main.cpp
 * \brief Return Value Optimization (RVO), Named RVO (NRVO) and Copy-Elision are in C++ since C++98
 *
 * \see   https://shaharmike.com/cpp/rvo/
 *
 * \note  Output (note that -fno-elide-constructors disables RVO in clang)
 *
 * Conclusion
 *
 * While we can’t count on RVO to always take place, it will in most cases.
 * For those cases where it doesn’t we always have Move Semantics,
 * As always, optimize for readability rather than performance when writing code,
 * unless you have a quantifiable reason.
 */


#include <StdStream/StdStream.h>
#include <StdTest/StdTest.h>
#include <Stl.h>

#define RULE_5_OPTION_LOG 1

#include <Idioms/RuleOf/Rule5.h>
//--------------------------------------------------------------------------------------------------
class Example
{
public:
	Example() = default;
	~Example() = default;

	Rule5 RVO()
	{
		return Rule5("value");
	}

	Rule5 NRVO()
	{
		Rule5 obj("value");
		return obj;
	}

	void copyElision(Rule5 a_obj)
	{
		STD_UNUSED(a_obj);
	}
};
//--------------------------------------------------------------------------------------------------
int main(int, char **)
{
	Example example;

   /**
	* RVO - Return Value Optimization
	*
	* Means the compiler is allowed to avoid creating temporary objects for return values,
	* even if they have side effects.
	*/
	{
		std::cout << STD_TITLE_VAR("RVO") << std::endl;

		Rule5 rv = example.RVO();
		STD_TEST(!rv.value().empty());
	}

	{
		std::cout << STD_TITLE_VAR("RVO by ref") << std::endl;

		const auto &rv = example.RVO().value();
		STD_TEST(!rv.empty());
	}

   /**
	* NRVO - Named Return Value Optimization
	*
	* Is when an object with a name is returned but is nevertheless not copied
	*/
	{
		std::cout << STD_TITLE_VAR("NRVO") << std::endl;

		Rule5 rv = example.NRVO();
		STD_TEST(!rv.value().empty());
	}

	{
		std::cout << STD_TITLE_VAR("NRVO by ref") << std::endl;

		const auto &rv = example.NRVO().value();
		STD_TEST(!rv.empty());
	}

   /**
	* Copy Elision
	*
	* RVO is part of a larger group of optimizations called copy-elision.
	* Essentials are the same, except copy-elision is not required to happen as part of
	* return statements
	*/
	{
		std::cout << STD_TITLE_VAR("Copy Elision") << std::endl;

		example.copyElision( Rule5() );
	}

	// When RVO doesn’t / can’t happen

	return EXIT_SUCCESS;
}
//--------------------------------------------------------------------------------------------------

#if OUTPUT

::::: RVO :::::
[Ctor] const std::string &
[Dtor]

::::: RVO by ref :::::
[Ctor] const std::string &
[Dtor]

::::: NRVO :::::
[Ctor] const std::string &
[Dtor]

::::: NRVO by ref :::::
[Ctor] const std::string &
[Dtor]

::::: Copy Elision :::::
[Ctor] Default
[Dtor]

#endif
