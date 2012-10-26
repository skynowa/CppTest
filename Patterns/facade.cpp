/*
Facade hides a lot of complex behaviour behind a simple, single interface.  
It puts a shop-front on an otherwise complex set of classes.
*/

#include <string>
#include <iostream>

class HelloWorld
{
public:
	virtual ~HelloWorld() { }
	virtual std::string hello()=0;
	virtual std::string world()=0;
	virtual void output(const std::string&)=0;
	virtual void endl()=0;
};

class HelloWorldImpl : public HelloWorld
{
public:
	std::string hello() { return "Hello"; }
	std::string world() { return "world"; }
	void output(const std::string & str)
	{
		std::cout << str;
	}
	void endl()
	{
		std::cout << std::endl;
	}
};

void hello_world(HelloWorld & hw)
{
	hw.output(hw.hello());
	hw.output(" ");
	hw.output(hw.world());
	hw.output("!");
	hw.endl();
}

int main()
{
	HelloWorldImpl hw;
	hello_world(hw);
	return 0;
}

