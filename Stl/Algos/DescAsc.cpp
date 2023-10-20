/**
 * \file  DescAsc.cpp
 * \brief
 *
 * \see
 * \todo
 */


#include <StdStream/StdStream.h>
#include <StdTest/StdTest.h>
#include <Stl.h>
//--------------------------------------------------------------------------------------------------
int main(int, char **)
{
    std::vector<int> v {2, 1, 5, 3, 4};

    auto asc = [&](const int it_1, const int it_2) -> bool
    {
        return it_1 < it_2;
    };

    auto desc = [&](const int it_1, const int it_2) -> bool
    {
        return it_1 > it_2;
    };

    // ASC
    {
    	std::sort(v.begin(), v.end(), asc);

        std::cout << "ASC: " << v << std::endl;
    }

    // DESC
    {
    	std::sort(v.begin(), v.end(), desc);

        std::cout << "DESC: " << v << std::endl;
    }

    return EXIT_SUCCESS;
}
//--------------------------------------------------------------------------------------------------


#if OUTPUT

ASC:  1 2 3 4 5
DESC: 5 4 3 2 1

#endif
