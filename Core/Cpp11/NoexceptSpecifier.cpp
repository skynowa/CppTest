/**
 * \file  NoexceptSpecifier.cpp
 * \brief
 *
 * \see
 * \todo
 */


#include <StdStream/StdStream.h>
#include <StdTest/StdTest.h>
#include <Stl.h>
//--------------------------------------------------------------------------------------------------
void foo() noexcept(true)
{
    STD_TRACE_FUNC;

	try {
		std::string str = "xxxxx";
		str.at(10); // Compiletime - OK

        // static_assert(noexcept(str.at(10)));  // Compiletime - error: static assertion failed
        static_assert(!noexcept(str.at(0)));     // Compiletime - OK

		std::cout << STD_TRACE_VAR(str) << std::endl;

		throw 1; // Compiletime - OK
	}
	catch (const std::exception &a_e) {
		std::cout << STD_TRACE_VAR(a_e.what()) << std::endl;
	}
	catch (...) {
		std::cout << "Unknown" << std::endl;
	}
}
//--------------------------------------------------------------------------------------------------
int main(int, char **)
{
    // std::cout << STD_TRACE_VAR("") << std::endl;

    static_assert(noexcept(true));  // Compiletime - OK
    static_assert(noexcept(false)); // Compiletime - OK

    if ( noexcept(true) ) {
        std::cout << "noexcept - true" << std::endl;
    }

    if ( noexcept(false) ) {
        std::cout << "noexcept - false" << std::endl;
    }

    ::foo(); // Compiletime - OK

    return EXIT_SUCCESS;
}
//--------------------------------------------------------------------------------------------------


#if OUTPUT

noexcept - true
noexcept - false
	::: foo :::
a_e.what(): basic_string::at: __n (which is 10) >= this->size() (which is 5)

#endif
