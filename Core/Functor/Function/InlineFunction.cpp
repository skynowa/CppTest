/**
 * \file  InlineFunction.cpp
 * \brief
 */


#include <StdStream.h>
#include <StdTest.h>
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

    std::cout << "Addition of two numbers: " << add << "\n";
}
//-------------------------------------------------------------------------------------------------
inline void
Operation::difference()
{
    sub = a - b;

    std::cout << "Difference of two numbers: " << sub << "\n";
}
//-------------------------------------------------------------------------------------------------
inline void
Operation::product()
{
    mul = a * b;

    std::cout << "Product of two numbers: " << mul << "\n";
}
//-------------------------------------------------------------------------------------------------
inline void
Operation::division()
{
    div = a / b;

    std::cout<<"Division of two numbers: "<< div <<"\n" ;
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

Addition of two numbers: 30
Difference of two numbers: -10
Product of two numbers: 200
Division of two numbers: 0

#endif
