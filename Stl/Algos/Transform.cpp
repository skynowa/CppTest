/**
 * \file  Transform.cpp
 * \brief
 */


#include <StdStream/StdStream.h>
#include <StdTest/StdTest.h>
#include <Stl.h>
//-------------------------------------------------------------------------------------------------
int main(int, char **)
{
    {
        std::cout << "\nSample #1" << std::endl;

        const std::vector<int> valuesIn {1, 2, 3, 4, 5};
        std::vector<double>    valuesOut;

        std::transform(valuesIn.cbegin(), valuesIn.cend(),
            std::back_inserter(valuesOut),
            [](const int a_num) -> int
            {
                return a_num * 1.2;
            });

        std::cout << STD_TRACE_VAR(valuesOut) << std::endl;
    }

    {
        std::cout << "\nSample #2" << std::endl;

        std::vector<int> valuesIn {1, 2, 3, 4, 5};

        std::transform(valuesIn.begin(), valuesIn.end(),
            valuesIn.begin(),
            [](const int a_num) -> int
            {
                return a_num * 1.2;
            });

        std::cout << STD_TRACE_VAR(valuesIn) << std::endl;
    }

    {
        std::cout << "\nSample #3" << std::endl;

        const std::vector<int> valuesIn {1, 2, 3, 4, 5};
        std::vector<double>    valuesOut;

        std::for_each(valuesIn.cbegin(), valuesIn.cend(),
            [&](const int a_num) -> void
            {
                valuesOut.push_back(a_num * 1.2);
            });

        std::cout << STD_TRACE_VAR(valuesIn) << std::endl;
    }

    return EXIT_SUCCESS;
}
//-------------------------------------------------------------------------------------------------


#if OUTPUT

Sample #1
valuesOut: std::vector (size=5): {1,2,3,4,6}

Sample #2
valuesIn: std::vector (size=5): {1,2,3,4,6}

Sample #3
valuesIn: std::vector (size=5): {1,2,3,4,5}

#endif
