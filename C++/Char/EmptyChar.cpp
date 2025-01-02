/**
 * \file  EmptyChar.cpp
 * \brief Empty char
 */


#include <StdStream/StdStream.h>
#include <StdTest/StdTest.h>
#include <Stl.h>
//-------------------------------------------------------------------------------------------------
int main(int, char **)
{
    {
        const char ch {};
        static_assert(ch == char{});

        std::cout << STD_TRACE_VAR2(ch, static_cast<int>(ch)) << std::endl;
    }

    {
        const char ch {'\0'};
        static_assert(ch == char{});

        std::cout << STD_TRACE_VAR2(ch, static_cast<int>(ch)) << std::endl;
    }

    {
        const char ch {0};
        static_assert(ch == char{});

        std::cout << STD_TRACE_VAR2(ch, static_cast<int>(ch)) << std::endl;
    }

    {
        const char ch {'0'};
        static_assert(ch == char{48});

        std::cout << STD_TRACE_VAR2(ch, static_cast<int>(ch)) << std::endl;
    }

    {
        const char ch {' '};
        static_assert(ch == char{32});

        std::cout << STD_TRACE_VAR2(ch, static_cast<int>(ch)) << std::endl;
    }

    {
    #if 0
        const char ch {''};   // error: empty character constant

        std::cout << STD_TRACE_VAR2(ch, static_cast<int>(ch)) << std::endl;
    #endif
    }

    return 0;
}
//-------------------------------------------------------------------------------------------------


#if OUTPUT

ch: ,  static_cast<int>(ch): 0
ch: ,  static_cast<int>(ch): 0
ch: ,  static_cast<int>(ch): 0
ch: 0, static_cast<int>(ch): 48
ch:  , static_cast<int>(ch): 32

#endif
