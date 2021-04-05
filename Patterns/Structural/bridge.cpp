/**
 * \file
 * \brief
 *
 * \todo
 */

/*
Bridge allows two implementations to vary independently.
In this case, the implementations of message and recipient are independent,
but combine to output "Hello world!"
*/

#include <iostream>
#include <string>

class Message
{
public:
	virtual ~Message() { }
	virtual void send_to(const std::string &)=0;
};

class Recipient
{
public:
	virtual ~Recipient() { }
	virtual void send(Message &)=0;
};

class Hello : public Message
{
public:
	void send_to(const std::string & name)
	{
		std::cout << "Hello " << name << "!" << std::endl;
	};
};

class World : public Recipient
{
public:
	void send(Message & msg)
	{
		msg.send_to("world");
	};
};

void hello_world(Message & msg, Recipient & recipient)
{
	recipient.send(msg);
}

int main()
{
	Hello hello;
	World world;
	hello_world(hello, world);
	return 0;
}
