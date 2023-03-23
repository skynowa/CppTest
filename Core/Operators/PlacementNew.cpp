/**
 * \file  PlacementNew.cpp
 * \brief Placement new allows you to construct an object on memory that's already allocated
 *
 * \review
 */


#include <StdStream/StdStream.h>
#include <StdTest/StdTest.h>
#include <Stl.h>
//-------------------------------------------------------------------------------------------------
class A
{
public:
	explicit A(const std::size_t a_x) :
		_x{a_x}
	{
		STD_TRACE_FUNC;
	}

	~A()
	{
		STD_TRACE_FUNC;
	}

private:
	const std::size_t _x {};
};
//-------------------------------------------------------------------------------------------------
int main(int, char **)
{
	// sample 1
	{
		const std::size_t n {5};

		auto *placementBuff = static_cast<A *>(operator new[] (n * sizeof(A)));

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
		using T = char;

		const std::size_t n {7};

		// allocate memory
		T *placementBuff = new T[n * sizeof(T)];

		// construct in allocated storage ("place")
		T *ptr = new(placementBuff) T;

		// test
		strcpy(ptr, "ABCDEF");
		std::cout << STD_TRACE_VAR(ptr) << std::endl;

		// destruct
		ptr->~T();

		// deallocate memory
		delete [] placementBuff;
	}

    return EXIT_SUCCESS;
}
//-------------------------------------------------------------------------------------------------


#if OUTPUT

	::: A :::
	::: A :::
	::: A :::
	::: A :::
	::: A :::
	::: ~A :::
	::: ~A :::
	::: ~A :::
	::: ~A :::
	::: ~A :::
ptr: ABCDEF

#endif
