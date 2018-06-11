/**
 * \file  main.cpp
 * \brief
 */


#include "../StdTest.h"

//-------------------------------------------------------------------------------------------------
// Function that accepts no parameter.
// It is to break the recursion chain of vardiac template function
void
log(const char *format)
{
	std::cout << "I am empty function and I am called at last.\n" << std::endl;
}
//-------------------------------------------------------------------------------------------------
// Variadic Template Function that accepts variable number of arguments of any type
template<typename T, typename ...Args>
void
log(const char *format, const T &a_value, Args... a_args)
{
	// Print the First Element
	std::cout << STD_TRACE_VAR2(format, a_value) << std::endl;

	// Forward the remaining arguments
	log(format, a_args...);
}
//-------------------------------------------------------------------------------------------------
int main(int, char **)
{
	log("{}-{}-{}", 2, 3.4, "aaa");

    return EXIT_SUCCESS;
}
//-------------------------------------------------------------------------------------------------


#if OUTPUT



#endif
