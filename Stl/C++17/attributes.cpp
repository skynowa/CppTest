/**
 * \file  main.cpp
 * \brief New standard attributes

C++17 introduces three new attributes: [[fallthrough]], [[nodiscard]] and [[maybe_unused]]
 */


#include <StdStream.h>
#include <StdTest.h>
#include <Stl.h>

//-------------------------------------------------------------------------------------------------
int main(int, char **)
{
	// Will warn if return of foo() is ignored
	[[nodiscard]] int foo();
	int main() {
	int a {1};
	switch (a) {
		// Indicates that falling through on case 1 is intentional
		case 1: [[fallthrough]]
		case 2:
		// Indicates that b might be unused, such as on production builds
			[[maybe_unused]] int b = foo();
			assert(b > 0);
			break;
	}
	}

    // std::cout << TRACE_VAR("") << std::endl;

    return EXIT_SUCCESS;
}
//-------------------------------------------------------------------------------------------------


#if OUTPUT



#endif
