/**
 * \file  Slice.cpp
 * \brief
 */


#include <StdStream/StdStream.h>
#include <StdTest/StdTest.h>
#include <Stl.h>

using namespace std;
//-------------------------------------------------------------------------------------------------
template<typename T>
vector<T>
slice(
    const vector<T> &v,
    const size_t     begin,
    const size_t     end
)
{
	auto first = v.cbegin() + begin;
	auto last  = v.cbegin() + end + 1;

	return {first, last};
}
//-------------------------------------------------------------------------------------------------
int main()
{
	const vector<int> vec {7,6,2,4,1,9,10,15,17};

	vector<int> subVec = ::slice(vec, 3, 6);

	cout << STD_TRACE_VAR(subVec) <<endl;

	return 0;
}
//-------------------------------------------------------------------------------------------------

#if 0

4 1 9 10

#endif
