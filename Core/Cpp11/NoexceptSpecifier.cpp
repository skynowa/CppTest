/**
 * \file  NoexceptSpecifier.cpp
 * \brief noexcept specifier
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
		str.at(10); // Compile Time - OK

        // static_assert(noexcept(str.at(10)));  // Compile Time - error: static assertion failed
        static_assert(!noexcept(str.at(0)));     // Compile Time - OK

		std::cout << STD_TRACE_VAR(str) << std::endl;

		throw 1; // Compile Time - OK
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

    static_assert(noexcept(true));  // Compile Time - OK
    static_assert(noexcept(false)); // Compile Time - OK

    if ( noexcept(true) ) {
        std::cout << "noexcept - true" << std::endl;
    }

    if ( noexcept(false) ) {
        std::cout << "noexcept - false" << std::endl;
    }

    ::foo(); // Compile Time - OK

    return EXIT_SUCCESS;
}
//--------------------------------------------------------------------------------------------------


#if OUTPUT

noexcept - true
noexcept - false
	::: foo :::
a_e.what(): basic_string::at: __n (which is 10) >= this->size() (which is 5)

#endif
