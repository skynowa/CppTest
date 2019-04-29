/**
 * \file  main.cpp
 * \brief https://github.com/rioki/rex/blob/master/strex.h#L71
 */


#include <StdStream.h>
#include <StdTest.h>
#include <Stl.h>
//-------------------------------------------------------------------------------------------------
constexpr std::size_t
hash(
	const char        *a_str,
	const std::size_t  a_h = {}
)
{
	if (a_str == nullptr) {
		return {};
	}

    return !a_str[a_h] ? 5381 : (hash(a_str, a_h + 1) * 33) ^ a_str[a_h];
}
//-------------------------------------------------------------------------------------------------
std::size_t
hash(
	const std::string &a_str
)
{
	return ::hash( a_str.c_str() );
}
//-------------------------------------------------------------------------------------------------
void
ifString_test(
	const std::string &a_value
)
{
    if      (a_value == "aaaaa") {
		std::cout << "aaaaa" << std::endl;
	}
	else if (a_value == "bbbbb") {
		std::cout << "bbbbb" << std::endl;
	}
	else if (a_value == "ccccc") {
		std::cout << "ccccc" << std::endl;
	}
	else {
		std::cout << "[Unknown]: " << ::hash(a_value) << std::endl;
	}
}
//-------------------------------------------------------------------------------------------------
void
switchString_test(
	const char *a_value
)
{
    switch (::hash(a_value)) {
    case ::hash("aaaaa"):
        std::cout << "aaaaa" << std::endl;
        break;
    case ::hash("bbbbb"):
        std::cout << "bbbbb" << std::endl;
        break;
    case ::hash("ccccc"):
		std::cout << "ccccc" << std::endl;
        break;
    default:
        std::cout << "[Unknown]: " << ::hash(a_value) << std::endl;
        break;
    }
}
//-------------------------------------------------------------------------------------------------
int main(int, char **)
{
	{
	#if 1
		std::cout << "::: ifString_test :::" << std::endl;

		::ifString_test("aaaaa");
		::ifString_test("bbbbb");
		::ifString_test("ccccc");
		::ifString_test("xxxxx");
		::ifString_test("");
		::ifString_test({});	// nullptr
	#endif
	}

	std::cout << std::endl;

	{
	#if 1
		std::cout << "::: switchString_test :::" << std::endl;

		::switchString_test("aaaaa");
		::switchString_test("bbbbb");
		::switchString_test("ccccc");
		::switchString_test("xxxxx");
		::switchString_test("");
		::switchString_test(nullptr);
	#endif
	}

    return EXIT_SUCCESS;
}
//-------------------------------------------------------------------------------------------------


#if OUTPUT



#endif
