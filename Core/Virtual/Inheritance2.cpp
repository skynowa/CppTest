/**
 * \file  Inheritance2.cpp
 * \brief Virtual inheritance
 */


#include <StdStream/StdStream.h>
#include <StdTest/StdTest.h>
#include <Stl.h>
//--------------------------------------------------------------------------------------------------
struct A
{
    A ()
    {
        STD_TRACE_FUNC;
    }

    virtual ~A()
    {
        STD_TRACE_FUNC;
    }
};
//--------------------------------------------------------------------------------------------------
struct B1 :
    virtual A
{
    B1()
    {
        STD_TRACE_FUNC;
    }
};

struct B2 :
    virtual A
{
    B2()
    {
        STD_TRACE_FUNC;
    }
};

struct B3 :
    virtual A
{
    B3()
    {
        STD_TRACE_FUNC;
    }
};
//--------------------------------------------------------------------------------------------------
struct C :
    virtual B1,
    virtual B2,
    virtual B3
{
public:
    C()
    {
        STD_TRACE_FUNC;
    }
};
//--------------------------------------------------------------------------------------------------
int main(int, char **)
{
    C c;

    return EXIT_SUCCESS;
}
//--------------------------------------------------------------------------------------------------


#if OUTPUT

A::A
B1::B1
B2::B2
B3::B3
C::C
A::~A

#endif