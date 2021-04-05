/**
 * \file  main.cpp
 * \brief function::target example
 *
 * \todo
 */


#include <StdTest.h>

#include <iostream>
#include <functional>
#include <vector>

using namespace std;
//-------------------------------------------------------------------------------------------------
using functor_t     = function<void(const string &value)>;
using functor_ptr_t = void(*)(const string &value);

void functor(const string &value)
{
    cout << __FUNCTION__ << " " << value << endl;
}
//-------------------------------------------------------------------------------------------------
int main(int, char **)
{
    // std::function<int(int,int)> foo1 = my_plus;
    // std::function<int(int,int)> foo2;
    // std::function<int(int,int)> foo3 {};

    // std::cout << foo1.target<int(*)(int,int)>() << std::endl;
    // std::cout << foo2.target<int(*)(int,int)>() << std::endl;
    // std::cout << foo3.target<int(*)(int,int)>() << std::endl;

    functor_t f;
	std::cout << f.target<functor_ptr_t>() << std::endl;

    f = {};
    std::cout << f.target<functor_ptr_t>() << std::endl;

    f = functor;
    std::cout << f.target<functor_ptr_t>() << std::endl;

    f("test123");

    f = nullptr;
    std::cout << f.target<functor_ptr_t>() << std::endl;

    std::cout << "Finished" << std::endl;

    return 0;
}
//-------------------------------------------------------------------------------------------------


#if OUTPUT

0
0
0x7ffc98252fb0

#endif
