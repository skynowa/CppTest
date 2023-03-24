/**
 * \file  AccessSpecifiers.cpp
 * \brief Access specifiers
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
#if 0
	protected A // error: ‘A’ is an inaccessible base of ‘B’
#else
	public A
#endif
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
