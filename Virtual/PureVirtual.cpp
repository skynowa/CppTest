 /*
 * \file  Main.cpp
 * \brief 
 */


//---------------------------------------------------------------------------
#include <string>
#include <iostream>
#include <assert.h>
//---------------------------------------------------------------------------
class A {
    public:
        void bar() { 
            foo(); 
        }

    private: /* or public */
        virtual void foo() { 
            std::cout << __FUNCTION__ << std::endl; 
        }
};
//---------------------------------------------------------------------------
class B: 
    public A 
{
    private: /* or public */
        virtual void foo() { 
            std::cout << __FUNCTION__ << std::endl; 
        }
};
//---------------------------------------------------------------------------
int main(int, char **)
{
    A *a = new B();
    a->bar();

    delete a;

    // std::cout << "" << std::endl;

    return EXIT_SUCCESS;
}
//---------------------------------------------------------------------------


#if OUTPUT

 B::foo

#endif