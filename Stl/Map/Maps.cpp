/**
 * \file  main.cpp
 * \brief http://thispointer.com/map-vs-unordered_map-when-to-choose-one-over-another/
 *
 * \todo
 */


#include <StdTest.h>
#include <Stl.h>

//-------------------------------------------------------------------------------------------------
void
testMap()
{
   /**
    * std::map
    *
    * Internally store elements in a balanced BST.
    * Therefore, elements will be stored in sorted order of keys.
    */

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
   /**
    * std::unordered_map
    *
    * Store elements using hash table.
    * Therefore, elements will not be stored in any sorted order. They will be stored in arbitrary order .
    */

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
