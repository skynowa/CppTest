 /*
 * \file  Hierarchy.cpp
 * \brief class hierarchy
 */


#include <StdStream/StdStream.h>
#include <StdTest/StdTest.h>
#include <Stl.h>
//---------------------------------------------------------------------------
class A1
{
public:
    A1() { std::cout << __FUNCTION__ << std::endl; }
};

class A2 :
    public A1
{
public:
    A2() { std::cout << __FUNCTION__ << std::endl; }
};

class A3 :
    public A2
{
public:
    A3() { std::cout << __FUNCTION__ << std::endl; }
};
//---------------------------------------------------------------------------
class C1
{
public:
    C1() { std::cout << __FUNCTION__ << std::endl; }
};
//---------------------------------------------------------------------------
class B1
{
public:
    B1() { std::cout << __FUNCTION__ << std::endl; }
};

class B2 :
    public B1,
    public C1
{
public:
    B2() { std::cout << __FUNCTION__ << std::endl; }
};

class B3 :
    public B2
{
public:
    B3() { std::cout << __FUNCTION__ << std::endl; }
};
//---------------------------------------------------------------------------
class Z :
    public A3,
    public B3
{
public:
    Z() { std::cout << __FUNCTION__ << std::endl; }
};
//---------------------------------------------------------------------------
int main(int, char **)
{
    {
        Z z;
    }

    return EXIT_SUCCESS;
}
//---------------------------------------------------------------------------


#if OUTPUT

A1::A1
A2::A2
A3::A3

B1::B1
C1::C1  // <- C1
B2::B2
B3::B3

Z::Z

#endif