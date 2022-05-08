/**
 * \file  NamespaceOperator.cpp
 * \brief
 *
 * \review
 */


#include <StdStream/StdStream.h>
#include <StdTest/StdTest.h>
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
		std::cout << TRACE_VAR(_d) << std::endl;
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

    return EXIT_SUCCESS;
}
//-------------------------------------------------------------------------------------------------


#if OUTPUT

_d: {data_string}

#endif
