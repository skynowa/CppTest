/**
 * \file  Dry.cpp
 * \brief DRY - Don't repeat yourself
 */


#include <StdStream/StdStream.h>
#include <StdTest/StdTest.h>
#include <Stl.h>
//--------------------------------------------------------------------------------------------------
double priceWithTax(double a_price, double a_taxRate)
{
	return a_price * (1.0 + a_taxRate);
}
//--------------------------------------------------------------------------------------------------
void printPrice(const std::string &a_name, double a_price, double a_taxRate)
{
	std::cout << a_name << ": " << priceWithTax(a_price, a_taxRate) << std::endl;
}
//--------------------------------------------------------------------------------------------------
int main(int, char **)
{
	const double taxRate {0.2};

	printPrice("book", 10.0, taxRate);
	printPrice("pen", 2.5, taxRate);

    return EXIT_SUCCESS;
}
//--------------------------------------------------------------------------------------------------


#if OUTPUT

book: 12
pen: 3

#endif
