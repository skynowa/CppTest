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
        << STD_TRACE_VAR(sizeof(A::EChar))     << "\n"
        << STD_TRACE_VAR(sizeof(a.ch))         << "\n"
        << "\n"
        << STD_TRACE_VAR(sizeof(A::ELongLong)) << "\n"
        << STD_TRACE_VAR(sizeof(a.ll))         << "\n"
        << "\n"
        << STD_TRACE_VAR(sizeof(A))            << "\n"
        << STD_TRACE_VAR(sizeof(a))            << "\n"
        << "\n"
        << STD_TRACE_VAR(sizeof(B))            << "\n"
        << STD_TRACE_VAR(sizeof(b))            << "\n";

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
