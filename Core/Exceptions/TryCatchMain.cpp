/**
 * \file  TryCatchMain.cpp
 * \brief Main without braces in try/catch
 */


#include <StdStream/StdStream.h>
#include <StdTest/StdTest.h>
#include <Stl.h>
//--------------------------------------------------------------------------------------------------
int main(int, char **)

try	{
	std::vector<int> v;

	int value = v.at(0);
	std::cout << STD_TRACE_VAR(value) << std::endl;

	return EXIT_SUCCESS;
}
catch (const std::exception &a_ex) {
	std::cout << STD_TRACE_VAR(a_ex.what()) << std::endl;

	return EXIT_FAILURE;
}
catch (...) {
	std::cout << "Unknown" << std::endl;

	return EXIT_FAILURE;
}
//--------------------------------------------------------------------------------------------------


#if OUTPUT

e.what(): vector::_M_range_check: __n (which is 0) >= this->size() (which is 0)

#endif
