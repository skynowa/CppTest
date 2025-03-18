/**
 * \file  Atoi.cpp
 * \brief Convert Non-number values to int, double
 */


//---------------------------------------------------------------------------
#include <StdStream/StdStream.h>
#include <StdTest/StdTest.h>
#include <Stl.h>
//---------------------------------------------------------------------------
int main(int, char **)
{
	const char *strInts []
	{
		"", "NULL", "ta", "13ta", "a31", "$27,41"
	};

	for (const auto it_strInt : strInts) {
		int a = std::atoi(it_strInt);
		std::cout << STD_TRACE_VAR2(it_strInt, a) << std::endl;
	}

	{
	#if 0
		const char *strInt {nullptr};

		int a = std::atoi(strInt);
		std::cout << STD_TRACE_VAR2(strInt, a) << std::endl;
	#endif
	}

	{
		const char *strDouble {"$27,41 "};

	   /**
		* Need for fix:
		*
		* - Remove  - "$"
		* - Replace - "," -> "."
		*/
	    double a = std::strtod(strDouble, nullptr);
		std::cout << STD_TRACE_VAR2(strDouble, a) << std::endl;
	}

    return EXIT_SUCCESS;
}
//---------------------------------------------------------------------------


#if OUTPUT

---------------------------------------------
it_strInt: , a: 0
it_strInt: NULL, a: 0
it_strInt: ta, a: 0
it_strInt: 13ta, a: 13
it_strInt: a31, a: 0
it_strInt: $27,41, a: 0
strDouble: $27,41 , a: 0
---------------------------------------------

#endif
