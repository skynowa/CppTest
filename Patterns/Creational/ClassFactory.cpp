/**
 * \file  ClassFactory.cpp
 * \brief Class factory pattern is an object/method for creating other objects
 *
 * The class factory creates and returns new objects by instantiating various classes
 * (through the use of constructors). In most cases, a class factory has at most one method/function
 * that is given some type of incoming data and returns a new object (or pointer) to what was created
 */


#include <StdStream.h>
#include <StdTest.h>
#include <Stl.h>
//-------------------------------------------------------------------------------------------------
class ICar
{
public:
             ICar() = default;
	virtual ~ICar() = default;

	virtual void printName() = 0;
};
//-------------------------------------------------------------------------------------------------
class Ford :
	public ICar
{
public:
	void printName() override
	{
		std::cout << "Ford" << std::endl;
	}
};
//-------------------------------------------------------------------------------------------------
class Toyota :
	public ICar
{
public:
	void printName() override
	{
		std::cout << "Toyota" << std::endl;
	}
};
//-------------------------------------------------------------------------------------------------


//-------------------------------------------------------------------------------------------------
class IEngine
{
public:
             IEngine() = default;
	virtual ~IEngine() = default;

	virtual void printPower() = 0;
};
//-------------------------------------------------------------------------------------------------
class FordEngine :
	public IEngine
{
public:
	void printPower() override
	{
		std::cout << "Ford Engine 4.4" << std::endl;
	}
};
//-------------------------------------------------------------------------------------------------
class ToyotaEngine :
	public IEngine
{
public:
	void printPower() override
	{
		std::cout << "Toyota Engine 3.2" << std::endl;
	}
};
//-------------------------------------------------------------------------------------------------



//-------------------------------------------------------------------------------------------------
class ICarFactory
{
public:
	virtual ~ICarFactory() = default;

	virtual ICar*    createCar()    = 0;
	virtual IEngine* createEngine() = 0;
};
//-------------------------------------------------------------------------------------------------
class FordFactory :
	public ICarFactory
{
public:
	ICar* createCar() override
	{
		return new Ford();
	}

	IEngine* createEngine() override
	{
		return new FordEngine();
	}
};
//-------------------------------------------------------------------------------------------------
class ToyotaFactory :
	public ICarFactory
{
public:
	ICar* createCar() override
	{
		return new Toyota();
	}

	IEngine* createEngine() override
	{
		return new ToyotaEngine();
	}
};
//-------------------------------------------------------------------------------------------------
void use(ICarFactory *f)
{
	ICar    *myCar    = f->createCar();
	IEngine *myEngine = f->createEngine();

	myCar->printName();
	myEngine->printPower();

	delete myCar;
	delete myEngine;
}
//-------------------------------------------------------------------------------------------------
int main()
{
	ToyotaFactory toyotaFactory;
	FordFactory	  fordFactory;

	use(&toyotaFactory);
	use(&fordFactory);

	return 0;
}
//-------------------------------------------------------------------------------------------------
#if OUTPUT

	Toyota
	Toyota Engine 3.2
	Ford
	Ford Engine 4.4

#endif
