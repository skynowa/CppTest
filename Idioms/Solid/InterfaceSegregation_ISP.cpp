/**
 * \file  InterfaceSegregation_ISP.cpp
 * \brief Separating the interfaces
 */


#include <StdStream/StdStream.h>
#include <StdTest/StdTest.h>
#include <Stl.h>
//--------------------------------------------------------------------------------------------------
class IPrinter
{
public:
	virtual ~IPrinter() = default;

	virtual void print(const std::string &a_text) = 0;
};
//--------------------------------------------------------------------------------------------------
class IScanner
{
public:
	virtual ~IScanner() = default;

	virtual std::string scan() = 0;
};
//--------------------------------------------------------------------------------------------------
class SimplePrinter :
	public IPrinter
{
public:
	void print(const std::string &a_text) override
	{
		std::cout << "print: " << a_text << std::endl;
	}
};
//--------------------------------------------------------------------------------------------------
class OfficeDevice :
	public IPrinter,
	public IScanner
{
public:
	void print(const std::string &a_text) override
	{
		std::cout << "office print: " << a_text << std::endl;
	}

	std::string scan() override
	{
		return "document";
	}
};
//--------------------------------------------------------------------------------------------------
int main(int, char **)
{
	SimplePrinter printer;
	OfficeDevice  officeDevice;

	printer.print("invoice");
	officeDevice.print(officeDevice.scan());

    return EXIT_SUCCESS;
}
//--------------------------------------------------------------------------------------------------


#if OUTPUT

print: invoice
office print: document

#endif
