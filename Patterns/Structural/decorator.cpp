/**
 * \file
 * \brief
 *
 * \todo
 */

/*
Decorator adds or overrides functionality of a class.
Unlike normal inheritance, decorator overrides behaviour
of a derived class, not a base class.
*/


#include <iostream>
#include <string>

class Greeting
{
public:
	virtual ~Greeting() { }
	virtual std::string get_greeting() const=0;
};

class Exclamation : public Greeting
{
	const Greeting & greeting;
public:
	Exclamation(const Greeting & gr) : greeting(gr) { }
	std::string get_greeting() const
	{
		return greeting.get_greeting() + "!";
	}
};

class HelloWorld : public Greeting
{
public:
	std::string get_greeting() const
	{
		return "Hello world";
	}
};

void hello_world(const Greeting & greeting)
{
	std::cout << greeting.get_greeting() << std::endl;
}

int main()
{
	HelloWorld hw;
	hello_world(Exclamation(hw));
	return 0;
}
