/**
 * \file  Initialization.cpp
 * \brief
 */


#include <StdStream/StdStream.h>
#include <StdTest/StdTest.h>
#include <Stl.h>
//-------------------------------------------------------------------------------------------------
int main(int, char **)
{
	// Initialize an unordered_map through initializer_list
	const std::unordered_map<std::string, int> wordMap
    (
        {
            {"First",  1},
            {"Second", 2},
            {"Third",  3}
        }
    );

    {
        std::cout << STD_TRACE_VAR(wordMap) << std::endl;
        std::cout << "*******************" << std::endl;
    }

    {
        // Initialize an unordered_map through another range of elements of type std::pair
        const std::unordered_map<std::string, int> wordMap_2(wordMap.cbegin(), wordMap.cend());

        std::cout << STD_TRACE_VAR(wordMap_2) << std::endl;
        std::cout << "*******************" << std::endl;
    }

    {
        // Initialize an unordered_map through other unordered_map
        const std::unordered_map<std::string, int> wordMap_3(wordMap);

        std::cout << STD_TRACE_VAR(wordMap_3) << std::endl;
        std::cout << "*******************" << std::endl;
    }

	return EXIT_SUCCESS;
}
//-------------------------------------------------------------------------------------------------

#if OUTPUT

wordMap: std::unordered_map (size=3): {
std::pair: {Third,3}
std::pair: {Second,2}
std::pair: {First,1}}
*******************
wordMap_2: std::unordered_map (size=3): {
std::pair: {First,1}
std::pair: {Second,2}
std::pair: {Third,3}}
*******************
wordMap_3: std::unordered_map (size=3): {
std::pair: {Third,3}
std::pair: {Second,2}
std::pair: {First,1}}
*******************

#endif
