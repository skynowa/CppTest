 /*
 * \file  Main.cpp
 * \brief pointer to function
 */


//---------------------------------------------------------------------------
#include <string>
#include <iostream>
#include <assert.h>
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
    int iClassFunc(const std::string &a_value)
    {
       std::cout << a_value << std::endl;
       return 0;
    }
};
//---------------------------------------------------------------------------
int main(int iArgCount, char **paszArgs)
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
        //A objA;

        ::classFuncPtr = &A::iClassFunc;

        //(*iFunc)("Test!!");
        //iFunc("Test!!");

        //(A::*g_piClassFunc)("Test!!");
        //A::g_piClassFunc("Test!!");
    }

    return EXIT_SUCCESS;
}
//---------------------------------------------------------------------------


#if OUTPUT



#endif
