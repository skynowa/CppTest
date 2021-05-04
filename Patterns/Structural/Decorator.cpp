/**
 * \file  Decorator.cpp
 * \brief Decorator adds / overrides functionality of a class
 *
 * \review
 *
 * Unlike normal inheritance, decorator overrides behaviour of a derived class, not a base class
 */


#include <StdStream.h>
#include <StdTest.h>
#include <Stl.h>
//--------------------------------------------------------------------------------------------------
class IGreeting
{
public:
	virtual ~IGreeting() = default;

	virtual std::string greeting() const = 0;
};
//--------------------------------------------------------------------------------------------------
class Exclamation :
	public IGreeting
{
public:
	Exclamation(const IGreeting &a_greeting) :
		_greeting(a_greeting)
	{
	}

	std::string greeting() const override
	{
		return _greeting.greeting() + "!";
	}

private:
	const IGreeting &_greeting;
};
//--------------------------------------------------------------------------------------------------
class HelloWorld :
	public IGreeting
{
public:
	std::string greeting() const override
	{
		return "Hello world";
	}
};
//--------------------------------------------------------------------------------------------------
int main()
{
	HelloWorld hw;
	Exclamation exclamation(hw);

	std::cout << TRACE_VAR(exclamation.greeting()) << std::endl;

	return 0;
}
//--------------------------------------------------------------------------------------------------

#if OUTPUT

exclamation.greeting(): Hello world!

#endif