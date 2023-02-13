/**
 * \file  UnorderedMap.cpp
 * \brief
 *
 * \todo
 */


#include <StdTest/StdTest.h>
#include <Stl.h>

//-------------------------------------------------------------------------------------------------
template<template<class...> class T>
void test()
{
    T<std::string, int> x;
    x.insert(std::make_pair("one", 1));
    x.insert(std::make_pair("two", 2));
    x.insert(std::make_pair("three", 3));
    x.insert(std::make_pair("four", 4));

    for (const auto& i : x) {
        std::cout << "{" << i.first << ", " << i.second << "}" << std::endl;
    }
}
//-------------------------------------------------------------------------------------------------
int main(int, char **)
{
	std::cout << "std::map:" << std::endl;
	test<std::map>();

	std::cout << "\nstd::unordered_map:" << std::endl;
	test<std::unordered_map>();

	return 0;
}
//-------------------------------------------------------------------------------------------------


#if OUTPUT

std::map:
{four, 4}
{one, 1}
{three, 3}
{two, 2}

std::unordered_map:
{four, 4}
{three, 3}
{one, 1}
{two, 2}

#endif
