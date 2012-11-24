/*
An abstract factory is used to create objects.  
However you want to change what object is created.
*/


#include <iostream>
#include <string>
#include <memory>
//---------------------------------------------------------------------------
class IMessage {
    public:
        virtual ~IMessage() { }
        virtual std::string get_message()=0;
};
//---------------------------------------------------------------------------
class IMessageFactory {
    public:
        virtual ~IMessageFactory() { }
        virtual std::auto_ptr<IMessage> create_message() const=0;
};
//---------------------------------------------------------------------------
class CHelloWorldMessage : 
    public IMessage 
{
    public:
        std::string get_message() {
            return "Hello world!";
        }
};
//---------------------------------------------------------------------------
class CHelloWorldFactory : 
    public IMessageFactory 
{
    public:
        std::auto_ptr<IMessage> create_message() const {
            return std::auto_ptr<IMessage>(new CHelloWorldMessage());
        }
};
//---------------------------------------------------------------------------
void 
hello_world(
    const IMessageFactory & factory
)
{
	std::auto_ptr<IMessage> message = factory.create_message();
	std::cout << message->get_message() << std::endl;
}
//---------------------------------------------------------------------------
int main()
{
	hello_world(CHelloWorldFactory());
    
	return 0;
}
//---------------------------------------------------------------------------


#if OUTPUT

    Hello world!
    
#endif
