/**
 * \file  Bridge.cpp
 * \brief Bridge allows two implementations to vary independently
 *
 * \remark
 *
 * In this case, the implementations of message and recipient are independent,
 * but combine to output "Hello world!"
 */


#include <StdStream.h>
#include <StdTest.h>
#include <Stl.h>
//--------------------------------------------------------------------------------------------------
class IMessage
{
public:
	virtual ~IMessage() = default;

	virtual void sendTo(const std::string &) = 0;
};
//--------------------------------------------------------------------------------------------------
class Hello :
	public IMessage
{
public:
	void sendTo(const std::string &a_name) override
	{
		std::cout << "Hello " << a_name << "!" << std::endl;
	};
};
//--------------------------------------------------------------------------------------------------

//--------------------------------------------------------------------------------------------------
class IRecipient
{
public:
	virtual ~IRecipient() = default;

	virtual void send(IMessage &) = 0;
};
//--------------------------------------------------------------------------------------------------
class World :
	public IRecipient
{
public:
	void send(IMessage &a_msg) override
	{
		a_msg.sendTo("world");
	};
};
//--------------------------------------------------------------------------------------------------
int main()
{
	Hello hello;
	World world;

	world.send(hello);

	return 0;
}
//--------------------------------------------------------------------------------------------------

#if OUTPUT

Hello world!

#endif
