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
#define RULEOF5_OPTION_COPY 1
#define RULEOF5_OPTION_MOVE 1

#include <Idioms/RuleOf5.h>
//--------------------------------------------------------------------------------------------------
RuleOf5 exampleRVO()
{
	return RuleOf5();
}
//--------------------------------------------------------------------------------------------------
RuleOf5 exampleNRVO()
{
	RuleOf5 snitch;
	return snitch;
}
//--------------------------------------------------------------------------------------------------
void exampleCopyElision(RuleOf5 /* obj */)
{
}
//--------------------------------------------------------------------------------------------------
int main(int, char **)
{
   /*
	* RVO - Return Value Optimization
	*
	* Means the compiler is allowed to avoid creating temporary objects for return values,
	* even if they have side effects.
	*/
	{
		std::cout << "::::: " << "RVO" << " :::::" << std::endl;

		RuleOf5 snitch = exampleRVO();
	}

   /**
    * NRVO - Named Return Value Optimization
	*
	* Is when an object with a name is returned but is nevertheless not copied
	*/
	{
		std::cout << "::::: " << "NRVO" << " :::::" << std::endl;

		exampleNRVO();
	}

   /**
	* Copy Elision
	*
	* RVO is part of a larger group of optimizations called copy-elision.
	* Essentials are the same, except copy-elision is not required to happen as part of
	* return statements
	*/
	{
		std::cout << "::::: " << "Copy Elision" << " :::::" << std::endl;

		::exampleCopyElision( RuleOf5() );
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
