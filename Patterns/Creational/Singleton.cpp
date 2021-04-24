/**
 * \file  Singleton.cpp
 * \brief Singleton - only one instance of a class
 *
 * Singleton ensures that there is one, and only one instance of a class.
 * Like global variables, everybody has access to that instance.
 * Singleton should be used sparingly since the assumption that
 * there should be just one of something usually ends up being wrong.
 * Singleton is hard to write unit tests with.
 */


#include <StdStream.h>
#include <StdTest.h>
#include <Stl.h>
//-------------------------------------------------------------------------------------------------
class HelloWorld
{
public:
	void test()
	{
		std::cout << "Hello world!" << std::endl;
	}

	static HelloWorld & get()
	{
		static HelloWorld singleton;
		return singleton;
	}

private:
	HelloWorld() = default;
	HelloWorld(const HelloWorld &);
};
//-------------------------------------------------------------------------------------------------
void
helloWorld()
{
	HelloWorld::get().test();
}
//-------------------------------------------------------------------------------------------------
int main()
{
	::helloWorld();

	return EXIT_SUCCESS;
}
//-------------------------------------------------------------------------------------------------


#if OUTPUT

Hello world!

#endif
