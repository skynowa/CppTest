/**
 * \file  Insertion.cpp
 * \brief
 */


#include <StdStream/StdStream.h>
#include <StdTest/StdTest.h>
#include <Stl.h>
//-------------------------------------------------------------------------------------------------
int main(int, char **)
{
    // Creating an empty unordered_map
    std::unordered_map<std::string, int> wordMap;

    // Inserting elements through an initializer_list
    wordMap.insert( {{"First", 1}, {"Second", 2}, {"Third", 3}} );

    using UOMIterator = std::unordered_map<std::string, int>::iterator;

    // Pair of Map Iterator and bool value
    std::pair<UOMIterator, bool> result;

    // Inserting an element through pair
    result = wordMap.insert( std::make_pair<std::string, int>("Second", 6) );
    if (result.second == false) {
        std::cout << "Element 'Second' not inserted again" <<std::endl;
    }

    // Inserting an element through value_type
    result = wordMap.insert( {"Fourth", 4} );
    if (result.second == false) {
        std::cout << "Element 'Fourth' not inserted again"<<std::endl;
    } else {
        // Element inserted sucessfully, so first value in pair
        // is the iterator of newly inserted element
        std::cout << "Element Inserted : ";
        std::cout << result.first->first << "::" << result.first->second << std::endl;
    }

    std::cout << STD_TRACE_VAR(wordMap) << std::endl;

    return EXIT_SUCCESS;
}
//-------------------------------------------------------------------------------------------------

#if OUTPUT

Element 'Second' not inserted again
Element Inserted : Fourth::4

wordMap: std::unordered_map (size=4): {
std::pair: {Third,3}
std::pair: {Second,2}
std::pair: {Fourth,4}
std::pair: {First,1}}

#endif
