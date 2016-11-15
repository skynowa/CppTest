/**
 * \file  main.cpp
 * \brief
 */


#include "../StdTest.h"
#include <new>
//-------------------------------------------------------------------------------------------------
class A
{
public:
	 A(const std::size_t x) {}
	~A() {}
};
//-------------------------------------------------------------------------------------------------
int main(int argsNum, char **args)
{
	const std::size_t n = 50;

	A* placementMemory = static_cast<A*>(operator new[] (n * sizeof(A)));
	for (std::size_t i = 0; i < n; ++ i) {
		// здесь память для объекта не выделяется, но инициализируется
		new (placementMemory + i) A(rand());
	}

	// деинициализация памяти
	{
		for (std::size_t i = 0; i < n; ++ i) {
			placementMemory[i].~A();
		}

		operator delete[] (placementMemory);
	}

    // std::cout << "" << std::endl;

    return 0;
}
//-------------------------------------------------------------------------------------------------


#if OUTPUT



#endif

