/**
 * \file  main.cpp
 * \brief Nested namespaces
 *
 * Using the namespace resolution operator to create nested namespace definitions.
 */


#include <StdStream.h>
#include <StdTest.h>
#include <Stl.h>

//-------------------------------------------------------------------------------------------------
int main(int, char **)
{
	namespace A {
		namespace B {
			namespace C {
				int i;
			}
		}
	}

	// vs.
	namespace A::B::C {
		int i;
	}

    // std::cout << TRACE_VAR("") << std::endl;

    return EXIT_SUCCESS;
}
//-------------------------------------------------------------------------------------------------


#if OUTPUT



#endif
