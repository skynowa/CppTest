/**
 * \file  main.cpp
 * \brief Inline variables
 *
 * The inline specifier can be applied to variables as well as to functions.
 * A variable declared inline has the same semantics as a function declared inline.
 */


#include <StdStream.h>
#include <StdTest.h>
#include <Stl.h>

//-------------------------------------------------------------------------------------------------
// Disassembly example using compiler explorer.
struct S
{
	int x;
};
//-------------------------------------------------------------------------------------------------
// mov esi, dword ptr [x1]
// x1: .long 321
inline S x1 = S{321};
//-------------------------------------------------------------------------------------------------
int main(int, char **)
{
	// mov eax, dword ptr [.L_ZZ4mainE2x2]
	// mov dword ptr [rbp - 8], eax
	// .L_ZZ4mainE2x2: .long 123
	S x2 = S{123};

    std::cout << TRACE_VAR(x1.x) << std::endl;
    std::cout << TRACE_VAR(x2.x) << std::endl;

    return EXIT_SUCCESS;
}
//-------------------------------------------------------------------------------------------------


#if OUTPUT

x1.x: 321
x2.x: 123

#endif
