/**
 * \file  Prototype.cpp
 * \brief Prototype - object which is cloneable
 *
 * A Prototype is an object which is cloneable, i.e. you can create a copy,
 * even though you don't know what you are creating a copy of.
 */


#include <StdStream/StdStream.h>
#include <StdTest/StdTest.h>
#include <Stl.h>
//-------------------------------------------------------------------------------------------------
class ICloneable
{
public:
			 ICloneable() = default;
	virtual ~ICloneable() = default;

	virtual std::unique_ptr<ICloneable> clone() const = 0;
	virtual void test() = 0;
};
//-------------------------------------------------------------------------------------------------
class HelloWorld :
	public ICloneable
{
public:
	std::unique_ptr<ICloneable> clone() const override
	{
		return std::unique_ptr<ICloneable>(new HelloWorld);
	}

	void test() override
	{
		std::cout << "Hello world!" << std::endl;
	}
};
//-------------------------------------------------------------------------------------------------
int main(int, char **)
{
	HelloWorld hw;

	std::unique_ptr<ICloneable> hwClone = hw.clone();
	hwClone->test();

	return EXIT_SUCCESS;
}
//-------------------------------------------------------------------------------------------------

#if OUTPUT

Hello world!

#endif
