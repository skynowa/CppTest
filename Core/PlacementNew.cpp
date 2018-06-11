/**
 * \file  main.cpp
 * \brief
 */


#include <StdTest.h>
#include <new>
//-------------------------------------------------------------------------------------------------
class A
{
public:
	 A(const std::size_t x) {}
	~A() {}
};
//-------------------------------------------------------------------------------------------------
int main(int, char **)
{
   /**
    * FAQ
    *
    * Placement new allows you to construct an object on memory that's already allocated
    */

	// sample 1
	{
		const std::size_t n = 50;

		A* placementBuff = static_cast<A*>(operator new[] (n * sizeof(A)));
		for (std::size_t i = 0; i < n; ++ i) {
			// здесь память для объекта не выделяется, но инициализируется
			new (placementBuff + i) A(rand());
		}

		// деинициализация памяти
		{
			for (std::size_t i = 0; i < n; ++ i) {
				placementBuff[i].~A();
			}

			operator delete[] (placementBuff);
		}
	}

	// sample 2
	{
		typedef char T;
		const std::size_t n = 50;

		// allocate memory
		T* placementBuff = new T[n * sizeof(T)];

		// construct in allocated storage ("place")
		T* ptr = new(placementBuff) T;

		// test
		strcpy(ptr, "ABCDEF");
		std::cout << STD_TRACE_VAR(ptr) << std::endl;

		// destruct
		ptr->~T();

		// deallocate memory
		delete [] placementBuff;
	}

    return 0;
}
//-------------------------------------------------------------------------------------------------


#if OUTPUT



#endif

