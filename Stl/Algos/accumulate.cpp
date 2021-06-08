 /*
 * \file  accumulate.cpp
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
	std::list<std::string> amounts;
	amounts.push_back("0.1");
	amounts.push_back("0.2");
	amounts.push_back("0.3");

	std::string sRv = std::accumulate(amounts.begin(), amounts.end(), std::string("0.0"),
		[&](const std::string &a_it_1, const std::string &a_it_2)
		{
			return std::to_string(std::stod(a_it_1) + std::stod(a_it_2));
		});

    std::cout << TRACE_VAR(sRv) << std::endl;

    return 0;
}
//-------------------------------------------------------------------------------------------------


#if OUTPUT

sRv: 0.600000

#endif
