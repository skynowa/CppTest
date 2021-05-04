/**
 * \file  Composite.cpp
 * \brief Composite combines several classes into a single class.
 */


#include <StdStream.h>
#include <StdTest.h>
#include <Stl.h>
//--------------------------------------------------------------------------------------------------
class IGreeting
{
public:
	virtual ~IGreeting() = default;

	virtual std::string get() const = 0;
};
//--------------------------------------------------------------------------------------------------
class IRecipient
{
public:
	virtual ~IRecipient() = default;

	virtual std::string get() const = 0;
};
//--------------------------------------------------------------------------------------------------
class Hello :
	public IGreeting
{
public:
	std::string get() const override
	{
		return "Hello";
	}
};
//--------------------------------------------------------------------------------------------------
class World :
	public IRecipient
{
public:
	std::string get() const override
	{
		return "world";
	}
};
//--------------------------------------------------------------------------------------------------
class Composite
{
public:
	Composite(IGreeting &a_greeting, IRecipient &a_recipient) :
	    _greeting (a_greeting),
		_recipient(a_recipient)
	{
	}

	void greet() const
	{
		std::cout
			<< _greeting.get() << " "
			<< _recipient.get() << "!"
			<< std::endl;
	}

private:
	IGreeting  &_greeting;
	IRecipient &_recipient;
};
//--------------------------------------------------------------------------------------------------
int main()
{
	Hello hello;
	World world;

	Composite composite(hello, world);
	composite.greet();

	return 0;
}
//--------------------------------------------------------------------------------------------------

#if OUTPUT

Hello world!

#endif
