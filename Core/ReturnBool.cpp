/**
 * \file  ReturnBool.cpp
 * \brief
 */


#include <StdTest.h>
#include <Stl.h>
//-------------------------------------------------------------------------------------------------
bool
isValid()
{
	// std::cout << "\nfunc: " << __FUNCTION__ << std::endl;

    // return true;
}
//-------------------------------------------------------------------------------------------------
int main(int, char **)
{
    std::cout << ::isValid() << std::endl;

    return 0;
}
//-------------------------------------------------------------------------------------------------


#if OUTPUT

145 // random value

#endif
