/**
 * \file  CstrNull.cpp
 * \brief c_str() of empty std::string
 */


//---------------------------------------------------------------------------
#include <unistd.h>
#include <assert.h>
#include <string>
#include <iostream>
//---------------------------------------------------------------------------
int main(int, char **)
{
    std::string s;

    const char *p = NULL;
    assert(NULL == p);

    p = s.c_str();
    assert(NULL != p);

    // std::cout << "" << std::endl;

    return 0;
}
//---------------------------------------------------------------------------

#if OUTPUT
// NOTE:

$ ./CstrNull
    <no asserts>

#endif
