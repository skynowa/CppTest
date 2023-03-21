/**
 * \file  Inheritance1.cpp
 * \brief Virtual inheritance
 */


#include <StdStream/StdStream.h>
#include <StdTest/StdTest.h>
#include <Stl.h>
//--------------------------------------------------------------------------------------------------
struct IInterface
{
             IInterface() { STD_TRACE_FUNC; };
    virtual ~IInterface() { STD_TRACE_FUNC; };

    virtual void foo() = 0;
};
//--------------------------------------------------------------------------------------------------
struct A :
    /* virtual */ IInterface
{
             A() { STD_TRACE_FUNC; };
    virtual ~A() { STD_TRACE_FUNC; };

    void foo() override { STD_TRACE_FUNC; };
};
//--------------------------------------------------------------------------------------------------
struct B :
    /* virtual */ IInterface
{
             B() { STD_TRACE_FUNC; };
    virtual ~B() { STD_TRACE_FUNC; };

    void foo() override { STD_TRACE_FUNC; };
};
//--------------------------------------------------------------------------------------------------
struct X final :
    A,
    B
{
     X() { STD_TRACE_FUNC; };
    ~X() final { STD_TRACE_FUNC; };

    void foo() final { STD_TRACE_FUNC; };
};
//--------------------------------------------------------------------------------------------------
int main(int, char **)
{
	//-------------------------------------
	{
		X x;
	}

    #if OUTPUT

        // without virtual inheritance
        IInterface::IInterface
        A::A
        IInterface::IInterface
        B::B
        X::X
        X::~X
        B::~B
        IInterface::~IInterface
        A::~A
        IInterface::~IInterface

    #endif

    #if OUTPUT

        // with virtual inheritance
        IInterface::IInterface
        A::A
        B::B
        X::X
        X::~X
        B::~B
        A::~A
        IInterface::~IInterface

    #endif

    std::cout << "-------------------------" << std::endl;

	//-------------------------------------
	{
		A *pI = new A();
		pI->foo();
		delete pI;
	}

    #if OUTPUT
        IInterface::IInterface
        A::A
        A::foo
        A::~A
        IInterface::~IInterface
    #endif

	std::cout << "-------------------------" << std::endl;

	//-------------------------------------
	{
		B *pI = new B();
		pI->foo();
		delete pI;
	}

    #if OUTPUT
        IInterface::IInterface
        B::B
        B::foo
        B::~B
        IInterface::~IInterface
    #endif

	std::cout << "-------------------------" << std::endl;

	//-------------------------------------
	{
		IInterface *pI = new A();
		pI->foo();
		delete pI;
	}

    #if OUTPUT
        IInterface::IInterface
        A::A
        A::foo
        A::~A
        IInterface::~IInterface
    #endif

	std::cout << "-------------------------" << std::endl;

	//-------------------------------------
	{
		IInterface *pI = new B();
		pI->foo();
		delete pI;
	}

    #if OUTPUT
        IInterface::IInterface
        B::B
        B::foo
        B::~B
        IInterface::~IInterface
    #endif

	std::cout << "-------------------------" << std::endl;

    return EXIT_SUCCESS;
}
//--------------------------------------------------------------------------------------------------


#if OUTPUT

IInterface
A
IInterface
B
X
~X
~B
~IInterface
~A
~IInterface
-------------------------
IInterface
A
foo
~A
~IInterface
-------------------------
IInterface
B
foo
~B
~IInterface
-------------------------
IInterface
A
foo
~A
~IInterface
-------------------------
IInterface
B
foo
~B
~IInterface
-------------------------

#endif
