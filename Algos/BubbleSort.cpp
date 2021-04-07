/**
 * \file  BubbleSort.cpp
 * \brief
 *
* \todo
 */


#include <StdStream.h>
#include <StdTest.h>
#include <Stl.h>
//-------------------------------------------------------------------------------------------------
template <typename T >
void
bubble_sort(T &a)
{
	for (T::size_type i = 0; a.size() && i < a.size() - 1; ++ i) {
		for (T::size_type j = i; j + 1 > 0; -- j) {
			if (a[j] > a[j+1])
				std::swap(a[j], a[j+1]);
		}
	}
}
//-------------------------------------------------------------------------------------------------
int main(int, char **)
{
    std::vector<int> v;
    v.push_back( 7 );
    v.push_back( 1000 );
    v.push_back( 134 );
    v.push_back( 23 );
    v.push_back( 1 );

    ::bubble_sort( v );

    std::cout << TRACE_VAR(v) << std::endl;

    return EXIT_SUCCESS;
}
//-------------------------------------------------------------------------------------------------


#if OUTPUT



#endif
