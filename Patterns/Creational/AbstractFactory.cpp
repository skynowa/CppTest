/*
An abstract factory is used to create objects.
However you want to change what object is created.
*/


#include <iostream>
#include <string>
#include <memory>
//-------------------------------------------------------------------------------------------------
class IMessage
{
public:
    virtual ~IMessage() = default;
    virtual std::string get() = 0;
};
//-------------------------------------------------------------------------------------------------
class CMessageA :
    public IMessage
{
public:
    virtual std::string get()
    {
        return "Hello world!";
    }
};
//-------------------------------------------------------------------------------------------------
class IMessageFactory
{
public:
    virtual ~IMessageFactory() = default;
    virtual std::auto_ptr<IMessage> create_message() const = 0;
};
//-------------------------------------------------------------------------------------------------
class CMessageFactoryA :
    public IMessageFactory
{
public:
    virtual std::auto_ptr<IMessage> create_message() const
    {
        return std::auto_ptr<IMessage>(new CMessageA());
    }
};
//-------------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------------
void
hello_world(
    const IMessageFactory &factory
)
{
	std::auto_ptr<IMessage> message = factory.create_message();

	std::cout << message->get() << std::endl;
}
//-------------------------------------------------------------------------------------------------
int main()
{
	hello_world( CMessageFactoryA() );

	return 0;
}
//-------------------------------------------------------------------------------------------------


#if OUTPUT

    Hello world!

#endif
