/**
 * \file  OverloadingArithmeticOperatorUsingMemberFunction.cpp
 * \brief this function is a member function!
 *
 * \review
 *
 * The cents parameter in the friend version is now the implicit *this parameter
 */


#include <StdStream/StdStream.h>
#include <StdTest/StdTest.h>
#include <Stl.h>
//--------------------------------------------------------------------------------------------------
class Cents
{
public:
    Cents(int cents)
    {
        _cents = cents;
    }

    // Overload Cents + int
    Cents operator + (int value);

    int getCents()
    {
        return _cents;
    }

private:
    int _cents {};
};
//--------------------------------------------------------------------------------------------------
Cents
Cents::operator + (int value)
{
    return Cents(_cents + value);
}
//--------------------------------------------------------------------------------------------------
int main()
{
	Cents cents1(6);
	Cents cents2 = cents1 + 2;

	std::cout << "I have " << cents2.getCents() << " cents.\n";

    return EXIT_SUCCESS;
}
//--------------------------------------------------------------------------------------------------


#if OUTPUT

I have 8 cents.

#endif
