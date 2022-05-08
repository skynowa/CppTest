/**
 * \file  FunctorTarget.cpp
 * \brief function::target example
 */


#include <StdStream/StdStream.h>
#include <StdTest/StdTest.h>
#include <Stl.h>
//-------------------------------------------------------------------------------------------------
using functor_t     = std::function<void(const std::string &value)>;
using functor_ptr_t = void(*)(const std::string &value);
//-------------------------------------------------------------------------------------------------
void
functor(const std::string &value)
{
    std::cout << __FUNCTION__ << " " << value << std::endl;
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

    return EXIT_SUCCESS;
}
//-------------------------------------------------------------------------------------------------


#if OUTPUT

0
0
0x7ffd4a640e90
functor test123
0

#endif
