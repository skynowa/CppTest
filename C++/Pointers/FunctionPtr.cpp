/**
 * \file  FunctionPtr.cpp
 * \brief pointer to function
 *
 * \review
 *
 * https://isocpp.org/wiki/faq/pointers-to-members
 */


#include <StdStream/StdStream.h>
#include <StdTest/StdTest.h>
#include <Stl.h>
//--------------------------------------------------------------------------------------------------
int
func(const std::string &a_value)
{
    std::cout << "func: " << a_value << std::endl;
    return 0;
}

int (*funcPtr)(const std::string &) = nullptr;
//--------------------------------------------------------------------------------------------------
class A
{
public:
    int
    method(const std::string &a_value) const
    {
        std::cout << "method: " << a_value << std::endl;
        return 0;
    }
};

int (A::*methodPtr)(const std::string &) const = nullptr;
//--------------------------------------------------------------------------------------------------
int main(int, char **)
{
    // function - by name
    {
        (*func)("by name 1");
        func("by name 2");
    }

    // function - by pointer
    {
        ::funcPtr = &func;

        (*::funcPtr)("by pointer 1");
        ::funcPtr("by pointer 2");
    }

    // method - by name
    {
        A a;
        a.method("by name");
    }

    // method - by pointer
    {
        ::methodPtr = &A::method;

        A a;
        (a.*::methodPtr)("by pointer");
    }

    return EXIT_SUCCESS;
}
//--------------------------------------------------------------------------------------------------


#if OUTPUT

func: by name 1
func: by name 2
func: by pointer 1
func: by pointer 2
method: by name
method: by pointer

#endif
