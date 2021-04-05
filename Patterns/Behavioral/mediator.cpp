/**
 * \file
 * \brief
 *
 * \todo
 */

/*
Mediator binds different classes together,
and the individual classes communicate via the mediator, never directly.
In this example,  Message::print() calls Mediator, not Printer directly.
*/

#include <iostream>
#include <string>

//-------------------------------------------------------------------------------------------------
class Printer
{
public:
	void print(const std::string &str) const
	{
		std::cout << __FUNCTION__ << ": " << str << std::endl;
	}
};
//-------------------------------------------------------------------------------------------------
class Message
{
public:
	virtual ~Message() { }
	virtual void print(const class Mediator &mediator) const;
};
//-------------------------------------------------------------------------------------------------
class Mediator
{
public:
	Mediator(const Printer &p, const Message &m) :
		printer(p),
		message(m)
	{
	}

	void messagePrint() const
	{
		message.print(*this);
	}

	void printerPrint(const std::string &str) const
	{
		printer.print(str);
	}

private:
	const Printer &printer;
	const Message &message;
};
//-------------------------------------------------------------------------------------------------
void Message::print(const Mediator &mediator) const
{
	mediator.printerPrint("AAA");
}
//-------------------------------------------------------------------------------------------------
int main()
{
	Printer printer;
	Message message;

	Mediator mediator(printer, message);
	mediator.messagePrint();
	mediator.printerPrint("BBB");

	return 0;
}
//-------------------------------------------------------------------------------------------------
