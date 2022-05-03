/**
 * \file  ReturnBool.cpp
 * \brief Returm "NO" value (as bool)
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
