/**
 * \file  CompInt.cpp
 * \brief Int comparator
 */


#include <StdStream/StdStream.h>
#include <StdTest/StdTest.h>
#include <Stl.h>
//-------------------------------------------------------------------------------------------------
using int_mmap_less_t    = std::multimap<int, int, std::less<int>>;
using int_mmap_greater_t = std::multimap<int, int, std::greater<int>>;
//--------------------------------------------------------------------------------------------------
int main(int, char **)
{
    {
        const ::int_mmap_less_t intMap
        {
            {3, 200},
            {1, 400},
            {4, 999},
            {2, 300}
        };

        std::cout << "int_mmap_less_t:" << std::endl;

        for (const auto &[it_key, it_value] : intMap) {
            std::cout << "{" << it_key << ", " << it_value << "}" << std::endl;
        }
    }

    {
        const ::int_mmap_greater_t intMap
        {
            {3, 200},
            {1, 400},
            {4, 999},
            {2, 300}
        };

        std::cout << "\nint_mmap_greater_t:" << std::endl;

        for (const auto &[it_key, it_value] : intMap) {
            std::cout << "{" << it_key << ", " << it_value << "}" << std::endl;
        }
    }

    return EXIT_SUCCESS;
}
//--------------------------------------------------------------------------------------------------


#if OUTPUT

int_mmap_less_t:
{1, 400}
{2, 300}
{3, 200}
{4, 999}

int_mmap_greater_t:
{4, 999}
{3, 200}
{2, 300}
{1, 400}

#endif
