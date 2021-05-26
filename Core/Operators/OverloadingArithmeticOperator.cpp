/**
 * \file  OverloadingArithmeticOperator.cpp
 * \brief
 */


#include <StdStream.h>
#include <StdTest.h>
#include <Stl.h>
//--------------------------------------------------------------------------------------------------
class Cents
{
public:
	Cents(int cents) :
		_cents(cents)
	{
	}

	int getCents() const
	{
		return _cents;
	}

	friend Cents
	operator + (const Cents &c1, const Cents &c2)
	{
		return Cents(c1._cents + c2._cents);
	}

	friend Cents
	operator - (const Cents &c1, const Cents &c2)
	{
		return Cents(c1._cents - c2._cents);
	}

	friend Cents
	operator + (const Cents &c1, int value)
	{
		// we can access _cents directly because this is a friend function
		return Cents(c1._cents + value);
	}

	friend
	Cents operator + (int value, const Cents &c1)
	{
		// we can access _cents directly because this is a friend function
		return Cents(c1._cents + value);
	}

private:
	int _cents {};
};
//--------------------------------------------------------------------------------------------------
int main()
{
	Cents c1(5);
	Cents c2(10);

	Cents cent_sum  = c1 + c2;
	Cents cent_diff = c2 - c1;

	std::cout << "I have " << cent_sum.getCents() << " cents" << std::endl;
	std::cout << "I have " << cent_diff.getCents() << " cents." << std::endl;

	Cents c3 = Cents(4) + 6;
	Cents c4 = 6 + Cents(4);

	std::cout << "I have " << c3.getCents() << " cents." << std::endl;
	std::cout << "I have " << c4.getCents() << " cents." << std::endl;

	return 0;
}
//--------------------------------------------------------------------------------------------------


#if OUTPUT

I have 15 cents
I have 5 cents.
I have 10 cents.
I have 10 cents.

#endif
