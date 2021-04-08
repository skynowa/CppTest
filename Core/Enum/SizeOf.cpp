 /*
 * \file  main.cpp
 * \brief enum size
 *
 * \todo
 */


#include <string>
#include <iostream>
#include <assert.h>

//-------------------------------------------------------------------------------------------------
#define TRACE_VAR(v) \
    #v ": " << (v)
//-------------------------------------------------------------------------------------------------
int main(int, char **)
{
    class A
    {
    public:
        enum class EChar : char
        {
            chUNKNOWN,
            chONE,
            chTWO,
            chTHREE
        };

        enum class ELongLong : long long
        {
            llUNKNOWN,
            llONE,
            llTWO,
            llTHREE
        };

        const A::EChar     ch = A::EChar::chONE;
        const A::ELongLong ll = A::ELongLong::llONE;
    };

    class B
    {
    };

    A a;
    B b;

    std::cout
        << TRACE_VAR(sizeof(A::EChar))     << "\n"
        << TRACE_VAR(sizeof(a.ch))         << "\n"
        << "\n"
        << TRACE_VAR(sizeof(A::ELongLong)) << "\n"
        << TRACE_VAR(sizeof(a.ll))         << "\n"
        << "\n"
        << TRACE_VAR(sizeof(A))            << "\n"
        << TRACE_VAR(sizeof(a))            << "\n"
        << "\n"
        << TRACE_VAR(sizeof(B))            << "\n"
        << TRACE_VAR(sizeof(b))            << "\n";

    return 0;
}
//-------------------------------------------------------------------------------------------------


#if OUTPUT

EChar: 1
ch: 1

ELongLong: 8
ll: 8

#endif
