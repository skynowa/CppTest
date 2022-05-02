/**
 * \file  Sample1.cpp
 * \brief New standard attributes
 *
 * C++17 introduces three new attributes: [[fallthrough]], [[nodiscard]], [[maybe_unused]]
 */


#include <StdStream.h>
#include <StdTest.h>
#include <Stl.h>
//-------------------------------------------------------------------------------------------------
// Will warn if return of foo() is ignored
[[nodiscard]] int
foo()
{
	return 7;
}
//-------------------------------------------------------------------------------------------------
int main(int, char **)
{
	const int a {1};

	switch (a) {
	case 1:
		// Indicates that falling through on case 1 is intentional
		[[fallthrough]];
	case 2:
		// Indicates that b might be unused, such as on production builds
		[[maybe_unused]] int b = foo();
		STD_TEST(b > 0);
		break;
	}

    return EXIT_SUCCESS;
}
//-------------------------------------------------------------------------------------------------


#if OUTPUT

// no warnings

#endif
