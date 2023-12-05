/**
 * \file  Bool.cpp
 * \brief Conversion operator bool
 *
 * explicit help protect against unwanted conversion while assigning it
 *
 * \see   https://stackoverflow.com/questions/4600295/what-is-the-meaning-of-operator-bool-const
 *        https://www.modernescpp.com/index.php/c-core-guidelines-more-rules-to-overloading/
 */


#include <StdStream/StdStream.h>
#include <StdTest/StdTest.h>
#include <Stl.h>
//--------------------------------------------------------------------------------------------------
struct A
	/// Non-explicit conversion
{
	operator bool() const
	{
		return true;
	}
};
//-------------------------------------------------------------------------------------------------
struct B
	/// Explicit conversion
{
	explicit operator bool() const
	{
		return true;
	}
};
//--------------------------------------------------------------------------------------------------
int main(int, char **)
{
	// Non-explicit conversion
	{
		A a;

		if (a) {
			std::cout << "a: true" << std::endl; // OK: A::operator bool()
		}

		const bool res1 = a;                    // OK: copy-initialization selects A::operator bool()
		const bool res2 = static_cast<bool>(a); // OK: static_cast performs direct-initialization

		std::cout << STD_TRACE_VAR(res1) << std::endl;
		std::cout << STD_TRACE_VAR(res2) << std::endl;
		std::cout << STD_TRACE_VAR(!!res2) << std::endl;
		std::cout << std::endl;
	}

	// Explicit conversion
	{
		B b;

		if (b) {
			std::cout << "b: true" << std::endl; // OK: B::operator bool()
		}

		// const bool res1 = b;                 // error: copy-initialization does not consider B::operator bool()
		const bool res2 = static_cast<bool>(b); // OK: static_cast performs direct-initialization

		// std::cout << STD_TRACE_VAR(res1) << std::endl;
		std::cout << STD_TRACE_VAR(res2) << std::endl;
		std::cout << STD_TRACE_VAR(!!res2) << std::endl;
		std::cout << std::endl;
	}

	return EXIT_SUCCESS;
}
//--------------------------------------------------------------------------------------------------


#if OUTPUT

a: true
res1: 1
res2: 1
!!res2: 1

b: true
res2: 1
!!res2: 1

#endif
