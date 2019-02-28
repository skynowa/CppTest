/**
 * \file  main.cpp
 * \brief
 */


#include <StdTest.h>
#include <Stl.h>

//-------------------------------------------------------------------------------------------------
int main(int, char **)
{
	std::map<std::string, std::string> m;

    std::cout << STD_TRACE_VAR(m["test"].empty()) << std::endl;
    std::cout << STD_TRACE_VAR(m["test"].empty()) << std::endl;

    return 0;
}
//-------------------------------------------------------------------------------------------------


#if OUTPUT

m["test"].empty(): 1
m["test"].empty(): 1

#endif
