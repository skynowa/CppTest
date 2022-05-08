/**
 * \file  Facade.cpp
 * \brief Wrap / simplify complex behaviour
 *
 * Facade hides a lot of complex behaviour behind a simple, single interface.
 * It puts a shop-front on an otherwise complex set of classes.
 */


#include <StdStream/StdStream.h>
#include <StdTest/StdTest.h>
#include <Stl.h>
//--------------------------------------------------------------------------------------------------
class IHelloWorld
{
public:
	virtual ~IHelloWorld() = default;

	virtual std::string hello() = 0;
	virtual std::string world() = 0;

	virtual void output(const std::string &) = 0;
	virtual void endl() = 0;
};
//--------------------------------------------------------------------------------------------------
class HelloWorldImpl :
	public IHelloWorld
{
public:
	std::string hello() override
	{
		return "Hello";
	}

	std::string world() override
	{
		return "world";
	}

	void output(const std::string & str) override
	{
		std::cout << str;
	}

	void endl() override
	{
		std::cout << std::endl;
	}
};
//--------------------------------------------------------------------------------------------------
int main()
{
	HelloWorldImpl hw;

	hw.output( hw.hello() );
	hw.output(" ");
	hw.output( hw.world() );
	hw.output("!");
	hw.endl();

	return 0;
}
//--------------------------------------------------------------------------------------------------

#if OUTPUT

Hello world!

#endif
