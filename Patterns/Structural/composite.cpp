/**
 * \file
 * \brief
 *
 * \todo
 */

/*
Composite combines several classes into a single class.
*/

#include <iostream>
#include <string>

class Greeting
{
public:
	virtual ~Greeting() { }
	virtual std::string get_greeting()=0;
};

class Recipient
{
public:
	virtual ~Recipient() { }
	virtual std::string get_recipient()=0;
};

class Composite
{
	Greeting & greeting;
	Recipient & recipient;
public:
	Composite(Greeting & greeting, Recipient & recipient) :
	    greeting(greeting),
		recipient(recipient) { }
	void greet() const
	{
		std::cout << greeting.get_greeting() << " "
			<< recipient.get_recipient() << "!" << std::endl;
	}
};

class Hello : public Greeting
{
public:
	std::string get_greeting() { return "Hello"; }
};

class World : public Recipient
{
public:
	std::string get_recipient() { return "world"; }
};

void hello_world(const Composite & composite)
{
	composite.greet();
}

int main()
{
	Hello hello;
	World world;
	hello_world(Composite(hello, world));
	return 0;
}
