/*
A Prototype is an object which is cloneable, i.e. you can create a copy,
even though you don't know what you are creating a copy of.
*/

#include <iostream>
#include <memory>
//-------------------------------------------------------------------------------------------------
class DoSomething
{
public:
	virtual ~DoSomething() { }
	virtual std::auto_ptr<DoSomething> clone() const=0;
	virtual void do_it()=0;
};
//-------------------------------------------------------------------------------------------------
class HelloWorld : public DoSomething
{
public:
	std::auto_ptr<DoSomething> clone() const
	{
		return std::auto_ptr<DoSomething>(new HelloWorld);
	}
	void do_it()
	{
		std::cout << "Hello world!" << std::endl;
	}
};
//-------------------------------------------------------------------------------------------------
void hello_world(const DoSomething & something)
{
	std::auto_ptr<DoSomething> clone = something.clone();
	clone->do_it();
}
//-------------------------------------------------------------------------------------------------
int main()
{
	hello_world(HelloWorld());
	return 0;
}
//-------------------------------------------------------------------------------------------------
