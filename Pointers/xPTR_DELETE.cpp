/**
 * \file  main.cpp
 * \brief
 */


#include <StdTest.h>
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
		STD_TEST(ptr == NULL);
	}

	{
		int *ptr = new int;

		Ptr::deleteByValue(ptr);
		STD_TEST(ptr != NULL);
	}
}
//---------------------------------------------------------------------------
int main(int, char **)
{
	func();

	return 0;
}
//---------------------------------------------------------------------------
