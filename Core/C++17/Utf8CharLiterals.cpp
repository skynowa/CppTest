/**
 * \file  Utf8CharLiterals.cpp
 * \brief UTF-8 Character Literals
 *
 * A character literal that begins with u8 is a character literal of type char.
 * The value of a UTF-8 character literal is equal to its ISO 10646 code point value.
 */


#include <StdStream/StdStream.h>
#include <StdTest/StdTest.h>
#include <Stl.h>
//-------------------------------------------------------------------------------------------------
int main(int, char **)
{
	const char x {u8'x'};

    std::cout << TRACE_VAR2(x, sizeof(x)) << std::endl;

    return EXIT_SUCCESS;
}
//-------------------------------------------------------------------------------------------------


#if OUTPUT

x: x, sizeof(x): 1

#endif
