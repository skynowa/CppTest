/**
 * \file  SingleResponsibility_SRP.cpp
 * \brief class should do one thing
 *
 * Demonstrates separating report formatting from console output.
 */


#include <StdStream/StdStream.h>
#include <StdTest/StdTest.h>
#include <Stl.h>
//--------------------------------------------------------------------------------------------------
struct Report
{
	std::string title;
	std::string body;
};
//--------------------------------------------------------------------------------------------------
class ReportFormatter
{
public:
	std::string format(const Report &a_report) const
	{
		return a_report.title + ": " + a_report.body;
	}
};
//--------------------------------------------------------------------------------------------------
class ConsolePrinter
{
public:
	void print(const std::string &a_text) const
	{
		std::cout << a_text << std::endl;
	}
};
//--------------------------------------------------------------------------------------------------
int main(int, char **)
{
	const Report report {"SRP", "formatting and printing are separate responsibilities"};

	const ReportFormatter formatter;
	const ConsolePrinter   printer;

	printer.print(formatter.format(report));

    return EXIT_SUCCESS;
}
//--------------------------------------------------------------------------------------------------


#if OUTPUT

SRP: formatting and printing are separate responsibilities

#endif
