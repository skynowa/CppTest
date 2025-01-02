/**
 * \file  Global1.cpp
 * \brief global and local var with the same name
 */


#include <StdStream/StdStream.h>
#include <StdTest/StdTest.h>
#include <Stl.h>
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

    return EXIT_SUCCESS;
}
//---------------------------------------------------------------------------

#if OUTPUT

Global s = string_global
Local  s = string_local

#endif
