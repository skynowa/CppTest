/**
 * \file  WithPred.cpp
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
//-------------------------------------------------------------------------------------------------
int main(int, char **)
{
    // Less
    {
        using int_unordered_map_less_t = std::unordered_map<int, int, Hash, std::less<int>>;

        const int_unordered_map_less_t mapLess
        {
            {11, 9},
            {22, 8},
            {33, 7}
        };

        std::cout << "Less: " << std::endl;

        for (const auto &[it_key, it_value] : mapLess) {
            std::cout << "{" << it_key << ", " << it_value << "}" << std::endl;
        }
    }

    std::cout << std::endl;

    // Greater
    {
        using int_unordered_map_greater_t = std::unordered_map<int, int, Hash, std::greater<int>>;

        const int_unordered_map_greater_t mapGreater
        {
            {11, 9},
            {22, 8},
            {33, 7}
        };

        std::cout << "Greater: " << std::endl;

        for (const auto &[it_key, it_value] : mapGreater) {
            std::cout << "{" << it_key << ", " << it_value << "}" << std::endl;
        }
    }

    return EXIT_SUCCESS;
}
//--------------------------------------------------------------------------------------------------


#if OUTPUT

Less:
{33, 7}
{22, 8}
{11, 9}

Greater:
{33, 7}
{22, 8}
{11, 9}

#endif
