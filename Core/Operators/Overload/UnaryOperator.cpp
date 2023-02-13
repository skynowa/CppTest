/**
 * \file  UnaryOperator.cpp
 * \brief
 *
 * \review
 *
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

    // Overload -Cents as a member function
    Cents operator-() const;

    int getCents() const
    {
        return _cents;
    }

private:
    int _cents {};
};
//--------------------------------------------------------------------------------------------------
Cents
Cents::operator - () const
{
	return Cents(- _cents);
}
//--------------------------------------------------------------------------------------------------
int main(int, char **)
{
	const Cents nickle(5);

	std::cout << "Nickle of debt is worth " << (- nickle).getCents() << " cents." << std::endl;

    return EXIT_SUCCESS;
}
//--------------------------------------------------------------------------------------------------


#if OUTPUT

Nickle of debt is worth -5 cents.

#endif
