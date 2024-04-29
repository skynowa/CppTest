 /*
 * \file  CompareWithEpsilon.cpp
 * \brief
 */


#include <StdStream/StdStream.h>
#include <StdTest/StdTest.h>
#include <Stl.h>
//-------------------------------------------------------------------------------------------------
template<
    typename T,
    typename = typename std::enable_if<std::is_floating_point<T>::value, T>::type>
inline bool
isFloatEqual(
    const T a,
    const T b,
    const T epsilon = std::numeric_limits<T>::epsilon()
) noexcept
{
    return std::abs(a - b) <= epsilon;
}
//-------------------------------------------------------------------------------------------------
int main(int, char **)
{
    STD_TEST(isFloatEqual(0.1, 0.1));
    STD_TEST(isFloatEqual(0.3, 0.3));
    STD_TEST(isFloatEqual(0.4, 0.1 + 0.3));
    STD_TEST(isFloatEqual(0.5, 0.2 + 0.3));

    return EXIT_SUCCESS;
}
//-------------------------------------------------------------------------------------------------


#if OUTPUT

#endif
