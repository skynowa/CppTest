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
    std::string s;

    int a = std::atoi( s.c_str() );
    std::cout << STD_TRACE_VAR(a) << std::endl;

    int b = std::atoi("");
    std::cout << STD_TRACE_VAR(b) << std::endl;

    int c = std::atoi("NULL");
    std::cout << STD_TRACE_VAR(c) << std::endl;

#if 0
	int d = std::atoi(nullptr);
	std::cout << d << std::endl;
#endif

   /**
    * Need for fix:
    *
    * - Remove  - "$"
    * - Replace - "," -> "."
    */
    double e = std::strtod("$27,41", nullptr);
    std::cout << STD_TRACE_VAR(e) << std::endl;

    return EXIT_SUCCESS;
}
//---------------------------------------------------------------------------


#if OUTPUT

a: 0
b: 0
c: 0
d: Segmentation fault
e: 0

#endif
