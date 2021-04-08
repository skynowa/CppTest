 /*
 * \file  Main.cpp
 * \brief pointer to function
 *
 * \todo "std::func_ptr"
 *
 * https://isocpp.org/wiki/faq/pointers-to-members
 */


#include <StdTest.h>

//---------------------------------------------------------------------------
int (*funcPtr)(const std::string &value) = NULL;

int iFunc(const std::string &a_value)
{
   std::cout << a_value << std::endl;
   return 0;
}
//---------------------------------------------------------------------------
class A;

int (A::*classFuncPtr)(const std::string &value) = NULL;

class A
{
public:
    int classFunc(const std::string &a_value)
    {
       std::cout << a_value << std::endl;
       return 0;
    }
};
//---------------------------------------------------------------------------
int main(int, char **)
{
    // function pointer
    {
        ::funcPtr = &iFunc;

        (*iFunc)("Test!!");
        iFunc("Test!!");

        (*::funcPtr)("Test!!");
        ::funcPtr("Test!!");
    }

    // class member pointer
    {
        A objA;

        ::classFuncPtr = &A::classFunc;

        (*iFunc)("Test!!");
        iFunc("Test!!");

        // (A::*classFuncPtr)("Test!!");
        // A::g_classFunc("Test!!");
    }

    return EXIT_SUCCESS;
}
//---------------------------------------------------------------------------


#if OUTPUT

Test!!
Test!!
Test!!
Test!!

#endif
