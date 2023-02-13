/**
 * \file  PrefixIncermentDecrementOperator.cpp
 * \brief
 *
 * \review
 *
 * Note that we return *this. The overloaded increment and decrement operators return the current
 * implicit object so multiple operators can be “chained” together.
 */


#include <StdStream/StdStream.h>
#include <StdTest/StdTest.h>
#include <Stl.h>
//--------------------------------------------------------------------------------------------------
class Digits
{
public:
	Digits(int digit) :
		_digit(digit)
	{
	}

	Digits & operator ++ ();
	Digits & operator -- ();

	friend
	std::ostream& operator << (std::ostream &out, const Digits &d);

private:
	int _digit {};
};
//--------------------------------------------------------------------------------------------------
Digits &
Digits::operator ++ ()
{
	if (_digit == 9)
		_digit = 0;
	else
		++_digit;

	return *this;
}
//--------------------------------------------------------------------------------------------------
Digits &
Digits::operator -- ()
{
	if (_digit == 0)
		_digit = 9;
	else
		--_digit;

	return *this;
}
//--------------------------------------------------------------------------------------------------
std::ostream &
operator << (std::ostream &out, const Digits &d)
{
	out << d._digit;

	return out;
}
//--------------------------------------------------------------------------------------------------
int main()
{
	Digits d1(6);

	std::cout << "The Digit is : "     << d1      << std::endl;
	std::cout << "Prefix Increment : " << (++ d1) << std::endl;
	std::cout << "Prefix Decrement : " << (-- d1) << std::endl;

    return EXIT_SUCCESS;
}
//--------------------------------------------------------------------------------------------------


#if OUTPUT

The Digit is : 6
Prefix Increment : 7
Prefix Decrement : 6

#endif
