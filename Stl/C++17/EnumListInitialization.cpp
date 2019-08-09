/**
 * \file  main.cpp
 * \brief Direct List Initialization of Enums

 Enums can now be initialized using braced syntax.
 */


#include <StdStream.h>
#include <StdTest.h>
#include <Stl.h>

//-------------------------------------------------------------------------------------------------
int main(int, char **)
{
	enum byte : unsigned char {};
	byte b {0}; // OK
	byte c {-1}; // ERROR
	byte d = byte{1}; // OK
	byte e = byte{256}; // ERROR

    // std::cout << TRACE_VAR("") << std::endl;

    return EXIT_SUCCESS;
}
//-------------------------------------------------------------------------------------------------


#if OUTPUT



#endif
