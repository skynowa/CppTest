/*
* \file  Main.cpp
* \brief
*/


//---------------------------------------------------------------------------
#include <string>
#include <iostream>
#include <assert.h>
#include <exception>
//---------------------------------------------------------------------------
class A {
    public:
                     A()   { std::cout << "A::A()\n"; }
        virtual void Foo() { std::cout << "A::Foo()\n"; }
};
//---------------------------------------------------------------------------
class B : 
    public    A
    // protected A
    // private   A
{
    public:
                     B()   { std::cout << "B::B()\n"; }
        virtual void Foo() { std::cout << "B::Foo()\n"; }
};
//---------------------------------------------------------------------------
int main() {
    try {
        throw B();
    }
    catch (A &ex) {
        std::cout << "catch (A &ex)\n";
        ex.Foo();
    }
    catch (B &ex) {
        std::cout << "catch (B &ex)\n";
        ex.Foo();
    }

    return EXIT_SUCCESS;
}
//---------------------------------------------------------------------------


#if OUTPUT

    // class B : public A
    A::A()
    B::B()
    catch (A &ex)
    B::Foo()

    // class B : protected or private A
    A::A()
    B::B()
    catch (B &ex)
    B::Foo()

#endif