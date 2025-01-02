/**
 * \file  CallMethod.cpp
 * \brief Вызов нестатического метода класса без создания экземпляра в C++
 *
 * http://www.quizful.net/interview/cpp/non-static-method-call-cpp
 */


#include <StdStream/StdStream.h>
#include <StdTest/StdTest.h>
#include <Stl.h>
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
	A *a = (A *)12;
	a->foo();

    return EXIT_SUCCESS;
}
//-------------------------------------------------------------------------------------------------


#if OUTPUT

foo

#endif
