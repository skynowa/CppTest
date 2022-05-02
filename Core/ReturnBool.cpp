/**
 * \file  ReturnBool.cpp
 * \brief
 */


#include <StdStream.h>
#include <StdTest.h>
#include <Stl.h>
//--------------------------------------------------------------------------------------------------
bool
isValid()
{
	// std::cout << "\nfunc: " << __FUNCTION__ << std::endl;

    // return true;
}
//-------------------------------------------------------------------------------------------------
int main(int, char **)
{
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wreturn-type"
    std::cout << ::isValid() << std::endl;
#pragma GCC diagnostic pop

    return 0;
}
//-------------------------------------------------------------------------------------------------


#if OUTPUT

145 // random value

#endif
