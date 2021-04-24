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
class Message
{
public:
	std::string hello {};
	std::string world {};

	void send() const
	{
		std::cout << hello << " " << world << std::endl;
	}
};
//-------------------------------------------------------------------------------------------------
class IBuilderMessage
{
public:
	virtual ~IBuilderMessage() = default;

	virtual void update(Message *out_msg) const = 0;
};
//-------------------------------------------------------------------------------------------------


//-------------------------------------------------------------------------------------------------
class BuilderHello :
	public IBuilderMessage
{
public:
	void update(Message *out_msg) const override
	{
		out_msg->hello = "Hello";
	}
};
//-------------------------------------------------------------------------------------------------
class BuilderWorld :
	public IBuilderMessage
{
public:
	void update(Message *out_msg) const override
	{
		out_msg->world = "world!";
	}
};
//-------------------------------------------------------------------------------------------------
void
helloWorld(
	const IBuilderMessage &a_builder1,
	const IBuilderMessage &a_builder2
)
{
	Message msg;

	a_builder1.update(&msg);
	a_builder2.update(&msg);

	msg.send();
}
//-------------------------------------------------------------------------------------------------
int main()
{
	helloWorld(BuilderHello(), BuilderWorld());

	return EXIT_SUCCESS;
}
//-------------------------------------------------------------------------------------------------

#if OUTPUT

Hello world!

#endif
