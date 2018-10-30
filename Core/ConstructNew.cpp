/**
 * \file  main.cpp
 * \brief
 */


#include <StdTest.h>
#include <Stl.h>

//-------------------------------------------------------------------------------------------------
struct Data
{
	Data()
	{
		std::cout << __FUNCTION__ << std::endl;
	}
};
//-------------------------------------------------------------------------------------------------
class A
{
public:
	Data *d;

	A()
	{
	}
};
//-------------------------------------------------------------------------------------------------
int main(int, char **)
{
	{
		A a;
	    std::cout << STD_TRACE_VAR(a.d) << std::endl;
	}

	{
		A *a = new A;
	    std::cout << STD_TRACE_VAR(a->d) << std::endl;
		delete a;
	}

	{
		A *a = new A();
	    std::cout << STD_TRACE_VAR(a->d) << std::endl;
		delete a;
	}

    return EXIT_SUCCESS;
}
//-------------------------------------------------------------------------------------------------


#if OUTPUT

a.d: 0x7f52ab0639a0
a->d: 0
a->d: 0

#endif
