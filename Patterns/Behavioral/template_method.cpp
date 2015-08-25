/*
Template method provides an implementation in a derived class,
to be used by the base class.
*/

#include <string>
#include <iostream>

//-------------------------------------------------------------------------------------------------
class IHelloWorld
{
public:
	virtual ~IHelloWorld() { }

	void output()
	{
		writeString("Hello world!");
		writeEndl();
	};

	virtual void writeString(const std::string &str) = 0;
	virtual void writeEndl() = 0;
};
//-------------------------------------------------------------------------------------------------
class HelloWorld_Impl : public IHelloWorld
{
public:
	virtual void writeString(const std::string &str)
	{
		std::cout << str;
	}

	virtual void writeEndl()
	{
		std::cout << std::endl;
	}
};
//-------------------------------------------------------------------------------------------------
int main()
{
	HelloWorld_Impl hw;
	hw.output();

	return 0;
}
//-------------------------------------------------------------------------------------------------
