/**
 * \file  Inheritance1.cpp
 * \brief
 *
 * \review
 */


#include <StdStream/StdStream.h>
#include <StdTest/StdTest.h>
#include <Stl.h>
//--------------------------------------------------------------------------------------------------
class IInterface
{
public:
             IInterface() { std::cout << __FUNCTION__ << std::endl; };
    virtual ~IInterface() { std::cout << __FUNCTION__ << std::endl; };

    virtual void vFoo() = 0;
};
//--------------------------------------------------------------------------------------------------
class A :
    public /* virtual */ IInterface
{
public:
             A() { std::cout << __FUNCTION__ << std::endl; };
    virtual ~A() { std::cout << __FUNCTION__ << std::endl; };

    virtual void vFoo() { std::cout << __FUNCTION__ << std::endl; };
};
//--------------------------------------------------------------------------------------------------
class B :
    public /* virtual */ IInterface
{
public:
             B() { std::cout << __FUNCTION__ << std::endl; };
    virtual ~B() { std::cout << __FUNCTION__ << std::endl; };

    virtual void vFoo() { std::cout << __FUNCTION__ << std::endl; };
};
//--------------------------------------------------------------------------------------------------
class X final :
    public A,
    public B
{
public:
     X() { std::cout << __FUNCTION__ << std::endl; };
    ~X() final { std::cout << __FUNCTION__ << std::endl; };

    void vFoo() final { std::cout << __FUNCTION__ << std::endl; };
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
		pI->vFoo();
		delete pI;
	}

    #if OUTPUT
        IInterface::IInterface
        A::A
        A::vFoo
        A::~A
        IInterface::~IInterface
    #endif

	std::cout << "-------------------------" << std::endl;

	//-------------------------------------
	{
		B *pI = new B();
		pI->vFoo();
		delete pI;
	}

    #if OUTPUT
        IInterface::IInterface
        B::B
        B::vFoo
        B::~B
        IInterface::~IInterface
    #endif

	std::cout << "-------------------------" << std::endl;

	//-------------------------------------
	{
		IInterface *pI = new A();
		pI->vFoo();
		delete pI;
	}

    #if OUTPUT
        IInterface::IInterface
        A::A
        A::vFoo
        A::~A
        IInterface::~IInterface
    #endif

	std::cout << "-------------------------" << std::endl;

	//-------------------------------------
	{
		IInterface *pI = new B();
		pI->vFoo();
		delete pI;
	}

    #if OUTPUT
        IInterface::IInterface
        B::B
        B::vFoo
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
vFoo
~A
~IInterface
-------------------------
IInterface
B
vFoo
~B
~IInterface
-------------------------
IInterface
A
vFoo
~A
~IInterface
-------------------------
IInterface
B
vFoo
~B
~IInterface
-------------------------

#endif
