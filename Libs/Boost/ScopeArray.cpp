/**
 * \file  ScopeArray.cpp
 * \brief boost::scoped_array
 */


#include <StdStream.h>
#include <StdTest.h>
#include <Stl.h>

#include "boost/scoped_array.hpp"
//-------------------------------------------------------------------------------------------------
class Printer
{
public:
	Printer() :
		_id{_count ++}
	{
		std::cout << __FUNCTION__ << ": " << TRACE_VAR2(_count, _id) << std::endl;
	}

	~Printer()
	{
		std::cout << __FUNCTION__ << ": " << TRACE_VAR2(_count, _id) << std::endl;
	}

private:
	static inline int _count {};

	int _id {};
};
//-------------------------------------------------------------------------------------------------
int main(int, char **)
{
	{
		boost::scoped_array<Printer> p2(new Printer[5]);
	}

	return EXIT_SUCCESS;
}
//-------------------------------------------------------------------------------------------------

#if OUTPUT

Printer: _count: 1, _id: 0
Printer: _count: 2, _id: 1
Printer: _count: 3, _id: 2
Printer: _count: 4, _id: 3
Printer: _count: 5, _id: 4
~Printer: _count: 5, _id: 4
~Printer: _count: 5, _id: 3
~Printer: _count: 5, _id: 2
~Printer: _count: 5, _id: 1
~Printer: _count: 5, _id: 0

#endif
