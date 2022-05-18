/**
 * \file  AbstractFactory.cpp
 * \brief An abstract factory is used to create objects
 *
 * However you want to change what object is created
 */


#include <StdStream/StdStream.h>
#include <StdTest/StdTest.h>
#include <Stl.h>
//-------------------------------------------------------------------------------------------------
class IMessage
{
public:
    virtual ~IMessage() = default;

    virtual std::string get() = 0;
};
//-------------------------------------------------------------------------------------------------
class MsgA :
    public IMessage
{
public:
    std::string get() override
    {
        return "Hello world!";
    }
};
//-------------------------------------------------------------------------------------------------
class IMessageFactory
{
public:
    virtual ~IMessageFactory() = default;

    virtual std::unique_ptr<IMessage> create() const = 0;
};
//-------------------------------------------------------------------------------------------------
class MsgFactoryA :
    public IMessageFactory
{
public:
    std::unique_ptr<IMessage> create() const override
    {
        return std::unique_ptr<IMessage>(new MsgA());
    }
};
//-------------------------------------------------------------------------------------------------
int main()
{
    MsgFactoryA factory;
	std::unique_ptr<IMessage> msg = factory.create();

	std::cout << STD_TRACE_VAR(msg->get()) << std::endl;

	return 0;
}
//-------------------------------------------------------------------------------------------------


#if OUTPUT

    Hello world!

#endif
