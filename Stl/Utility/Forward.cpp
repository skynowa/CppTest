/**
 * \file  Forward.cpp
 * \brief
 *
 * \todo
 */


#include <StdTest/StdTest.h>
#include <Stl.h>
//-------------------------------------------------------------------------------------------------
// function with lvalue and rvalue reference overloads:
void overloaded (const int& ) {std::cout << "[lvalue]";}
void overloaded (int&& )      {std::cout << "[rvalue]";}
//-------------------------------------------------------------------------------------------------
// function template taking rvalue reference to deduced type:
template <class T> void
fn(T&& x)
{
    overloaded (x);                   // always an lvalue
    overloaded (std::forward<T>(x));  // rvalue if argument is rvalue
}
//-------------------------------------------------------------------------------------------------
int main(int, char **)
{
    int a;

    std::cout << "calling fn with lvalue: ";
    fn(a);
    std::cout << '\n';

    std::cout << "calling fn with rvalue: ";
    fn(0);
    std::cout << '\n';

    return 0;
}
//-------------------------------------------------------------------------------------------------

#if OUTPUT

calling fn with lvalue: [lvalue][lvalue]
calling fn with rvalue: [lvalue][rvalue]

#endif
