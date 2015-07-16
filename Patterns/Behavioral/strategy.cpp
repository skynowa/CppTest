/*
Strategy is an algorithm that you pass into a function or class that uses the strategy.  
The idea is that you can provide a different strategy to achieve something different.
*/

#include <iostream>
#include <string>

class Strategy
{
public:
	virtual ~Strategy() { }
	virtual std::string format(const std::string &, const std::string &) const=0;
};

class Formatter : public Strategy
{
public:
	std::string format(const std::string & s1, const std::string & s2) const
	{
		return s1 + " " + s2 + "!";
	}
};

void hello_world(const Strategy & strategy)
{
	std::cout << strategy.format("Hello", "world") << std::endl;
}

int main()
{
	hello_world(Formatter());
	return 0;
}
