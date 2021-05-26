/*
 * \file  ThrowDerived.cpp
 * \brief
 */


#include <StdStream.h>
#include <StdTest.h>
#include <Stl.h>
//---------------------------------------------------------------------------
class A
{
public:
             A() { std::cout << "A::A()\n"; }
    virtual ~A() {}

    virtual void foo() const
    {
        std::cout << "A::foo()\n";
    }
};
//---------------------------------------------------------------------------
class B :
    public A
    // protected A
    // private   A
{
public:
    B()
    {
        std::cout << "B::B()\n";
    }

    void foo() const override
    {
        std::cout << "B::foo()\n";
    }
};
//---------------------------------------------------------------------------
int main()
{
    try {
        throw B();
    }
    catch (const B &ex) {
        std::cout << "catch (B &ex)\n";
        ex.foo();
    }
    catch (const A &ex) {
        std::cout << "catch (A &ex)\n";
        ex.foo();
    }

    return EXIT_SUCCESS;
}
//---------------------------------------------------------------------------


#if OUTPUT

A::A()
B::B()
catch (B &ex)
B::foo()

#endif