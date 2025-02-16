/**
 * \file  TemplateMethod.cpp
 * \brief Template method provides an implementation in a derived class, to be used by the base class
 */


#include <StdStream/StdStream.h>
#include <StdTest/StdTest.h>
#include <Stl.h>
//-------------------------------------------------------------------------------------------------
class IHelloWorld
{
public:
	virtual ~IHelloWorld() = default;

	void output()
	{
		writeString("Hello world!");
		writeEndl();
	};

	virtual void writeString(const std::string &str) = 0;
	virtual void writeEndl() = 0;
};
//-------------------------------------------------------------------------------------------------
class HelloWorld_Impl :
    public IHelloWorld
{
public:
	void writeString(const std::string &str) final
	{
		std::cout << STD_TRACE_VAR(str);
	}

	void writeEndl() final
	{
		std::cout << std::endl;
	}
};
//-------------------------------------------------------------------------------------------------
int main(int, char **)
{
	HelloWorld_Impl hw;
	hw.output();

	return 0;
}
//-------------------------------------------------------------------------------------------------


#if 0

str: Hello world!

#endif
