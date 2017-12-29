/**
 * \file  main.cpp
 * \brief
 */


#include <StdTest.h>
#include <map>

//-------------------------------------------------------------------------------------------------
int main(int argsNum, char **args)
{
	std::map<std::string, bool> m;
	m["A"] = true;
	m["B"] = false;
	m["C"] = true;

	for (auto &it_m : m) {
		std::cout << "{" << it_m.first << "," << it_m.second << "}" << std::endl;
	}

	std::cout << "{Z," << m["Z"] << "}" << std::endl;

    return 0;
}
//-------------------------------------------------------------------------------------------------


#if OUTPUT

{A,1}
{B,0}
{C,1}
{Z,0}

#endif

