 /*
 * \file  main.cpp
 * \brief
 */


#include <StdTest.h>


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
	Field()	 { STD_TRACE_FUNC; }
	~Field() { STD_TRACE_FUNC; }
};
//-------------------------------------------------------------------------------------------------
class A :
	public Base1,
	public Base2
{
public:
	Field f1, f2, f3;

	A()	 { STD_TRACE_FUNC; }
	~A() { STD_TRACE_FUNC; }
};
//-------------------------------------------------------------------------------------------------
int main(int argsNum, char **args)
{
	A a;

	return 0;
}
//-------------------------------------------------------------------------------------------------


#if OUTPUT

	::: Base1 :::
	::: Base2 :::
	::: Field :::
	::: Field :::
	::: Field :::
	::: A :::
	::: ~A :::
	::: ~Field :::
	::: ~Field :::
	::: ~Field :::
	::: ~Base2 :::
	::: ~Base1 :::

#endif

