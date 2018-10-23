/**
 * \file  main.cpp
 * \brief
 */


#include "../StdTest.h"
#include "../Stl.h"

//-------------------------------------------------------------------------------------------------
template<typename ... Param>
std::vector<std::string>
toString(const Param & ... a_param)
{
	const auto toString_impl = [](const auto &t) -> std::string
	{
		std::stringstream ss;
		ss << t;

		return ss.str();
	};

	return std::vector<std::string>{ toString_impl(a_param)... };
}
//-------------------------------------------------------------------------------------------------
int main(int, char **)
{
	const std::vector<std::string> vec = ::toString("hello", 1, 5.3, "bob");

    for (auto &it : vec) {
		std::cout << STD_TRACE_VAR(it) << std::endl;
	}

    return 0;
}
//-------------------------------------------------------------------------------------------------


#if OUTPUT

it: hello
it: 1
it: 5.3
it: bob

#endif
