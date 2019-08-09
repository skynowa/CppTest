/**
 * \file  main.cpp
 * \brief Template argument deduction for class templates
 *
 * Automatic template argument deduction much like how it's done for functions, but now including class constructors
 */


#include <StdStream.h>
#include <StdTest.h>
#include <Stl.h>

//-------------------------------------------------------------------------------------------------
int main(int, char **)
{
	template <typename T = float>
	struct MyContainer {
	T val;
	MyContainer() : val() {}
	MyContainer(T val) : val(val) {}
	// ...
	};
	MyContainer c1 {1}; // OK MyContainer<int>
	MyContainer c2; // OK MyContainer<float>

    // std::cout << TRACE_VAR("") << std::endl;

    return EXIT_SUCCESS;
}
//-------------------------------------------------------------------------------------------------


#if OUTPUT



#endif
