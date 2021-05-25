/**
 * \file  EnumIO_test.cpp
 * \brief smart enum
 *
 * \review
 */


#include "EnumIO.h"

//-------------------------------------------------------------------------------------------------
// Define Enum Like this
enum X
{
    Hi  = 0,
    Lo  = 1,
    Max = 5
};

// Then you just need to define their string values.
template<> char const*
enumStrings<X>::data[] = {"Hi", "Lo", "Max"};
//-------------------------------------------------------------------------------------------------
int main()
{
    X a = Max;

    std::cout << enumToString(a) << "\n";

    std::stringstream line("Lo");
    line >> enumFromString(a);

    std::cout << "A: " << a << " : " << enumToString(a) << "\n";
}
//-------------------------------------------------------------------------------------------------
