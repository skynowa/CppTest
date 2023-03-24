/**
 * \file  InheritanceFunctions.cpp
 * \brief Call derived methods
 */


#include <StdStream/StdStream.h>
#include <StdTest/StdTest.h>
#include <Stl.h>
//--------------------------------------------------------------------------------------------------
class I
{
public:
			 I() { STD_TRACE_FUNC; }
	virtual ~I() { STD_TRACE_FUNC; }

	virtual void foo() { std::cout << "\tI::foo()" << std::endl; }
};
//--------------------------------------------------------------------------------------------------
class A :
	public I
{
public:
			 A() { STD_TRACE_FUNC; }
	virtual ~A() { STD_TRACE_FUNC; }

	void foo() override { std::cout << "\tA::foo()" << std::endl; }
};
//--------------------------------------------------------------------------------------------------
class B :
	public I
{
public:
			 B() { STD_TRACE_FUNC; }
	virtual ~B() { STD_TRACE_FUNC; }

	void foo() override { std::cout << "\tB::foo()" << std::endl; }
};
//--------------------------------------------------------------------------------------------------
class AB :
	public A,
	public B
{
public:
			 AB() { STD_TRACE_FUNC; }
	virtual ~AB() { STD_TRACE_FUNC; }

	void foo() override { std::cout << "\tAB::foo()" << std::endl; }
};
//--------------------------------------------------------------------------------------------------
int main(int, char **)
{
	{
		std::cout << "-------------- I ----------------" << std::endl;

		I *i = new I();
		i->foo();
		delete i;
	}

	{
		std::cout << "-------------- A ----------------" << std::endl;

		I *b = new A();
		b->foo();
		delete b;

	}

	{
		std::cout << "-------------- B ----------------" << std::endl;

		I *c = new B();
		c->foo();
		delete c;
	}

	{
		std::cout << "-------------- AB ----------------" << std::endl;

	#if 0
		I *ab = new AB(); // error: ‘I’ is an ambiguous base of ‘AB’
		ab->foo();
		delete ab;
	#endif
	}

	return EXIT_SUCCESS;
}
//--------------------------------------------------------------------------------------------------

#if OUTPUT

-------------- I ----------------
	::: I :::
	I::foo()
	::: ~I :::
-------------- A ----------------
	::: I :::
	::: A :::
	A::foo()
	::: ~A :::
	::: ~I :::
-------------- B ----------------
	::: I :::
	::: B :::
	B::foo()
	::: ~B :::
	::: ~I :::

#endif
