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
		std::cout << "Sample #1:" << std::endl;

		const std::size_t n = 5;

		auto *buff = static_cast<A *>(operator new[] (n * sizeof(A)));

		for (std::size_t i = 0; i < n; ++ i) {
			// здесь память для объекта не выделяется, но инициализируется
			new (buff + i) A(rand());
		}

		// деинициализация памяти
		{
			for (std::size_t i = 0; i < n; ++ i) {
				buff[i].~A();
			}

			operator delete[] (buff);
		}
	}

	// sample 2
	{
		std::cout << "Sample #2:" << std::endl;

		using T = char;

		const std::size_t n = 7;

		// allocate memory
		T *buff = new T[n * sizeof(T)];

		// construct in allocated storage ("place")
		T *ptr = new (buff) T;

		// test
		strcpy(ptr, "ABCDEF");
		std::cout << "\t" << STD_TRACE_VAR(ptr) << std::endl;

		// destruct
		ptr->~T();

		// deallocate memory
		delete [] buff;
	}

    return EXIT_SUCCESS;
}
//-------------------------------------------------------------------------------------------------


#if OUTPUT

Sample #1:
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

Sample #2:
	ptr: ABCDEF

#endif
