/**
 * \file  For.cpp
 * \brief
 */


#include <StdStream/StdStream.h>
#include <StdTest/StdTest.h>
#include <Stl.h>
//---------------------------------------------------------------------------
bool
trace(const std::string &a_point)
{
    std::cout << a_point;

    return true;
}
//---------------------------------------------------------------------------
int main(int, char **)
{
    {
        int i = 0;

        for (trace("1,"); trace("2"); trace("3,")) {
            std::cout << " {" << TRACE_VAR(i) << "}" << std::endl;

            ++ i;

            if (i == 5) {
                break;
            }
        }
    }

    {
        std::cout << std::endl;

        for (int x = 0; x != 0; ++ x) {
            std::cout << " {" << TRACE_VAR(x) << "}" << std::endl;
        }
    }

    return EXIT_SUCCESS;
}
//---------------------------------------------------------------------------


#if OUTPUT

1,2 {i: 0}
3,2 {i: 1}
3,2 {i: 2}
3,2 {i: 3}
3,2 {i: 4}

// x - n/a

#endif