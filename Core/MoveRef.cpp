/**
 * \file
 * \brief
 *
 * \todo
 */


#include <StdStream.h>
#include <StdTest.h>
#include <Stl.h>

//-------------------------------------------------------------------------------------------------
struct A
{
    std::string value;

    A() :
        value() {std::cout << "A()" << std::endl;}
    A(const std::string &a_value):
        value(a_value) {std::cout << "A(std::string a_value)" << std::endl; }

    A(const A &a) :
        value(a.value) {std::cout << "A(const A &)" << std::endl;}
    A(A &&a) :
        value(move(a.value)) {std::cout << "A(A &&)" << std::endl;}

    // A & operator = (const A &) {std::cout << "A & operator = (const A &)" << std::endl;}
    // A & operator = (A &&) {std::cout << "A & operator = (A &&)" << std::endl;}

    ~A() {std::cout << "~A()" << std::endl;}
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

    // std::cout << "std::vector: " << v[0].value << std::endl;
    std::cout << "\n***** Test *****" << std::endl;

    for (auto &&it : v) {
        auto test = move(it.value);

        // std::cout << test.value << std::endl;
        // std::cout << it.value << std::endl;
        std::cout << it.value << (it.value.empty() ? "<moved>" : it.value) << std::endl;
    }

    std::cout << TRACE_VAR(a1.value) << std::endl;

    // std::cout <<"size = " <<  v.size() << std::endl;
    // std::cout << v[0] << std::endl;
    // std::cout << v[1] << std::endl;
    // std::cout << v[2] << std::endl;

    return 0;
}
//-------------------------------------------------------------------------------------------------
