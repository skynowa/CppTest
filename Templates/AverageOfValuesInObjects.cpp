/**
 * \file  AverageOfValuesInObjects.cpp
 * \brief
 *
 * \review
 */


#include <StdStream/StdStream.h>
#include <StdTest/StdTest.h>
#include <Stl.h>
//--------------------------------------------------------------------------------------------------
template<typename T>
T
average(T *array, int length)
{
	T sum = 0; /* explicit */

	for (int i = 0; i < length; i++) {
		sum += array[i];
	}

	sum /= length;

	return sum;
}
//--------------------------------------------------------------------------------------------------
class Cents
{
public:
	/* explicit */ Cents(int a_cents) :
		_cents(a_cents)
	{
	}

	int
	cents() const
	{
		std::cout << _cents << std::endl;

		return _cents;
	}

	friend bool
	operator > (const Cents &c1, const Cents &c2)
	{
		return (c1._cents > c2._cents);
	}

	friend std::ostream &
	operator << (std::ostream& out, const Cents& c1)
	{
		out << "Average of the Cents is = " << c1._cents << " cents";
		return out;
	}

	Cents &
	operator += (Cents &c1)
	{
		_cents += c1._cents;
		return *this;
	}

	Cents &
	operator /= (int value)
	{
		_cents /= value;
		return *this;
	}

private:
	int _cents {};
};
//--------------------------------------------------------------------------------------------------
int main()
{
    Cents array[] { Cents(5), Cents(10), Cents(15), Cents(14) };

    std::cout << ::average(array, 4) << std::endl;

    return EXIT_SUCCESS;
}
//--------------------------------------------------------------------------------------------------


#if OUTPUT

Average of the Cents is = 11 cents

#endif
