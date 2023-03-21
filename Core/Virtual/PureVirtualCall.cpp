/**
 * \file  PureVirtualCall.cpp
 * \brief
 *
 * \see   https://www.youtube.com/watch?v=7g8HufwNa0g&t=974s
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

        test();
    }

    virtual ~A()
    {
        STD_TRACE_FUNC;
    }

    void test() const
    {
        STD_TRACE_FUNC;

        foo();  // <-- pure virtual method called
    }

    virtual void foo() const = 0;
};
//--------------------------------------------------------------------------------------------------
struct B :
    A
{
    void foo() const override
    {
        STD_TRACE_FUNC;
    }
};
//--------------------------------------------------------------------------------------------------
int main(int, char **)
{
    try {
        B b;
    }
    catch (const std::exception &a_ex) {
        std::cout << STD_TRACE_VAR(a_ex.what()) << std::endl;
    }
    catch (...) {
        std::cout << "exception - unknown" << std::endl;
    }

    return EXIT_SUCCESS;
}
//--------------------------------------------------------------------------------------------------


#if OUTPUT

	::: A :::
	::: test :::

pure virtual method called
terminate called without an active exception

#endif
