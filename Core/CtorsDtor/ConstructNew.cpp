/**
 * \file  ConstructNew.cpp
 * \brief Ctor with operator new
 */


#include <StdStream/StdStream.h>
#include <StdTest/StdTest.h>
#include <Stl.h>
//-------------------------------------------------------------------------------------------------
class A
{
public:
	A()
	{
		std::cout << __FUNCTION__ << std::endl;
	}

	~A()
	{
		std::cout << __FUNCTION__ << std::endl << std::endl;
	}
};
//-------------------------------------------------------------------------------------------------
int main(int, char **)
{
	{
		A a;
	}

	{
		A *a = new A;
		delete a;
	}

	{
		A *a = new A();
		delete a;
	}

    return EXIT_SUCCESS;
}
//-------------------------------------------------------------------------------------------------


#if OUTPUT

A
~A

A
~A

A
~A

#endif
