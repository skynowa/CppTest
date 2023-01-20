/**
 * \file  SmallObjectOptimization.cpp
 * \brief Small Object Optimization (aka small buffer optimization)
 *
 * Small Object Optimization means that the std::string object has a small buffer for small strings,
 * which saves dynamic allocations.
 *
 * \see   https://shaharmike.com/cpp/std-string/
 */


#include <StdStream/StdStream.h>
#include <StdTest/StdTest.h>
#include <Stl.h>
//--------------------------------------------------------------------------------------------------
// replace operator new and delete to log allocations
void *
operator new(std::size_t n)
{
    std::cout << "[Allocating " << n << " bytes]";
    return malloc(n);
}
//--------------------------------------------------------------------------------------------------
void
operator delete(void *p) throw()
{
    free(p);
}
//--------------------------------------------------------------------------------------------------
void
operator delete(void *p, std::size_t) throw()
{
    free(p);
}
//--------------------------------------------------------------------------------------------------
int main(int, char **)
{
    for (std::size_t i = 0; i < 24; ++i) {
        std::cout << i << ": " << std::string(i, '=') << std::endl;
    }

    return EXIT_SUCCESS;
}
//--------------------------------------------------------------------------------------------------


#if OUTPUT

// GCC

0:
1: =
2: ==
3: ===
4: ====
5: =====
6: ======
7: =======
8: ========
9: =========
10: ==========
11: ===========
12: ============
13: =============
14: ==============
15: ===============
16: [Allocating 17 bytes]================
17: [Allocating 18 bytes]=================
18: [Allocating 19 bytes]==================
19: [Allocating 20 bytes]===================
20: [Allocating 21 bytes]====================
21: [Allocating 22 bytes]=====================
22: [Allocating 23 bytes]======================
23: [Allocating 24 bytes]=======================

#endif
