/**
 * \file  transform.cpp
 * \brief
 */


#include <StdStream.h>
#include <StdTest.h>
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
                std::cout << TRACE_VAR(a_num) << std::endl;

                return a_num * 1.2;
            });
    }

    {
        std::cout << "\nSample #2" << std::endl;

        std::vector<int> valuesIn {1, 2, 3, 4, 5};

        std::transform(valuesIn.begin(), valuesIn.end(),
            valuesIn.begin(),
            [](const int a_num) -> int
            {
                std::cout << TRACE_VAR(a_num) << std::endl;

                return a_num * 1.2;
            });
    }

    {
        std::cout << "\nSample #3" << std::endl;

        const std::vector<int> valuesIn {1, 2, 3, 4, 5};

        std::for_each(valuesIn.cbegin(), valuesIn.cend(),
            [](const int a_num) -> int
            {
                std::cout << TRACE_VAR(a_num) << std::endl;

                return a_num * 1.2;
            });
    }

    return EXIT_SUCCESS;
}
//-------------------------------------------------------------------------------------------------


#if OUTPUT

number: 1.2
number: 2.4
number: 3.6
number: 4.8
number: 6

#endif
