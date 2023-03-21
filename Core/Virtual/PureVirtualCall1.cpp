/**
 * \file  PureVirtualCall1.cpp
 * \brief WITHOUT PVC exception
 */


#include <StdStream/StdStream.h>
#include <StdTest/StdTest.h>
#include <Stl.h>
//--------------------------------------------------------------------------------------------------
struct A
{
    A()
    {
        STD_TRACE_FUNC;
    }

    virtual ~A()
    {
        STD_TRACE_FUNC;
    }

    void test() const
    {
        STD_TRACE_FUNC;

        foo();
    }

    virtual void foo() const
    {
        std::cout << '\t' << "A::foo()" << std::endl;
    }
};
//---------------------------------------------------------------------------
struct B:
    A
{
    void foo() const final
    {
        std::cout << '\t' << "B::foo()" << std::endl;
    }
};
//---------------------------------------------------------------------------
int main(int, char **)
{
    A *a = new B();
    a->test();

    delete a;

    return EXIT_SUCCESS;
}
//---------------------------------------------------------------------------


#if OUTPUT

	::: A :::
	::: test :::
	B::foo()
	::: ~A :::

#endif