 /*
 * \file  BuffToint.cpp
 * \brief buffer (memory) convert to int
 */


#include <StdStream/StdStream.h>
#include <StdTest/StdTest.h>
#include <Stl.h>
//---------------------------------------------------------------------------
int main()
{
    // int == 742
    const unsigned char array[4] {0x00, 0x00, 0x02, 0xe7};

    // 1 variant
    {
        int rv = 0;

        for (size_t i = 0; i < sizeof(array); ++ i) {
            rv <<= 8;
            rv |= array[i];
        }

        std::cout << STD_TRACE_VAR(rv) << std::endl;
    }

    // 2 variant
    {
        int rv = 0;

        for (size_t i = 0; i < sizeof(array); ++ i) {
            rv = rv * 256 + (array[i] & 0xff);
        }

        std::cout << STD_TRACE_VAR(rv) << std::endl;
    }

    // 3 variant
    {
        int rv = 0;

        rv = *reinterpret_cast<const int *>(array);

        std::cout << STD_TRACE_VAR(rv) << std::endl;
    }

    // 4 variant
    {
        int rv = 0;

        memcpy(&rv, array, sizeof(int));

        std::cout << STD_TRACE_VAR(rv) << std::endl;
    }

    return EXIT_SUCCESS;
}
//---------------------------------------------------------------------------

#if OUTPUT

rv: 743
rv: 743
rv: -419299328
rv: -419299328

#endif
