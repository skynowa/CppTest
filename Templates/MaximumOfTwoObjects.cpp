/**
 * \file  MaximumOfTwoObjects.cpp
 * \brief
 *
 * \review
 */


#include <StdStream/StdStream.h>
#include <StdTest/StdTest.h>
#include <Stl.h>
//--------------------------------------------------------------------------------------------------
template <typename T>
const T &
maximum(const T &x, const T &y)
{
	return (x > y) ? x : y;
}
//--------------------------------------------------------------------------------------------------
class Cents
{
public:
	explicit Cents(const int cents):
		_cents(cents)
	{
	}

	int cents() const
	{
		return _cents;
	}

	friend bool
	operator > (const Cents &c1, const Cents &c2)
	{
		return (c1._cents > c2._cents);
	}

private:
	const int _cents {};
};
//--------------------------------------------------------------------------------------------------
int main()
{
	Cents nickle(5);
	Cents dime(10);

	Cents bigger = maximum(nickle, dime);

	std::cout << TRACE_VAR(bigger.cents()) << std::endl;

    return EXIT_SUCCESS;
}
//--------------------------------------------------------------------------------------------------

#if OUTPUT

bigger.cents(): 10

#endif
