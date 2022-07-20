/**
 * \file  Npos.cpp
 * \brief npos is a static member constant value with the greatest possible value for an element of type size_t
 *
 * static const size_t npos = -1;
 */


#include <StdStream/StdStream.h>
#include <StdTest/StdTest.h>
#include <Stl.h>
//--------------------------------------------------------------------------------------------------
int main(int, char **)
{
    std::size_t i = -1;

    if (i == std::string::npos) {
        std::cout << STD_TRACE_VAR(i) << " - as string::npos" << std::endl;
    }

    std::cout << STD_TRACE_VAR(i) << std::endl;

    return EXIT_SUCCESS;
}
//--------------------------------------------------------------------------------------------------


#if OUTPUT

i: 18446744073709551615 - as string::npos
i: 18446744073709551615

#endif
