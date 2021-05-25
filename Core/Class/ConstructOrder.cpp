/**
 * \file  ConstructOrder.cpp
 * \brief Construct order
 */


#include <StdStream.h>
#include <StdTest.h>
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
	explicit Field(const std::string &a_name) :
		_name{a_name}
	{
		std::cout << "\t\tField: " << _name << std::endl;
	}

	~Field()
	{
		std::cout << "\t\t~Field: " << _name << std::endl;
	}

private:
	const std::string _name{};
};
//-------------------------------------------------------------------------------------------------
class A :
	public Base1,
	public Base2
{
public:
	Field f1{"f1"}, f2{"f2"}, f3{"f3"};

	A()	 { STD_TRACE_FUNC; }
	~A() { STD_TRACE_FUNC; }
};
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

#endif
