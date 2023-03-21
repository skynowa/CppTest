/**
 * \file  ScopeArray.cpp
 * \brief boost::scoped_array
 */


#include <StdStream/StdStream.h>
#include <StdTest/StdTest.h>
#include <Stl.h>

#if BOOST_VERSION > 0

#include <boost/scoped_array.hpp>
//-------------------------------------------------------------------------------------------------
class Printer
{
public:
	Printer() :
		_id{_count ++}
	{
		std::cout << __FUNCTION__ << ": " << STD_TRACE_VAR2(_count, _id) << std::endl;
	}

	~Printer()
	{
		std::cout << __FUNCTION__ << ": " << STD_TRACE_VAR2(_count, _id) << std::endl;
	}

private:
	static inline int _count {};

	int _id {};
};

#endif
//-------------------------------------------------------------------------------------------------
int main(int, char **)
{
#if BOOST_VERSION > 0
	{
		boost::scoped_array<Printer> p2(new Printer[5]);
	}
#else
	std::cout << "Boost - not instaled, skip" << std::endl;
#endif

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
