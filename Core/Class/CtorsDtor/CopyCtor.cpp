 /*
 * \file  CopyCtor.cpp
 * \brief Copy constructor
 */


#include <StdStream/StdStream.h>
#include <StdTest/StdTest.h>
#include <Stl.h>
//------------------------------------------------------------------------------
class A
{
public:
    A();

    void print() const;

private:
    int         _i {};
    std::string _s;
};
//------------------------------------------------------------------------------
A::A() :
    _i{- 1},
    _s{"str"}
{
}
//------------------------------------------------------------------------------
void A::print() const
{
    std::cout << STD_TRACE_VAR2(_i, _s) << std::endl;
}
//---------------------------------------------------------------------------
int main(int, char **)
{
    A a1;
    A a2 = a1;

    a1.print();
    a2.print();

    return EXIT_SUCCESS;
}
//---------------------------------------------------------------------------


#if OUTPUT

_i: -1, _s: str
_i: -1, _s: str

#endif
