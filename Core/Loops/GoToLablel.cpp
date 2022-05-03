/**
 * \file  GoToLablel.cpp
 * \brief
 */


#include <StdStream.h>
#include <StdTest.h>
#include <Stl.h>
//--------------------------------------------------------------------------------------------------
int main(int, char **)
{
    for (size_t i = 0; i < 10; ++ i) {
        if (i == 5) {
            goto finally;
        }
    }

    std::cout << 1 << std::endl;;

finally: {
    std::cout << 2 << std::endl;
}

    std::cout << 3 << std::endl;

    return EXIT_SUCCESS;
}
//---------------------------------------------------------------------------


#if OUTPUT

// with goto
2
3

// without goto
1
2
3

#endif
