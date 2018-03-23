/**
 * \file  main.cpp
 * \brief
 */


#include <StdTest.h>

//-------------------------------------------------------------------------------------------------
namespace std
{
using ustring_t = basic_string<unsigned char>;
}
//-------------------------------------------------------------------------------------------------
class StdStream
{
public:
	template<typename T>
	static void
	format(std::ostream &a_os, const T &a_value)
	{
		a_os << (const char *)a_value.c_str();
	}
};
//-------------------------------------------------------------------------------------------------
std::ostream &
operator << (std::ostream &a_os, const std::ustring_t &a_value)
{
	StdStream::format(a_os, a_value);
	return a_os;
}

//-------------------------------------------------------------------------------------------------
int main(int, char **)
{
	std::ustring_t s(10, 'g');

    std::cout << STD_TRACE_VAR(s) << std::endl;

    return 0;
}
//-------------------------------------------------------------------------------------------------


#if OUTPUT

s: gggggggggg

#endif

