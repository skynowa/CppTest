/**
 * \file  main.cpp
 * \brief
 */


#include <StdTest.h>
#include <Stl.h>


//-------------------------------------------------------------------------------------------------
struct Data
{
	std::string s;
};
//-------------------------------------------------------------------------------------------------
// namespace n
// {

std::ostream &
operator << (std::ostream &a_os, const ::Data &a_value)
{
    a_os << "{" << a_value.s << "}";

    return a_os;
}

// }
//-------------------------------------------------------------------------------------------------
namespace n
{

class A
{
public:
	A()
	{
		_d.s = "data_string";
	}

	void print()
	{
		std::cout << STD_TRACE_VAR(_d) << std::endl;
	}

private:
	Data _d;
};

}
//-------------------------------------------------------------------------------------------------
int main(int, char **)
{
	n::A a;
	a.print();

    return 0;
}
//-------------------------------------------------------------------------------------------------


#if OUTPUT

_d: {data_string}

#endif
