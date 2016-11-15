/**
 * \file  main.cpp
 * \brief
 */


#include "../StdTest.h"
#include <memory>
#include <string>
#include <iostream>
//---------------------------------------------------------------------------
class Ptr
{
public:
	template<class T>
	static void
	deleteByRef(T* &a_ptr)
	{
		delete a_ptr;
		a_ptr = NULL;
	}

	template<class T>
	static void
	deleteByValue(T* a_ptr)
	{
		delete a_ptr;
		a_ptr = NULL;
	}
};
//---------------------------------------------------------------------------
void func()
{
	{
		int *ptr = new int;
		Ptr::deleteByRef(ptr);
		_xTEST(ptr == NULL);
	}

	{
		int *ptr = new int;

		Ptr::deleteByValue(ptr);
		_xTEST(ptr != NULL);
	}
}
//---------------------------------------------------------------------------
int main(int argsNum, char **args)
{
	func();

	return 0;
}
//---------------------------------------------------------------------------
