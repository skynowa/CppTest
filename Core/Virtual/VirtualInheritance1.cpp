/**
 * \file  VirtualInheritance1.cpp
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
class CA :
    public /* virtual */ IInterface
{
public:
             CA() { std::cout << __FUNCTION__ << std::endl; };
    virtual ~CA() { std::cout << __FUNCTION__ << std::endl; };

    virtual void vFoo() { std::cout << __FUNCTION__ << std::endl; };
};
//--------------------------------------------------------------------------------------------------
class CB :
    public /* virtual */ IInterface
{
public:
             CB() { std::cout << __FUNCTION__ << std::endl; };
    virtual ~CB() { std::cout << __FUNCTION__ << std::endl; };

    virtual void vFoo() { std::cout << __FUNCTION__ << std::endl; };
};
//--------------------------------------------------------------------------------------------------
class CX :
    public CA,
    public CB
{
public:
             CX() { std::cout << __FUNCTION__ << std::endl; };
    virtual ~CX() { std::cout << __FUNCTION__ << std::endl; };

    virtual void vFoo() { std::cout << __FUNCTION__ << std::endl; };
};
//--------------------------------------------------------------------------------------------------
int main(int, char **)
{
	//-------------------------------------
	{
		CX x;
	}

    #if OUTPUT

        // without virtual inheritance
        IInterface::IInterface
        CA::CA
        IInterface::IInterface
        CB::CB
        CX::CX
        CX::~CX
        CB::~CB
        IInterface::~IInterface
        CA::~CA
        IInterface::~IInterface

    #endif

    #if OUTPUT

        // with virtual inheritance
        IInterface::IInterface
        CA::CA
        CB::CB
        CX::CX
        CX::~CX
        CB::~CB
        CA::~CA
        IInterface::~IInterface

    #endif

    std::cout << "-------------------------" << std::endl;

	//-------------------------------------
	{
		CA *pI = new CA();
		pI->vFoo();
		delete pI;
	}

    #if OUTPUT
        IInterface::IInterface
        CA::CA
        CA::vFoo
        CA::~CA
        IInterface::~IInterface
    #endif

	std::cout << "-------------------------" << std::endl;

	//-------------------------------------
	{
		CB *pI = new CB();
		pI->vFoo();
		delete pI;
	}

    #if OUTPUT
        IInterface::IInterface
        CB::CB
        CB::vFoo
        CB::~CB
        IInterface::~IInterface
    #endif

	std::cout << "-------------------------" << std::endl;

	//-------------------------------------
	{
		IInterface *pI = new CA();
		pI->vFoo();
		delete pI;
	}

    #if OUTPUT
        IInterface::IInterface
        CA::CA
        CA::vFoo
        CA::~CA
        IInterface::~IInterface
    #endif

	std::cout << "-------------------------" << std::endl;

	//-------------------------------------
	{
		IInterface *pI = new CB();
		pI->vFoo();
		delete pI;
	}

    #if OUTPUT
        IInterface::IInterface
        CB::CB
        CB::vFoo
        CB::~CB
        IInterface::~IInterface
    #endif

	std::cout << "-------------------------" << std::endl;

    return EXIT_SUCCESS;
}
//--------------------------------------------------------------------------------------------------


#if OUTPUT

IInterface
CA
IInterface
CB
CX
~CX
~CB
~IInterface
~CA
~IInterface
-------------------------
IInterface
CA
vFoo
~CA
~IInterface
-------------------------
IInterface
CB
vFoo
~CB
~IInterface
-------------------------
IInterface
CA
vFoo
~CA
~IInterface
-------------------------
IInterface
CB
vFoo
~CB
~IInterface
-------------------------


#endif
