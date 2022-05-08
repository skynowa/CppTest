/**
 * \file  InlineFunction.cpp
 * \brief
 */


#include <StdStream/StdStream.h>
#include <StdTest/StdTest.h>
#include <Stl.h>
//--------------------------------------------------------------------------------------------------
class Operation
{
public:
    void get();
    void sum();
    void difference();
    void product();
    void division();

private:
    int   a, b, add, sub, mul;
    float div;
};
//-------------------------------------------------------------------------------------------------
inline void
Operation::get()
{
    // std::cout << "Enter first value:";
    a = 10;

    // std::cout << "Enter second value:";
    b = 20;
}
//-------------------------------------------------------------------------------------------------
inline void
Operation::sum()
{
    add = a + b;

    std::cout << __FUNCTION__ << ": " << add << "\n";
}
//-------------------------------------------------------------------------------------------------
inline void
Operation::difference()
{
    sub = a - b;

    std::cout << __FUNCTION__ << ": " << sub << "\n";
}
//-------------------------------------------------------------------------------------------------
inline void
Operation::product()
{
    mul = a * b;

    std::cout << __FUNCTION__ << ": " << mul << "\n";
}
//-------------------------------------------------------------------------------------------------
inline void
Operation::division()
{
    div = a / b;

    std::cout << __FUNCTION__ << ": "<< div <<"\n" ;
}
//-------------------------------------------------------------------------------------------------
int main(int, char **)
{
    Operation s;
    s.get();
    s.sum();
    s.difference();
    s.product();
    s.division();

    return EXIT_SUCCESS;
}
//--------------------------------------------------------------------------------------------------


#if OUTPUT

sum: 30
difference: -10
product: 200
division: 0

#endif
