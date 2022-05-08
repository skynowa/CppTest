/**
 * \file  CstrNull.cpp
 * \brief c_str(), data(), ... of empty std::string
 */


#include <StdStream/StdStream.h>
#include <StdTest/StdTest.h>
#include <Stl.h>
//---------------------------------------------------------------------------
int main(int, char **)
{
    const std::string str;

    const char *ptr {};
    assert(ptr == nullptr);

    ptr = str.c_str();
    assert(ptr != nullptr);

    ptr = str.data();
    assert(ptr != nullptr);

    ptr = &str[0];
    assert(ptr != nullptr);

    STD_UNUSED(ptr);

    return EXIT_SUCCESS;
}
//---------------------------------------------------------------------------

#if OUTPUT

    <no asserts>

#endif
