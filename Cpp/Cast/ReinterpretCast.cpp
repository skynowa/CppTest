/**
 * \file  ReinterpretCast.cpp
 * \brief
 */


#include <StdStream/StdStream.h>
#include <StdTest/StdTest.h>
#include <Stl.h>
//---------------------------------------------------------------------------
void
func(unsigned char [])
{
	std::cout << "void func(unsigned char []) << \n";
}
//---------------------------------------------------------------------------
int main()
{
	char *ptr {};

	::func(reinterpret_cast<unsigned char *>(ptr));

	return 0;
}
//---------------------------------------------------------------------------
