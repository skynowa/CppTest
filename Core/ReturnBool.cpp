/**
 * \file  ReturnBool.cpp
 * \brief
 */


#include <StdStream.h>
#include <StdTest.h>
#include <Stl.h>
//--------------------------------------------------------------------------------------------------
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wreturn-type"

bool
isValid()
{
	// std::cout << "\nfunc: " << __FUNCTION__ << std::endl;

    // return true;
}

#pragma GCC diagnostic pop
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
