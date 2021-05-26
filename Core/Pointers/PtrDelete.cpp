/**
 * \file  PtrDelete.cpp
 * \brief
 */


#include <StdStream.h>
#include <StdTest.h>
#include <Stl.h>
//--------------------------------------------------------------------------------------------------
class Ptr
{
public:
	template<class T>
	static void
	deleteByRef(T* &a_ptr)
	{
		STD_TRACE_FUNC;

		delete a_ptr;
		a_ptr = nullptr;
	}

	template<class T>
	static void
	deleteByValue(T* a_ptr)
	{
		STD_TRACE_FUNC;

		delete a_ptr;
		a_ptr = nullptr;
	}
};
//--------------------------------------------------------------------------------------------------
void func()
{
	{
		int *ptr = new int;
		Ptr::deleteByRef(ptr);
		STD_TEST(ptr == nullptr);
	}

	{
		int *ptr = new int;

		Ptr::deleteByValue(ptr);
		STD_TEST(ptr != nullptr);
	}
}
//--------------------------------------------------------------------------------------------------
int main(int, char **)
{
	func();

    return EXIT_SUCCESS;
}
//--------------------------------------------------------------------------------------------------


#if OUTPUT

	::: deleteByRef :::
	::: deleteByValue :::

#endif
