/**
 * \file  main.cpp
 * \brief std::optional
 *
 * \todo
 *
 * The class template std::optional manages an optional contained value, i.e. a value that may or
 * may not be present. A common use case for optional is the return value of a function
 * that may fail.
 */


#include <StdStream/StdStream.h>
#include <StdTest/StdTest.h>
#include <Stl.h>

//-------------------------------------------------------------------------------------------------
std::optional<std::string>
create(bool b)
{
	if (b) {
		return "Godzilla";
	} else {
		return {};
	}
}
//-------------------------------------------------------------------------------------------------
int main(int, char **)
{
	create(false).value_or("empty"); // == "empty"
	create(true).value(); // == "Godzilla"

	// optional-returning factory functions are usable as conditions of while and if
	if (auto str = create(true)) {
		// ...
	}

    // std::cout << STD_TRACE_VAR("") << std::endl;

    return EXIT_SUCCESS;
}
//-------------------------------------------------------------------------------------------------


#if OUTPUT



#endif
