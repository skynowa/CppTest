/**
* \file  SwitchCase.cpp.cpp
* \brief Modern switch / case
*/


#include <StdStream/StdStream.h>
#include <StdTest/StdTest.h>
#include <Stl.h>
//---------------------------------------------------------------------------
int
main()
{
    // error: range expressions in switch statements are non-standard [-Werror=pedantic]
#if 0
    const int ints[] {-1, 0, 2, 3, 4, 6, 7, 200};

    for (const auto it_int : ints) {
        std::cout << it_int << " -> ";

        switch (it_int) {
        case 0 ... 3:
            std::cout << "[0 ... 3]" << std::endl;
            break;
        case 4 ... 5:
            std::cout << "[4 ... 5]" << std::endl;
            break;
        case 6:
            std::cout << "[6]" << std::endl;
            break;
        case 7 ... INT_MAX:
            std::cout << "[7 ... INT_MAX]" << std::endl;
            break;
        default:
            std::cout << "[default]" << std::endl;
            break;
        }
    }
#endif

    return EXIT_SUCCESS;
}
//---------------------------------------------------------------------------

#if 0

-1 -> [default]
0 -> [0 ... 3]
2 -> [0 ... 3]
3 -> [0 ... 3]
4 -> [4 ... 5]
6 -> [6]
7 -> [7 ... INT_MAX]
200 -> [7 ... INT_MAX]

#endif