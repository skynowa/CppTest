/**
 * \file  Inheritance.cpp
 * \brief Access level
 */


#include <StdStream/StdStream.h>
#include <StdTest/StdTest.h>
#include <Stl.h>
//--------------------------------------------------------------------------------------------------
class A
{
public:
			 A() { STD_TRACE_FUNC; }
	virtual ~A() { STD_TRACE_FUNC; }
};
//--------------------------------------------------------------------------------------------------
class B :
	// protected A - error: ‘I’ is an inaccessible base of ‘A’
	public A
{
public:
	B() { STD_TRACE_FUNC; }
   ~B() { STD_TRACE_FUNC; }
};
//--------------------------------------------------------------------------------------------------
int main(int, char **)
{
    A *a = new B();
    delete a;

    return EXIT_SUCCESS;
}
//--------------------------------------------------------------------------------------------------


#if OUTPUT

	::: A :::
	::: B :::
	::: ~B :::
	::: ~A :::

#endif
