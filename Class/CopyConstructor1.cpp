 /*
 * \file  main.cpp
 * \brief Copy constructor, operator =
 *
 * \todo
 */


//------------------------------------------------------------------------------
#include <string>
#include <iostream>
#include <assert.h>
//------------------------------------------------------------------------------
class B {

};
//------------------------------------------------------------------------------
class A {
public:
    // default constructor
    A() {
        std::cout << "\tA()" << std::endl;
    }

    // copy constructor
    A(const A &a_obj) {
        std::cout << "\tA(const A &a_obj)" << std::endl;
    }

    // overload constructor
    A(const B &b_obj) {
        std::cout << "\tA(const B &b_obj)" << std::endl;
    }

    // operator =
    A& operator= (const A &a_src) {
        std::cout << "\tA& operator= (const A &a_src)" << std::endl;

        return *this;
    }
};
//------------------------------------------------------------------------------
int main(int, char **)
{
    std::cout << "--------------------------------------\n"
              << "A a1: \n";

    A a1;       // default constructor A()


    std::cout << "--------------------------------------\n"
              << "A a2(a1): \n";
    A a2(a1);   // copy constructor A(a1)


    std::cout << "--------------------------------------\n"
              << "A a3 = a2: \n";
    A a3 = a2;  // copy constructor A(a2)


    std::cout << "--------------------------------------\n"
              << "A a4(b): \n";
    B b;
    A a4(b);    // overload constructor A(b)


    std::cout << "--------------------------------------\n"
              << "A a5 = b: \n";
    A a5 = b;   // overload constructor A(b)


    std::cout << "--------------------------------------\n"
              << "a1 = a5: \n";
    a1 = a5;    // operator=(const A&), �� ���� operator=(a5)


    std::cout << "--------------------------------------\n"
              << "a2 = b: \n";
    a2 = b;     // Step 1: ��������� ��������� ������ ������ � A
                //         � ������� ������������ ���� A(b),
                // Step 2: -> operator=(const A&) �� ���� operator=(A(b))


    std::cout << "---------------------------------------\n";

    return EXIT_SUCCESS;
}
//------------------------------------------------------------------------------


#if OUTPUT

--------------------------------------
A a1:
        A()
--------------------------------------
A a2(a1):
        A(const A &a_obj)
--------------------------------------
A a3 = a2:
        A(const A &a_obj)
--------------------------------------
A a4(b):
        A(const B &b_obj)
--------------------------------------
A a5 = b:
        A(const B &b_obj)
--------------------------------------
a1 = a5:
        A& operator= (const A &a_src)
--------------------------------------
a2 = b:
        A(const B &b_obj)
        A& operator= (const A &a_src)
---------------------------------------

#endif
