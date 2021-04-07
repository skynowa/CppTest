/**
 * \file  InvertString.cpp
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
invert_string(T &a)
{
	typename T::size_type length = a.size();

	for (typename T::size_type i = 0; i < (length / 2); ++ i) {
		std::swap(a[i], a[length - i - 1]);
	}
}
//-------------------------------------------------------------------------------------------------
int main(int, char **)
{
    std::string str = "abcdefg";
    ::invert_string(str);

    std::cout << TRACE_VAR(str) << std::endl;

    return EXIT_SUCCESS;
}
//-------------------------------------------------------------------------------------------------


#if OUTPUT



#endif
