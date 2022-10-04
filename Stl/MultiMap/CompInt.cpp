/**
 * \file  CompInt.cpp
 * \brief Int comparator
 */


#include <StdStream/StdStream.h>
#include <StdTest/StdTest.h>
#include <Stl.h>
//-------------------------------------------------------------------------------------------------
using int_mmap_t = std::multimap<int, int, std::less<int>>;
//--------------------------------------------------------------------------------------------------
int main(int, char **)
{
    const ::int_mmap_t intMap
    {
        {2, 2},
        {0, 0},
        {1, 1}
    };

    for (const auto &[it_key, it_value] : intMap) {
        std::cout << "{" << it_key << ", " << it_value << "}" << std::endl;
    }

    return EXIT_SUCCESS;
}
//--------------------------------------------------------------------------------------------------


#if OUTPUT

{0, 0}
{1, 1}
{2, 2}

#endif
