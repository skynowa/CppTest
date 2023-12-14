/**
 * \file  InlineVars.cpp
 * \brief Inline variables
 *
 * The inline specifier can be applied to variables as well as to functions.
 * A variable declared inline has the same semantics as a function declared inline.
 */


#include <StdStream/StdStream.h>
#include <StdTest/StdTest.h>
#include <Stl.h>
//-------------------------------------------------------------------------------------------------
// Disassembly example using compiler explorer.
struct S
{
	int x;
};
//-------------------------------------------------------------------------------------------------
// mov esi, dword ptr [s1]
// s1: .long 321
inline S s1 = S{321};
//-------------------------------------------------------------------------------------------------
int main(int, char **)
{
    std::cout << STD_TRACE_VAR(s1.x) << std::endl;

	// mov eax, dword ptr [.L_ZZ4mainE2x2]
	// mov dword ptr [rbp - 8], eax
	// .L_ZZ4mainE2x2: .long 123
	S s2 = S{123};
    std::cout << STD_TRACE_VAR(s2.x) << std::endl;

    return EXIT_SUCCESS;
}
//-------------------------------------------------------------------------------------------------


#if OUTPUT

s1.x: 321
s2.x: 123

#endif
