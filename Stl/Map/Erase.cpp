/**
 * \file  main.cpp
 * \brief
 */


#include <StdTest.h>
#include <map>

//-------------------------------------------------------------------------------------------------
int main(int, char **)
{
	std::size_t uiRv = 0;

	std::map<char,int> m;
	m['a'] = 10;
	m['b'] = 20;
	m['c'] = 30;

	uiRv = m.erase('a');
	std::cout << "a: " << STD_TRACE_VAR(uiRv) << std::endl;

	uiRv = m.erase('a');
	std::cout << "a: " << STD_TRACE_VAR(uiRv) << std::endl;

	uiRv = m.erase('x');
	std::cout << "x: " << STD_TRACE_VAR(uiRv) << std::endl;

	for (std::map<char,int>::iterator it=m.begin(); it!=m.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';


	return 0;
}
//-------------------------------------------------------------------------------------------------


#if OUTPUT

a: uiRv: 1
a: uiRv: 0
x: uiRv: 0
b => 20
c => 30

#endif

