/**
 * \file  main.cpp
 * \brief global and local var with the same name
 */


//---------------------------------------------------------------------------
#include <unistd.h>
#include <assert.h>
#include <string>
#include <iostream>
//---------------------------------------------------------------------------
std::string s = "string_global";
//---------------------------------------------------------------------------
int main(int, char **)
{
    std::string s = "string_local";

    assert("string_global" == ::s);
    std::cout << "Global s = " << ::s << std::endl;

    assert("string_local" == s);
    std::cout << "Local  s = " << s   << std::endl;

    return 0;
}
//---------------------------------------------------------------------------

#if OUTPUT
// NOTE:

> ./main

    Global s = string_global
    Local  s = string_local

#endif
