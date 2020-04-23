/**
 * \file  main.cpp
 * \brief [[fallthrough]]
 *
 * This attribute indicates that the break operator inside a case block is missing intentionally
 * (i.e., control is passed to the next case block), and therefore, a compiler or static code
 * analyzer warning should not be issued.
 */


#include <StdStream.h>
#include <StdTest.h>
#include <Stl.h>
//-------------------------------------------------------------------------------------------------
void f1() {}
void f2() {}
void f3() {}
void f4() {}
void f5() {}
//-------------------------------------------------------------------------------------------------
int main(int, char **)
{
    const int value = 10;

    // C++17
    switch (value) {
    case 10:
        f1();
        break;
    case 20:
        f2();
        break;
    case 30:
        f3();
        break;
    case 40:
        f4();
        [[fallthrough]]; // The warning will be suppressed
    case 50:
        f5();
    }

    // std::cout << TRACE_VAR("") << std::endl;

    return EXIT_SUCCESS;
}
//-------------------------------------------------------------------------------------------------


#if OUTPUT



#endif
