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

#define RULEOF5_OPTION_LOG 1

#include <Idioms/Rule5.h>
//--------------------------------------------------------------------------------------------------
class Example
{
public:
	Example() = default;
	~Example() = default;

	Rule5 RVO()
	{
		return Rule5();
	}

	Rule5 NRVO()
	{
		Rule5 obj;
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

   /*
	* RVO - Return Value Optimization
	*
	* Means the compiler is allowed to avoid creating temporary objects for return values,
	* even if they have side effects.
	*/
	{
		std::cout << STD_TITLE_VAR("RVO") << std::endl;

		Rule5 snitch = example.RVO();
	}

   /**
    * NRVO - Named Return Value Optimization
	*
	* Is when an object with a name is returned but is nevertheless not copied
	*/
	{
		std::cout << STD_TITLE_VAR("NRVO") << std::endl;

		example.NRVO();
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
[Ctor] Default
[Dtor]

::::: NRVO :::::
[Ctor] Default
[Dtor]

::::: Copy Elision :::::
[Ctor] Default
[Dtor]

#endif
