/**
 * \file  Deprecated.cpp
 * \brief
 *
 * Indicates that the use of the name or entity declared with this attribute is allowed,
 * but discouraged for some reason. Compilers typically issue warnings on such uses.
 * The string-literal, if specified, is usually included in the warnings.
 */


#include <StdStream.h>
#include <StdTest.h>
#include <Stl.h>
#include <iostream>
 //-------------------------------------------------------------------------------------------------
[[deprecated]]
void TriassicPeriod()
{
    std::clog << "Triassic Period: [251.9 - 208.5] million years ago.\n";
}
 //-------------------------------------------------------------------------------------------------
[[deprecated("Use NeogenePeriod() instead.")]]
void JurassicPeriod()
{
    std::clog << "Jurassic Period: [201.3 - 152.1] million years ago.\n";
}
//-------------------------------------------------------------------------------------------------
[[deprecated("Use calcSomethingDifferently(int).")]]
int calcSomething(int x)
{
    return x * 2;
}
//-------------------------------------------------------------------------------------------------
int main(int, char **)
{
    // TriassicPeriod();
    // JurassicPeriod();

    return EXIT_SUCCESS;
}
//-------------------------------------------------------------------------------------------------


#if OUTPUT

// warnings

#endif
