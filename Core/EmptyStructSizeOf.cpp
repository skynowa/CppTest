/**
 * \file  main.cpp
 * \brief
 */


#include <StdTest.h>

//-------------------------------------------------------------------------------------------------
struct A_1byte
{
};
//-------------------------------------------------------------------------------------------------
struct B_1byte :
	A_1byte
{
};
//-------------------------------------------------------------------------------------------------
class C_0byte
{
	int NO_DATA[0];
};
//-------------------------------------------------------------------------------------------------
class D_8byte
{
	virtual int foo() {}
};
//-------------------------------------------------------------------------------------------------
class E_4byte
{
	int value;
};
//-------------------------------------------------------------------------------------------------
class F_16byte
{
	D_8byte value1;
	E_4byte value2;
};
//-------------------------------------------------------------------------------------------------
int main(int argsNum, char **args)
{
	std::cout
		<< STD_TRACE_VAR(sizeof(A_1byte))  << "\n"
		<< STD_TRACE_VAR(sizeof(B_1byte))  << "\n"
		<< STD_TRACE_VAR(sizeof(C_0byte))  << "\n"
		<< STD_TRACE_VAR(sizeof(D_8byte))  << "\n"
		<< STD_TRACE_VAR(sizeof(E_4byte))  << "\n"
		<< STD_TRACE_VAR(sizeof(F_16byte)) << "\n"
		<< std::endl;

	return 0;
}
//-------------------------------------------------------------------------------------------------


#if OUTPUT

sizeof(A_1byte): 1
sizeof(B_1byte): 1
sizeof(C_0byte): 0
sizeof(D_8byte): 8
sizeof(E_4byte): 4
sizeof(F_16byte): 16

#endif

