/**
 * \file  ConstructOrder.cpp
 * \brief Construct order
 */


#include <StdStream/StdStream.h>
#include <StdTest/StdTest.h>
#include <Stl.h>
//-------------------------------------------------------------------------------------------------
class Base1
{
public:
	Base1()	 { STD_TRACE_FUNC; }
	~Base1() { STD_TRACE_FUNC; }
};
//-------------------------------------------------------------------------------------------------
class Base2
{
public:
	Base2()	 { STD_TRACE_FUNC; }
	~Base2() { STD_TRACE_FUNC; }
};
//-------------------------------------------------------------------------------------------------
class Field
{
public:
	explicit Field(std::string a_name) :
		_name{a_name}
	{
		std::cout << "\t\tField: " << _name << std::endl;
	}

	~Field()
	{
		std::cout << "\t\t~Field: " << _name << std::endl;
	}

private:
	const std::string _name;
};
//-------------------------------------------------------------------------------------------------
class A :
	public Base1,
	public Base2
{
public:
	const Field f1{"f1"};
	const Field f2{"f2"};
	const Field f3{"f3"};

	static const Field fs;								///< static as 2-nd
	static const inline Field fsi {"f_static_inline"};	///< static as 1-st

	A()	 { STD_TRACE_FUNC; }
	~A() { STD_TRACE_FUNC; }
};

/* static */ const Field A::fs{"f_static"};
//-------------------------------------------------------------------------------------------------
int main(int, char **)
{
	{
		A a;
	}

	return EXIT_SUCCESS;
}
//-------------------------------------------------------------------------------------------------


#if OUTPUT

	Field: f_static_inline
	Field: f_static
::: Base1 :::
::: Base2 :::
	Field: f1
	Field: f2
	Field: f3
::: A :::
::: ~A :::
	~Field: f3
	~Field: f2
	~Field: f1
::: ~Base2 :::
::: ~Base1 :::
	~Field: f_static

#endif
