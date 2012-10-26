/*
Factory method creates some object (in this case a string) in a derived class, 
for use in a base class.
*/


#include <iostream>
#include <string>

class Greeter
{
public:
	virtual ~Greeter() { }
	virtual std::string get_message()=0;
	void greet()
	{
		std::cout << get_message() << std::endl;
	}
};

class HelloWorld : public Greeter
{
public:
	std::string get_message()
	{
		return "Hello world!";
	}
};

void hello_world(Greeter & greeter)
{
	greeter.greet();
}

int main()
{
	HelloWorld greeter;
	hello_world(greeter);
	return 0;
}
