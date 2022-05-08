/**
 * \file  FactoryMethod.cpp
 * \brief Factory method - creates object in a derived class
 *
 * Factory method creates some object (in this case a string) in a derived class,
 * for use in a base class.
 */


#include <StdStream/StdStream.h>
#include <StdTest/StdTest.h>
#include <Stl.h>
//-------------------------------------------------------------------------------------------------
class IMessage
{
public:
    virtual ~IMessage() = default;

    virtual std::string message() const = 0;

    void run() const
    {
        std::cout << message() << std::endl;
    }
};
//-------------------------------------------------------------------------------------------------
class HelloWorld :
    public IMessage
{
public:
    std::string message() const override
    {
        return "Hello world!";
    }
};
//-------------------------------------------------------------------------------------------------
int main()
{
	HelloWorld greeter;
	greeter.run();

	return EXIT_SUCCESS;
}
//-------------------------------------------------------------------------------------------------


#if OUTPUT

Hello world!

#endif
