/**
 * \file  main.cpp
 * \brief std::byte
 *
 * The new std::byte type provides a standard way of representing data as a byte.
 * Benefits of using std::byte over char or unsigned char is that it is not a character type,
 * and is also not an arithmetic type; while the only operator overloads available
 * are bitwise operations.
 *
 * Note that std::byte is simply an enum, and braced initialization of enums become possible
 * thanks to direct-list-initialization of enums.
 */


#include <StdStream.h>
#include <StdTest.h>
#include <Stl.h>

//-------------------------------------------------------------------------------------------------
int main(int, char **)
{
	std::byte a {0};
	std::byte b {0xFF};

	int i = std::to_integer<int>(b); // 0xFF

	std::byte c = a & b;

	int j = std::to_integer<int>(c); // 0

    // std::cout << TRACE_VAR("") << std::endl;

    return EXIT_SUCCESS;
}
//-------------------------------------------------------------------------------------------------


#if OUTPUT



#endif
