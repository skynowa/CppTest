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
//--------------------------------------------------------------------------------------------------
struct Snitch
	/// Note: All methods have side effects
{
	Snitch()  { std::cout << "ctor" << std::endl; }
	~Snitch() { std::cout << "dtor" << std::endl; }

	Snitch(const Snitch&) { std::cout << "ctor copy" << std::endl; }
	Snitch(Snitch&&)      { std::cout << "ctor move" << std::endl; }

	Snitch& operator=(const Snitch&)
	{
		std::cout << "assignment copy" << std::endl;
		return *this;
	}

	Snitch& operator=(Snitch&&)
	{
		std::cout << "assignment move" << std::endl;
		return *this;
	}
};
//--------------------------------------------------------------------------------------------------
Snitch exampleRVO()
{
	return Snitch();
}
//--------------------------------------------------------------------------------------------------
Snitch ExampleRVO()
{
	return Snitch();
}
//--------------------------------------------------------------------------------------------------
Snitch exampleNRVO()
{
	Snitch snitch;
	return snitch;
}
//--------------------------------------------------------------------------------------------------
void exampleCopyElision(Snitch /* s */)
{
}
//--------------------------------------------------------------------------------------------------
int main(int, char **)
{
    // STD_TRACE_FUNC;

   /*
	* RVO - Return Value Optimization
	*
	* Means the compiler is allowed to avoid creating temporary objects for return values,
	* even if they have side effects.
	*/
	{
		std::cout << "\n::::: " << "RVO" << " :::::" << std::endl;

		Snitch snitch = exampleRVO();
	}

   /**
    * NRVO - Named Return Value Optimization
	*
	* Is when an object with a name is returned but is nevertheless not copied
	*/
	{
		std::cout << "\n::::: " << "NRVO" << " :::::" << std::endl;

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
		std::cout << "\n::::: " << "Copy Elision" << " :::::" << std::endl;

		::exampleCopyElision( Snitch() );
	}

	// When RVO doesn’t / can’t happen

    return EXIT_SUCCESS;
}
//--------------------------------------------------------------------------------------------------


#if OUTPUT

::::: RVO :::::
ctor
dtor

::::: NRVO :::::
ctor
dtor

::::: Copy Elision :::::
ctor
dtor

#endif
