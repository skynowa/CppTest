/**
 * \file  FactoryMethod.cpp
 * \brief Factory method - creates object in a derived class
 *
 * \todo
 * Factory method creates some object (in this case a string) in a derived class,
 * for use in a base class.
 */


#include <StdStream.h>
#include <StdTest.h>
#include <Stl.h>
//-------------------------------------------------------------------------------------------------
class IGreeter
{
public:
    virtual ~IGreeter() = default;

    virtual std::string message() const = 0;

    void run() const
    {
        std::cout << message() << std::endl;
    }
};
//-------------------------------------------------------------------------------------------------
class HelloWorld :
    public IGreeter
{
public:
    std::string message() const
    {
        return "Hello world!"s;
    }
};
//-------------------------------------------------------------------------------------------------
void
helloWorld(
    const IGreeter &a_greeter
)
{
	a_greeter.run();
}
//-------------------------------------------------------------------------------------------------
int main()
{
	HelloWorld greeter;
	::helloWorld(greeter);

	return EXIT_SUCCESS;
}
//-------------------------------------------------------------------------------------------------


#if OUTPUT

Hello world!

#endif
