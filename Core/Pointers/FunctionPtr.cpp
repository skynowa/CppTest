/**
 * \file  FunctionPtr.cpp
 * \brief pointer to function
 *
 * \review
 *
 * https://isocpp.org/wiki/faq/pointers-to-members
 */


#include <StdStream.h>
#include <StdTest.h>
#include <Stl.h>
//--------------------------------------------------------------------------------------------------
int (*funcPtr)(const std::string &value) = nullptr;

int
func(const std::string &a_value)
{
    std::cout << a_value << std::endl;
    return 0;
}
//--------------------------------------------------------------------------------------------------
class A;
int (A::*methodPtr)(const std::string &value) const = nullptr;

class A
{
public:
    int
    method(const std::string &a_value) const
    {
        std::cout << a_value << std::endl;

        return 0;
    }
};
//--------------------------------------------------------------------------------------------------
int main(int, char **)
{
    // function - by name
    {
        (*func)("function - by name 1");
        func("function - by name 2");

        std::cout << std::endl;
    }

    // function - by pointer
    {
        ::funcPtr = &func;

        (*::funcPtr)("function - by pointer 1");
        ::funcPtr("function - by pointer 2");

        std::cout << std::endl;
    }

    // method - by name
    {
        A a;
        a.method("method - by name");

        std::cout << std::endl;
    }

    // method - by pointer
    {
        ::methodPtr = &A::method;

        A a;
        (a.*::methodPtr)("method - by pointer");

        std::cout << std::endl;
    }

    return EXIT_SUCCESS;
}
//--------------------------------------------------------------------------------------------------


#if OUTPUT

function - by name 1
function - by name 2

function - by pointer 1
function - by pointer 2

method - by name

method - by pointer

#endif
