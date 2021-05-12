/**
 * \file  AverageOfValuesInObjects.cpp
 * \brief
 */


#include <StdStream.h>
#include <StdTest.h>
#include <Stl.h>

using namespace std;
//--------------------------------------------------------------------------------------------------
template <typename T>
T
average(T *array, int length)
{
	T sum = 0;

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
	Cents(int cents) :
		_cents(cents)
	{
	}

	int cents()
	{
		cout << _cents << endl;

		return _cents;
	}

	friend bool
	operator > (const Cents &c1, const Cents &c2)
	{
		return (c1._cents > c2._cents);
	}

	friend ostream &
	operator << (ostream& out, const Cents& c1)
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

    cout << ::average(array, 4) << endl;

    return EXIT_SUCCESS;
}
//--------------------------------------------------------------------------------------------------


#if OUTPUT

Average of the Cents is = 11 cents

#endif
