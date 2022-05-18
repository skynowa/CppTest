/**
 * \file  MoveRef.cpp
 * \brief
 *
 * [review]
 */


#include <StdStream/StdStream.h>
#include <StdTest/StdTest.h>
#include <Stl.h>
//-------------------------------------------------------------------------------------------------
class A
{
public:
    A() :
        _value()
    {
        std::cout << "A()" << std::endl;
    }

    explicit A(const std::string &a_value):
        _value(a_value)
    {
        std::cout << "A(std::string a_value)" << std::endl;
    }

    A(const A &a) :
        _value(a._value)
    {
        std::cout << "A(const A &)" << std::endl;
    }

    explicit A(A &&a) :
        _value(move(a._value))
    {
        std::cout << "A(A &&)" << std::endl;
    }

    // A & operator = (const A &) {std::cout << "A & operator = (const A &)" << std::endl;}
    // A & operator = (A &&) {std::cout << "A & operator = (A &&)" << std::endl;}

    ~A()
    {
        std::cout << "~A()" << std::endl;
    }

public:
    std::string _value;
};
//-------------------------------------------------------------------------------------------------
int main(int, char **)
{
    const A a1("STRING");
    // const A a2("2");
    // const A a3("3");
    // std::cout << "initialize" << std::endl;

    // std::vector<A> v;// {a1, a2, a3};
    std::vector<A> v;// {{a1}, {a2}, {a3}};

    // std::cout << "size = " << v.size() << std::endl;

    v.push_back(a1);
    // v.push_back(a2);
    // v.push_back(a3);

    // std::cout << "std::vector: " << v[0]._value << std::endl;
    std::cout << "\n***** Test *****" << std::endl;

    for (auto &&it : v) {
        auto test = move(it._value);

        // std::cout << test._value << std::endl;
        // std::cout << it._value << std::endl;
        std::cout << it._value << (it._value.empty() ? "<moved>" : it._value) << std::endl;
    }

    std::cout << STD_TRACE_VAR(a1._value) << std::endl;

    // std::cout <<"size = " <<  v.size() << std::endl;
    // std::cout << v[0] << std::endl;
    // std::cout << v[1] << std::endl;
    // std::cout << v[2] << std::endl;

    return EXIT_SUCCESS;
}
//-------------------------------------------------------------------------------------------------

#if OUTPUT

A(std::string a_value)
A(const A &)

***** Test *****
<moved>
a1._value: STRING
~A()
~A()


#endif
