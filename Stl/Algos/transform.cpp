/**
 * \file
 * \brief
 *
 * \todo
 */


#include <StdStream.h>
#include <StdTest.h>
#include <Stl.h>

//-------------------------------------------------------------------------------------------------
int main(int, char **)
{
    const auto valuesIn  = std::vector<int>{1, 2, 3, 4, 5};
    auto       valuesOut = std::vector<double>{};

    std::transform(valuesIn.cbegin(), valuesIn.cend(),
        std::back_inserter(valuesOut),
        [](const  int number)
		{
			return number * 1.2;
		});

    std::for_each(valuesOut.cbegin(), valuesOut.cend(),
        [](const double number)
		{
			std::cout << TRACE_VAR(number) << std::endl;
		});

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
