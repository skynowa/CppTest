/**
 * \file  UniquePtrNull.cpp
 * \brief std::unique_ptr with nullptr
 */


#include <StdStream/StdStream.h>
#include <StdTest/StdTest.h>
#include <Stl.h>
//--------------------------------------------------------------------------------------------------
struct A
{
    std::string str;

    A() :
        str("test")
    {
    }

    void bar() const
    {
        STD_TRACE_FUNC;

        std::cout << STD_TRACE_VAR(str) << std::endl;
    }
};
//--------------------------------------------------------------------------------------------------
void func(const A &a)
{
    STD_TRACE_FUNC;

    std::cout << STD_TRACE_VAR(a.str) << std::endl;
}
//--------------------------------------------------------------------------------------------------
int main(int, char **)
{
    std::unique_ptr<A> ptr(new A);

    // Not nullptr
    {
        std::cout << "#1: " << STD_TRACE_VAR(ptr.get()) << std::endl;

        func(*ptr);
        ptr->bar();

        std::cout << "OK\n" << std::endl;
    }

    // Reset to nullptr
    {
        ptr.reset(nullptr);
        std::cout << "#2: " << STD_TRACE_VAR(ptr.get()) << std::endl;

        func(*ptr);
        ptr->bar();

        std::cout << "OK\n" << std::endl;
    }

    return EXIT_SUCCESS;
}
//--------------------------------------------------------------------------------------------------


#if OUTPUT

#1: ptr.get(): 0x564a3fa09e70
	::: func :::
a.str: test
	::: bar :::
str: test
OK

#2: ptr.get(): 0
	::: func :::
    ...[Segmentation fault (core dumped)]

#endif
