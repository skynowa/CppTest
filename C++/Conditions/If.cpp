/**
 * \file  If.cpp
 * \brief
 */


#include <StdStream/StdStream.h>
#include <StdTest/StdTest.h>
#include <Stl.h>
//--------------------------------------------------------------------------------------------------
bool
success()
{
    return true;
}
//--------------------------------------------------------------------------------------------------
bool
fail()
{
    return false;
}
//--------------------------------------------------------------------------------------------------
int main(int, char **)
{
   /**
    * Inner condition
    */

    // success
    {
        bool bRv {};

        if ( (bRv = success()) ) {
            std::cout << "success: " << "true" << std::endl;
        } else {
            std::cout << "success: " << "false" << std::endl;
        }
    }

    // fail
    {
        bool bRv {};

        if ( (bRv = fail()) ) {
            std::cout << "fail: " << "true" << std::endl;
        } else {
            std::cout << "fail: " << "false" << std::endl;
        }
    }

    return EXIT_SUCCESS;
}
//--------------------------------------------------------------------------------------------------


#if OUTPUT

success: true
fail: false

#endif
