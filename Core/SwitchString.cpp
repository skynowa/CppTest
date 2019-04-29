/**
 * \file  main.cpp
 * \brief
 */


#include <StdStream.h>
#include <StdTest.h>
#include <Stl.h>
#include <iostream>
#include <functional>
#include <string>
//-------------------------------------------------------------------------------------------------
constexpr unsigned int
hash(const char *str, int h = 0)
{
    return !str[h] ? 5381 : (hash(str, h + 1) * 33) ^ str[h];
}
//-------------------------------------------------------------------------------------------------
void
switch_test(const std::string& name)
{
	std::cout << name << " -> ";

    switch (::hash(name.c_str()))
    {
    case ::hash("Alice"):
        std::cout << "Alice" << std::endl;
        break;
    case ::hash("Bob"):
        std::cout << "Bob" << std::endl;
        break;
    case ::hash("Charlie"):
		std::cout << "Charlie" << std::endl;
        break;
    default:
        std::cout << "[Unknown]" << std::endl;
        break;
    }
}
//-------------------------------------------------------------------------------------------------
int main(int, char **)
{
    ::switch_test("alice");
    ::switch_test("Alice");

    return EXIT_SUCCESS;
}
//-------------------------------------------------------------------------------------------------


#if OUTPUT



#endif
