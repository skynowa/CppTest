/**
 * \file  Builder.cpp
 * \brief Builder - responsible for constructing an object
 *
 * Builder is a class (or set of classes) responsible for constructing an object.
 * Each builder constructs a different part of the object.
 */


#include <StdStream.h>
#include <StdTest.h>
#include <Stl.h>
//-------------------------------------------------------------------------------------------------
class Message;

class IBuilder
{
public:
	virtual ~IBuilder() = default;

	virtual void build(Message & msg) const = 0;
};
//-------------------------------------------------------------------------------------------------
class Message
{
public:
	std::string greeting {};
	std::string recipient {};

	void send()
	{
		std::cout << greeting << " " << recipient << std::endl;
	}
};
//-------------------------------------------------------------------------------------------------
class Hello :
	public IBuilder
{
public:
	void build(Message &a_msg) const override
	{
		a_msg.greeting = "Hello";
	}
};
//-------------------------------------------------------------------------------------------------
class World :
	public IBuilder
{
public:
	void build(Message &a_msg) const override
	{
		a_msg.recipient = "world!";
	}
};
//-------------------------------------------------------------------------------------------------
void
hello_world(
	const IBuilder &a_stage1,
	const IBuilder &a_stage2
)
{
	Message msg;

	a_stage1.build(msg);
	a_stage2.build(msg);

	msg.send();
}
//-------------------------------------------------------------------------------------------------
int main()
{
	hello_world(Hello(), World());

	return EXIT_SUCCESS;
}
//-------------------------------------------------------------------------------------------------

#if OUTPUT

Hello world!

#endif
