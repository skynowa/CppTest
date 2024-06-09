/**
 * \file  InitCtor2.cpp
 * \brief
 */


#include <StdStream/StdStream.h>
#include <StdTest/StdTest.h>
#include <Stl.h>
//-------------------------------------------------------------------------------------------------
class DataWithCtorDefault
{
public:
    int a;
    int b {-1};
    int c {3};

    DataWithCtorDefault() = default;

    void print() const
    {
        std::cout << STD_TRACE_VAR3(a, b, c) << std::endl;
    }
};
//-------------------------------------------------------------------------------------------------
class DataWithCtor
{
public:
    int a;
    int b {-1};
    int c {3};

    DataWithCtor()
    {
    }

    void print() const
    {
        std::cout << STD_TRACE_VAR3(a, b, c) << std::endl;
    }
};
//-------------------------------------------------------------------------------------------------
class DataWitoutCtor
{
public:
    int a;
    int b {-1};
    int c {3};

    void print() const
    {
        std::cout << STD_TRACE_VAR3(a, b, c) << std::endl;
    }
};
//-------------------------------------------------------------------------------------------------
int main(int, char **)
{
    {
        std::cout << "Ctor default - yes" << std::endl;

        DataWithCtorDefault data1;
        data1.print();

        DataWithCtorDefault data2 {};
        data2.print();
    }

    {
        std::cout << "\nCtor - yes" << std::endl;

        DataWithCtor data1;
        data1.print();

        DataWithCtor data2 {};
        data2.print();
    }

    {
        std::cout << "\nCtor - no" << std::endl;

        DataWitoutCtor data1;
        data1.print();

        DataWitoutCtor data2 {};
        data2.print();
    }

    return EXIT_SUCCESS;
}
//-------------------------------------------------------------------------------------------------


#if OUTPUT

Ctor default - yes
a: 32764, b: -1, c: 3
a: 0, b: -1, c: 3

Ctor - yes
a: 0, b: -1, c: 3
a: -910941464, b: -1, c: 3

Ctor - no
a: 1819242352, b: -1, c: 3
a: 0, b: -1, c: 3

#endif
