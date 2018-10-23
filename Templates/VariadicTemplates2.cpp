/**
 * \file  main.cpp
 * \brief
 */


#include <StdTest.h>

//-------------------------------------------------------------------------------------------------
// Called at last
// Function that accepts no parameter.
// It is to break the recursion chain of vardiac template function
void
log(const char *a_format)
{
	std::cout << STD_TRACE_VAR(__FUNCTION__) << std::endl;
}
//-------------------------------------------------------------------------------------------------
// Variadic Template Function that accepts variable number of arguments of any type
template<typename T, typename ...Args>
void
log(const char *a_format, const T &a_value, Args... a_args)
{
	// Print the First Element
	std::cout << STD_TRACE_VAR2(__FUNCTION__, a_value) << std::endl;

	// Forward the remaining arguments
	log(a_format, a_args...);
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
