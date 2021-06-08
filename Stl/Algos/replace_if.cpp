/**
 * \file  replace_if.cpp
 * \brief
 *
 * \todo
 */


#include <StdStream.h>
#include <StdTest.h>
#include <Stl.h>
//-------------------------------------------------------------------------------------------------
bool
functor(const char a_it)
{
	return !std::isalnum( static_cast<int>(a_it) );
}
//-------------------------------------------------------------------------------------------------
int main(int, char **)
{
	std::string value = "Su tton (London,UK)";

	value.erase(std::remove_if(value.begin(), value.end(), functor), value.end());

	std::cout << TRACE_VAR(value) << std::endl;

	return 0;
}
//-------------------------------------------------------------------------------------------------


#if OUTPUT

value: SuttonLondonUK

#endif
