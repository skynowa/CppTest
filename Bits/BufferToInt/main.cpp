 /*
 * \file  Main.cpp
 * \brief buffer (memory) convert to int
 */


//---------------------------------------------------------------------------
#include <string>
#include <iostream>
#include <memory.h>
#include <assert.h>
//---------------------------------------------------------------------------
int main()
{

    // int == 742
    const unsigned char array[4] = {0x00, 0x00, 0x02, 0xe7};

    // 1 variant
    {
        int rv = 0;

        for (size_t i = 0; i < sizeof(array); ++ i) {
            rv <<= 8;
            rv |= array[i];
        }

        std::cout << "rv = " << rv << std::endl;
    }

    // 2 variant
    {
        int rv = 0;

        for (size_t i = 0; i < sizeof(array); ++ i) {
            rv = rv * 256 + (array[i] & 0xff);
        }

        std::cout << "rv = " << rv << std::endl;
    }

    // 3 variant
    {
        int rv = 0;

        rv = *(int *)array;

        std::cout << "rv = " << rv << std::endl;
    }

    // 4 variant
    {
        int rv = 0;

        memcpy(&rv, array, sizeof(int));

        std::cout << "rv = " << rv << std::endl;
    }

    return EXIT_SUCCESS;
}
//---------------------------------------------------------------------------

#if OUTPUT

    rv = 743
    rv = 743
    rv = -419299328
    rv = -419299328

#endif
