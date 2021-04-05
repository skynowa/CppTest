/**
 * \file  main.cpp
 * \brief Template argument deduction for class templates
 *
 * \todo
 *
 * Automatic template argument deduction much like how it's done for functions,
 * but now including class constructors
 */


#include <StdStream.h>
#include <StdTest.h>
#include <Stl.h>
//-------------------------------------------------------------------------------------------------
template <typename T = float>
struct Container
{
	const T _val{};

	Container() :
		_val{}
	{
		printType();
	}

	Container(T val) :
		_val{val}
	{
		printType();
	}

	void printType() const
	{
		std::cout << "_val type: " << typeid(_val).name() << std::endl;
	}
};
//-------------------------------------------------------------------------------------------------
int main(int, char **)
{
	Container c;		// Container<float>
	Container c1{1};	// Container<int>
	Container c2{1UL};	// Container<unsigned long>

    return EXIT_SUCCESS;
}
//-------------------------------------------------------------------------------------------------


#if OUTPUT

_val type: f
_val type: i
_val type: m

#endif
