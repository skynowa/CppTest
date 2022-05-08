/**
 * \file  PureVirtual.cpp
 * \brief
 */


#include <StdStream/StdStream.h>
#include <StdTest/StdTest.h>
#include <Stl.h>
//--------------------------------------------------------------------------------------------------
class A
{
public:
    virtual ~A() = default;

    void bar()
    {
        foo();
    }

private: /* or public */
    virtual void foo()
    {
        std::cout << __FUNCTION__ << std::endl;
    }
};
//---------------------------------------------------------------------------
class B:
    public A
{
private: /* or public */
    virtual void foo()
    {
        std::cout << __FUNCTION__ << std::endl;
    }
};
//---------------------------------------------------------------------------
int main(int, char **)
{
    A *a = new B();
    a->bar();

    delete a;

    // std::cout << "" << std::endl;

    return EXIT_SUCCESS;
}
//---------------------------------------------------------------------------


#if OUTPUT

B::foo

#endif