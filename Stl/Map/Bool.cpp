/**
 * \file  Bool.cpp
 * \brief
 */


#include <StdStream/StdStream.h>
#include <StdTest/StdTest.h>
#include <Stl.h>
//-------------------------------------------------------------------------------------------------
int main(int, char **)
{
	std::map<std::string, bool> m;
	m["A"] = true;
	m["B"] = false;
	m["C"] = true;

	for (auto &it_m : m) {
		std::cout << "{" << it_m.first << "," << it_m.second << "}" << std::endl;
	}

	std::cout << "{Z," << m["Z"] << "} - default ctor" << std::endl;

    return 0;
}
//-------------------------------------------------------------------------------------------------


#if OUTPUT

{A,1}
{B,0}
{C,1}
{Z,0} - default ctor

#endif
