/**
 * \file  main.cpp
 * \brief
 */


#include "../StdTest.h"
#include "../Stl.h"

//-------------------------------------------------------------------------------------------------
void
testMap()
{
	std::cout << "\n" << __FUNCTION__ << std::endl;

    std::map<int, int> values;
    values[5]  = 10;
    values[3]  = 5;
    values[20] = 100;
    values[1]  = 1;

    for (auto &it_value : values) {
        std::cout << it_value.first << " : " << it_value.second << '\n';
    }
}
//-------------------------------------------------------------------------------------------------
void
testUnorderedMap()
{
	std::cout << "\n" << __FUNCTION__ << std::endl;

    std::unordered_map<int, int> values;
    values[5]  = 10;
    values[3]  = 5;
    values[20] = 100;
    values[1]  = 1;

    for (auto &it_value : values) {
        std::cout << it_value.first << " : " << it_value.second << '\n';
    }
}
//-------------------------------------------------------------------------------------------------
int main(int, char **)
{
	testMap();
	testUnorderedMap();

    return 0;
}
//-------------------------------------------------------------------------------------------------


#if OUTPUT

testMap
1 : 1
3 : 5
5 : 10
20 : 100

testUnorderedMap
1 : 1
20 : 100
5 : 10
3 : 5

#endif
