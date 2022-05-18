/**
 * \file  VariadicTemplates.cpp
 * \brief
 *
 * \todo
 */


#include <StdStream/StdStream.h>
#include <StdTest/StdTest.h>
#include <Stl.h>
//-------------------------------------------------------------------------------------------------
void
printfV(const char* a_format)
{
	while (*a_format) {
		if (*a_format == '%' && *++a_format != '%')
			throw std::runtime_error("invalid format string: missing arguments");

		std::cout << *a_format ++;
	}
}
//-------------------------------------------------------------------------------------------------
template<typename T, typename... Params>
void
printfV(
	const char   *a_format,
	const T      &a_value,
	const Params &... a_params
)
{
	while (*a_format) {
		if (*a_format == '%' && *++a_format != '%') {
			// ignore the character that follows the '%': we already know the type!
			std::cout << STD_TRACE_VAR(a_value) << std::endl;

			return printfV(++ a_format, a_params...);
		}

		std::cout << *a_format++;
	}

	throw std::runtime_error("extra arguments provided to printfV");
}
//-------------------------------------------------------------------------------------------------
int main(int, char **)
{
	printfV("-%d-%s-%f\n", 1, "s", 0.5);

    // std::cout << STD_TRACE_VAR("") << std::endl;

    return 0;
}
//-------------------------------------------------------------------------------------------------


#if OUTPUT



#endif
