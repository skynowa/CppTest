/**
 * \file  main.cpp
 * \brief Direct List Initialization of Enums
 *
 * Enums can now be initialized using braced syntax.
 */


#include <StdStream.h>
#include <StdTest.h>
#include <Stl.h>

//-------------------------------------------------------------------------------------------------
int main(int, char **)
{
	enum Byte : unsigned char
	{
	};

	Byte b {0}; // OK
	/// Byte c {-1}; // ERROR
	Byte d = Byte{1}; // OK
	///Byte e = Byte{256}; // ERROR

    // std::cout << TRACE_VAR("") << std::endl;

    return EXIT_SUCCESS;
}
//-------------------------------------------------------------------------------------------------


#if OUTPUT



#endif
