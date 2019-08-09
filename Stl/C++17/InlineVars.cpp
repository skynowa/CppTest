/**
 * \file  main.cpp
 * \brief Inline variables

The inline specifier can be applied to variables as well as to functions. A variable declared inline has the same semantics as a function declared inline.
 */


#include <StdStream.h>
#include <StdTest.h>
#include <Stl.h>

//-------------------------------------------------------------------------------------------------
int main(int, char **)
{
	// Disassembly example using compiler explorer.
	struct S { int x; };
	inline S x1 = S{321}; // mov esi, dword ptr [x1]
						// x1: .long 321

	S x2 = S{123};        // mov eax, dword ptr [.L_ZZ4mainE2x2]
						// mov dword ptr [rbp - 8], eax
						// .L_ZZ4mainE2x2: .long 123

    // std::cout << TRACE_VAR("") << std::endl;

    return EXIT_SUCCESS;
}
//-------------------------------------------------------------------------------------------------


#if OUTPUT



#endif
