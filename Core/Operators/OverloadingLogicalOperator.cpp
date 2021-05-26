/**
 * \file  OverloadingLogicalOperator.cpp
 * \brief
 *
 * \review
 *
 * The comparison operators are all binary operators that do not modify their left operands,
 * we will make our overloaded comparison operators friend functions.
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

	friend bool operator >  (const Cents &c1, const Cents &c2);
	friend bool operator <  (const Cents &c1, const Cents &c2);
	friend bool operator >= (const Cents &c1, const Cents &c2);
	friend bool operator <= (const Cents &c1, const Cents &c2);

private:
	int _cents {};
};
//--------------------------------------------------------------------------------------------------
bool
operator > (const Cents &c1, const Cents &c2)
{
	return c1._cents > c2._cents;
}
//--------------------------------------------------------------------------------------------------
bool
operator < (const Cents &c1, const Cents &c2)
{
	return c1._cents < c2._cents;
}
//--------------------------------------------------------------------------------------------------
bool
operator >= (const Cents &c1, const Cents &c2)
{
	return c1._cents >= c2._cents;
}
//--------------------------------------------------------------------------------------------------
bool
operator <= (const Cents &c1, const Cents &c2)
{
	return c1._cents <= c2._cents;
}
//--------------------------------------------------------------------------------------------------
int main()
{
    Cents dime(10);
    Cents nickle(5);

    if (nickle > dime)
        std::cout << "a nickle is greater than a dime.\n";

    if (nickle >= dime)
        std::cout << "a nickle is greater than or equal to a dime.\n";

    if (nickle < dime)
        std::cout << "a dime is greater than a nickle.\n";

    if (nickle <= dime)
        std::cout << "a dime is greater than or equal to a nickle.\n";

    return EXIT_SUCCESS;
}
//--------------------------------------------------------------------------------------------------


#if OUTPUT

a dime is greater than a nickle.
a dime is greater than or equal to a nickle.

#endif
