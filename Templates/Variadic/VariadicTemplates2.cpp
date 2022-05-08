/**
 * \file  VariadicTemplates2.cpp
 * \brief
 *
 * \todo
 */


#include <StdStream/StdStream.h>
#include <StdTest/StdTest.h>
#include <Stl.h>
//-------------------------------------------------------------------------------------------------
// Called at last
// Function that accepts no parameter.
// It is to break the recursion chain of vardiac template function
void
log(const char *a_format)
{
	STD_UNUSED(a_format)

	std::cout << "[" << __FUNCTION__ << "]: no params" << std::endl;
}
//-------------------------------------------------------------------------------------------------
// Variadic Template Function that accepts variable number of arguments of any type
template<typename T, typename ... Params>
void
log(
	const char   *a_format,
	const T      &a_value,
	const Params & ... a_params
)
{
	// Print the First Element
	std::cout << "[" << __FUNCTION__ << "]: " << a_value << std::endl;

	// Forward the remaining arguments
	log(a_format, a_params...);
}
//-------------------------------------------------------------------------------------------------
int main(int, char **)
{
	log("{}-{}-{}", 2, 3.4, "aaa");

    return EXIT_SUCCESS;
}
//-------------------------------------------------------------------------------------------------


#if OUTPUT

__FUNCTION__: log, a_value: 2
__FUNCTION__: log, a_value: 3.4
__FUNCTION__: log, a_value: aaa
__FUNCTION__: log

#endif
