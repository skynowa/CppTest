/**
 * \file  main.cpp
 * \brief Вызов нестатического метода класса без создания экземпляра в C++
 *
 * http://www.quizful.net/interview/cpp/non-static-method-call-cpp
 */


#include <StdTest.h>

//-------------------------------------------------------------------------------------------------
class A
{
public:
    A()
    {
        std::cout << __FUNCTION__ << std::endl;
    }

    ~A()
    {
        std::cout << __FUNCTION__ << std::endl;
    }

    void foo()
    {
        std::cout << __FUNCTION__ << std::endl;
    }
};
//-------------------------------------------------------------------------------------------------
int main(int, char **)
{
	A *a = (A*)12;
	a->foo();

    return 0;
}
//-------------------------------------------------------------------------------------------------


#if OUTPUT

foo

#endif

