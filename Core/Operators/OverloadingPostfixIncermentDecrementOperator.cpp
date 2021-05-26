/**
 * \file  OverloadingPostfixIncermentDecrementOperator.cpp
 * \brief
 */


#include <StdStream.h>
#include <StdTest.h>
#include <Stl.h>
//--------------------------------------------------------------------------------------------------
class Digits
{
public:
	Digits(int digit) :
		_digit(digit)
	{
	}

	Digits operator ++ (int);
	Digits operator -- (int);

	friend
	std::ostream &operator << (std::ostream &out, const Digits &d);

private:
	int _digit {};
};
//--------------------------------------------------------------------------------------------------
Digits
Digits::operator ++ (int)
{
	// Create a temporary variable with our current digit
	Digits temp(_digit);

	// Use prefix operator to increment this digit
	++ _digit;

	// return temporary result
	return temp;
}
//--------------------------------------------------------------------------------------------------
Digits
Digits::operator -- (int)
{
	Digits temp(_digit);

	--_digit;

	return temp;
}
//--------------------------------------------------------------------------------------------------
std::ostream &
operator << (std::ostream &out, const Digits &d)
{
	out << d._digit;

	return out;
}
//--------------------------------------------------------------------------------------------------
int main(int, char **)
{
	Digits d1(5);

	std::cout << "The Digit is : "      << d1      << std::endl;
	std::cout << "Postfix Increment : " << (d1 ++) << std::endl;
	std::cout << "Postfix Decrement : " << (d1 --) << std::endl;

    return EXIT_SUCCESS;
}
//--------------------------------------------------------------------------------------------------


#if OUTPUT

The Digit is : 5
Postfix Increment : 5
Postfix Decrement : 6

#endif
