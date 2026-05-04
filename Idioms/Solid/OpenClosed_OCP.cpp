/**
 * \file  OpenClosed_OCP.cpp
 * \brief Classes should be open for extension and closed to modification
 */


#include <StdStream/StdStream.h>
#include <StdTest/StdTest.h>
#include <Stl.h>
//--------------------------------------------------------------------------------------------------
class Discount
{
public:
	virtual ~Discount() = default;

	virtual double apply(double a_price) const = 0;
};
//--------------------------------------------------------------------------------------------------
class RegularDiscount :
	public Discount
{
public:
	double apply(double a_price) const override
	{
		return a_price;
	}
};
//--------------------------------------------------------------------------------------------------
class PremiumDiscount :
	public Discount
{
public:
	double apply(double a_price) const override
	{
		return a_price * 0.8;
	}
};
//--------------------------------------------------------------------------------------------------
class PriceCalculator
{
public:
	double total(double a_price, const Discount &a_discount) const
	{
		return a_discount.apply(a_price);
	}
};
//--------------------------------------------------------------------------------------------------
int main(int, char **)
{
	const PriceCalculator calculator;
	const RegularDiscount regular;
	const PremiumDiscount premium;

	std::cout << STD_TRACE_VAR(calculator.total(100.0, regular)) << std::endl;
	std::cout << STD_TRACE_VAR(calculator.total(100.0, premium)) << std::endl;

    return EXIT_SUCCESS;
}
//--------------------------------------------------------------------------------------------------


#if OUTPUT

calculator.total(100.0, regular): 100
calculator.total(100.0, premium): 80

#endif
