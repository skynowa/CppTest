/**
 * \file  EnumListInitialization.cpp
 * \brief Direct List Initialization of Enums
 *
 * Enums can now be initialized using braced syntax.
 */


#include <StdStream/StdStream.h>
#include <StdTest/StdTest.h>
#include <Stl.h>
//-------------------------------------------------------------------------------------------------
int main(int, char **)
{
	enum Byte : unsigned char
	{
	};

	Byte b {0};             // OK
	std::cout << TRACE_VAR(b) << std::endl;

	/// Byte c {-1};        // ERROR

	Byte d = Byte{1};       // OK
	std::cout << TRACE_VAR(d) << std::endl;

	/// Byte e = Byte{256}; // ERROR

    return EXIT_SUCCESS;
}
//-------------------------------------------------------------------------------------------------


#if OUTPUT

b: 0
d: 1

#endif
