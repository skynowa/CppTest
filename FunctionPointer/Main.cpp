 /*
 * \file  Main.cpp
 * \brief pointer to function
 */


//---------------------------------------------------------------------------
#include <string>
#include <iostream>
#include <assert.h>
//---------------------------------------------------------------------------
int (*g_piFunc)(const std::string &csVal) = NULL;

int 
iFunc(const std::string &csVal) {
   std::cout << csVal << std::endl;
   return 0;  
}
//---------------------------------------------------------------------------
class A;

int (A::*g_piClassFunc)(const std::string &csVal) = NULL;

class A {
    public:
        int 
        iClassFunc(const std::string &csVal) {
           std::cout << csVal << std::endl;
           return 0;  
        }
};
//---------------------------------------------------------------------------
int main(int iArgCount, char **paszArgs)
{
    // function pointer
    {
        g_piFunc = &iFunc;

        (*iFunc)("Test!!");
        iFunc("Test!!");   
  
        (*g_piFunc)("Test!!");
        g_piFunc("Test!!");  
    }

    // class member pointer
    {
        //A objA;

        g_piClassFunc = &A::iClassFunc;

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