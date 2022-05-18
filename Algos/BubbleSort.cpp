/**
 * \file  BubbleSort.cpp
 * \brief
 *
 * \review
 */


#include <StdStream/StdStream.h>
#include <StdTest/StdTest.h>
#include <Stl.h>
//-------------------------------------------------------------------------------------------------
template<typename T >
void
bubbleSort(T &a)
{
    for (typename T::size_type i = 0; a.size() && i < a.size() - 1; ++ i) {
        for (typename T::size_type j = i; j + 1 > 0; -- j) {
            if (a[j] > a[j + 1]) {
                std::swap(a[j], a[j + 1]);
            }
		}
	}
}
//-------------------------------------------------------------------------------------------------
int main(int, char **)
{
    std::vector<int> v {7, 1000, 134, 23, 1};
    ::bubbleSort(v);

    std::cout << STD_TRACE_VAR(v) << std::endl;

    return EXIT_SUCCESS;
}
//-------------------------------------------------------------------------------------------------


#if OUTPUT

v: std::vector (size=5): {1,7,23,134,1000}

#endif
