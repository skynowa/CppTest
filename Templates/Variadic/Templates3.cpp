/**
 * \file  Templates3.cpp
 * \brief
 *
 * \todo
 */


#include <StdStream/StdStream.h>
#include <StdTest/StdTest.h>
#include <Stl.h>
//-------------------------------------------------------------------------------------------------
template<typename ... Params>
std::vector<std::string>
toString(const Params & ... a_params)
{
	const auto toString_impl = [](const auto &t) -> std::string
	{
		std::stringstream ss;
		ss << t;

		return ss.str();
	};

	return std::vector<std::string>{ toString_impl(a_params)... };
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
