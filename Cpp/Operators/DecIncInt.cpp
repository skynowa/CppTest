 /*
 * \file  DecIncInt.cpp
 * \brief Decrement, increment and sequence point
 *
 * \review
 */


#include <StdStream/StdStream.h>
#include <StdTest/StdTest.h>
#include <Stl.h>
//--------------------------------------------------------------------------------------------------
// ++ i
int
incPre(int &i)
{
	i = i + 1;

	return i;
}
//--------------------------------------------------------------------------------------------------
// i ++
int
incPost(int &i)
{
	int r = i;
	i = i + 1;

	return r;
}
//--------------------------------------------------------------------------------------------------
int main(int, char **)
{
    // 1
    {
	    int i = 1;
	    int x = 0;

	    x = ++ i; // result: x = 2, i = 2
	    std::cout << "x = " << x << ", "
                  << "i = " << i << std::endl;

	    i = 1;
	    x = i ++; // result: x = 1, i = 2
	    std::cout << "x = " << x << ", "
                  << "i = " << i << std::endl;

	    i = 1;
	    x = ++ i; // result: x = 2, i = 2
	    std::cout << "x = " << x << ", "
                  << "i = " << i << std::endl;

        std::cout << std::endl;

    #if OUTPUT

        x = 2, i = 2
        x = 1, i = 2
        x = 2, i = 2

    #endif
    }

    // 2
    {
    #pragma GCC diagnostic push
    #pragma GCC diagnostic ignored "-Wsequence-point"

        for (int i = 0; i < 5; ++ i) {
	        std::cout
                << "i = " << i ++ << ", "
				<< "i = " << ++ i << std::endl;
        }

    #pragma GCC diagnostic pop

        std::cout << std::endl;

    #if OUTPUT

        i = 1, i = 2
        i = 4, i = 5

    #endif
    }

    // 3
    {
        int x = 0;

        for (int i = 0; i < 5; ++ i) {
            x = i ++;
            std::cout << "x = " << x << ", ";

            x = ++ i;
            std::cout << "x = " << x << std::endl;
        }

        std::cout << std::endl;

    #if OUTPUT

        x = 0, x = 2
        x = 3, x = 5

    #endif
    }

    // 4
    {
        int x = 0;

    // error C2105: '--' needs l-value
    #if NOT_COMPILE
        -- x ++;
    #endif

        (-- x) ++;

        std::cout << "x = " << x << std::endl;

        std::cout << std::endl;

    #if OUTPUT

        x = 0;

    #endif
    }

    // 5
    {
        int x = 0;
        int a = 0;
        int b = 0;

    // error C2105: '++' needs l-value
    #if NOT_COMPILE
        x = a+++++b;
    #endif

    // error C2105: '++' needs l-value
    #if NOT_COMPILE
        x = ((a++)++)+b;
    #endif

        x = (a++)+(++b);

        std::cout << "x = " << x << std::endl;

        std::cout << std::endl;

    #if OUTPUT

        x = 1;

    #endif
    }

    return EXIT_SUCCESS;
}
//--------------------------------------------------------------------------------------------------


#if OUTPUT

x = 2, i = 2
x = 1, i = 2
x = 2, i = 2

i = 0, i = 2
i = 3, i = 5

x = 0, x = 2
x = 3, x = 5

x = 0

x = 1

#endif
