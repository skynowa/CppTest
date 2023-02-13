/**
 * \file  Function2.cpp
 * \brief
 */


#include <StdStream/StdStream.h>
#include <StdTest/StdTest.h>
#include <Stl.h>
//--------------------------------------------------------------------------------------------------
class A
{
public:
     A() { std::cout << "A::A" << std::endl; }
    ~A() { std::cout << "A::~A" << std::endl; }
};
//-------------------------------------------------------------------------------------------------
class B :
	public A
{
public:
     B() { std::cout << "B::B" << std::endl; }
    ~B() { std::cout << "B::~B" << std::endl; }
};
//---------------------------------------------------------------------------
int main(int, char **)
{
	A *x = new A();
	B *y = new B();

	delete x;
	delete y;

    return EXIT_SUCCESS;
}
//--------------------------------------------------------------------------------------------------


#if OUTPUT

A::A
A::A
B::B
A::~A
B::~B
A::~A

#endif
