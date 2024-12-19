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
    STD_TEST(ptr == nullptr);

    ptr = str.c_str();
    STD_TEST_PTR(ptr);

    ptr = str.data();
    STD_TEST_PTR(ptr);

    ptr = &str[0];
    STD_TEST_PTR(ptr);

    STD_UNUSED(ptr);

    return EXIT_SUCCESS;
}
//---------------------------------------------------------------------------

#if OUTPUT

    <no asserts>

#endif
