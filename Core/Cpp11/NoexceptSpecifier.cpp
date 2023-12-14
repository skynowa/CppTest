/**
 * \file  NoexceptSpecifier.cpp.cpp
 * \brief
 *
 * \see
 * \todo
 */


#include <StdStream/StdStream.h>
#include <StdTest/StdTest.h>
#include <Stl.h>
//--------------------------------------------------------------------------------------------------
void foo() noexcept(false)
{
	try {
		std::string s;
		s.at(10);

		if (noexcept(s)) {
			std::cout << "Unknown" << std::endl;
		}

		std::cout << s << std::endl;

		throw 1;
	}
	catch (const std::exception &a_e) {
		std::cout << a_e.what() << std::endl;
	}
	catch (...) {
		std::cout << "Unknown" << std::endl;
	}
}
//--------------------------------------------------------------------------------------------------
int main(int, char **)
{
    // STD_TRACE_FUNC;

    // std::cout << STD_TRACE_VAR("") << std::endl;

    ::foo();

    return EXIT_SUCCESS;
}
//--------------------------------------------------------------------------------------------------


#if OUTPUT



#endif
