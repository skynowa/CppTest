/**
 * \file  OperatorOutput.cpp
 * \brief
 */


#include <StdStream.h>
#include <StdTest.h>
#include <Stl.h>
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
using ustring_t = std::basic_string<unsigned char>;

inline std::ostream &
operator << (
	std::ostream      &a_os,
	const ::ustring_t &a_value
)
{
	StdStream::format(a_os, a_value);

	return a_os;
}
//-------------------------------------------------------------------------------------------------
int main(int, char **)
{
	::ustring_t s(10, 'g');

    std::cout << TRACE_VAR(s) << std::endl;

    return 0;
}
//-------------------------------------------------------------------------------------------------


#if OUTPUT

s: gggggggggg

#endif
