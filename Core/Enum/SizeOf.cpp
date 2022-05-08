 /*
 * \file  SizeOf.cpp
 * \brief enum size
 */


#include <StdStream/StdStream.h>
#include <StdTest/StdTest.h>
#include <Stl.h>
//-------------------------------------------------------------------------------------------------
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
//-------------------------------------------------------------------------------------------------
class B
{
};
//-------------------------------------------------------------------------------------------------
int main(int, char **)
{
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

sizeof(A::EChar): 1
sizeof(a.ch): 1

sizeof(A::ELongLong): 8
sizeof(a.ll): 8

sizeof(A): 16
sizeof(a): 16

sizeof(B): 1

#endif
