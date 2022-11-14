/**
 * \file  Basics.cpp
 * \brief
 *
 * \todo
 */


#include <StdStream/StdStream.h>
#include <StdTest/StdTest.h>
#include <Stl.h>
//-------------------------------------------------------------------------------------------------
struct Hash
{
    std::size_t operator() (const int value) const
    {
        return std::hash<int>()(value);
    }
};

using int_unordered_map_less_t    = std::unordered_map<int, int, Hash, std::less<int>>;
using int_unordered_map_greater_t = std::unordered_map<int, int, Hash, std::greater<int>>;
//-------------------------------------------------------------------------------------------------
int main(int, char **)
{
    const int_unordered_map_less_t intMap
    {
        {11, 1},
        {22, 2},
        {33, 3}
    };

    for (const auto &[it_key, it_value] : intMap) {
        std::cout << "{" << it_key << ", " << it_value << "}" << std::endl;
    }

    return EXIT_SUCCESS;
}
//--------------------------------------------------------------------------------------------------


#if OUTPUT

{Third, 8}
{First, 1}
{Second, 2}

#endif
