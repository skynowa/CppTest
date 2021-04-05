/**
 * \file  main.cpp
 * \brief UTF-8 Character Literals
 *
 * \todo
 *
 * A character literal that begins with u8 is a character literal of type char.
 * The value of a UTF-8 character literal is equal to its ISO 10646 code point value.
 */


#include <StdStream.h>
#include <StdTest.h>
#include <Stl.h>

//-------------------------------------------------------------------------------------------------
int main(int, char **)
{
	char x = u8'x';

    std::cout << TRACE_VAR(x) << std::endl;

    return EXIT_SUCCESS;
}
//-------------------------------------------------------------------------------------------------


#if OUTPUT



#endif
