/**
 * \file  NoReturn.cpp
 * \brief Indicates that the function does not return
 *
 * This attribute applies to the name of the function being declared in function declarations only.
 * The behavior is undefined if the function with this attribute actually returns.
 *
 * The first declaration of the function must specify this attribute if any declaration specifies it.
 *  If a function is declared with [[noreturn]] in one translation unit, and the same function
 * is declared without [[noreturn]] in another translation unit, the program is ill-formed;
 * no diagnostic required.
 *
 * noreturn doesn't tell the compiler that the function doesn't return any value.
 * It tells the compiler that control flow will not return to the caller.
 * This allows the compiler to make a variety of optimizations -- it need not save and restore
 * any volatile state around the call, it can dead-code eliminate any code that would otherwise
 * follow the call, etc.
 */


#include <StdStream.h>
#include <StdTest.h>
#include <Stl.h>
//-------------------------------------------------------------------------------------------------
[[ noreturn ]] void
f()
{
	throw "error";

	// No warning
}
//-------------------------------------------------------------------------------------------------
void q [[ noreturn ]]
(int i)
{
	// behavior is undefined if called with an argument <= 0
	if (i > 0) {
		throw "positive";
	}

	// warning: ‘noreturn’ function does return
}
//-------------------------------------------------------------------------------------------------
// void h() [[noreturn]]; // error: attribute applied to function type of h, not h itself
//-------------------------------------------------------------------------------------------------
int main(int, char **)
{
    return EXIT_SUCCESS;
}
//-------------------------------------------------------------------------------------------------


#if OUTPUT



#endif
