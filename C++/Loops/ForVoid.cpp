/**
 * \file  ForVoid.cpp
 * \brief
 */


#include <StdStream/StdStream.h>
#include <StdTest/StdTest.h>
#include <Stl.h>
//---------------------------------------------------------------------------
int main(int, char **)
{
    for (
        int i {5}, x {}, y {};

        0 < i;

        -- i, (void)++ x, ++ y)
    {
        std::cout << STD_TRACE_VAR3(i, x, y) << std::endl;
    }

    return EXIT_SUCCESS;
}
//--------------------------------------------------------------------------------------------------


#if OUTPUT

i: 5, x: 0, y: 0
i: 4, x: 1, y: 1
i: 3, x: 2, y: 2
i: 2, x: 3, y: 3
i: 1, x: 4, y: 4

#endif
