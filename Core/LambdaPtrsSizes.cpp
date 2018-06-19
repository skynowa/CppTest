/**
 * \file  main.cpp
 * \brief
 */


#include "../StdTest.h"

#include <functional>
#include <memory>

//-------------------------------------------------------------------------------------------------
int main(int, char **)
{
	std::function<void()> functor;

	auto lambdaEmpty = []() { };

	std::array<char, 100> chars;
	auto lambdaArray100ByRef   = [&chars](){};
	auto lambdaArray100ByValue = [chars](){};

	std::unique_ptr<int> uniquePtr = std::make_unique<int>(123);

    std::cout
    	<< STD_TRACE_VAR(sizeof(functor))            << "\n"
    	<< STD_TRACE_VAR(sizeof(lambdaEmpty))        << "\n"
    	<< STD_TRACE_VAR(sizeof(lambdaArray100ByRef))   << "\n"
    	<< STD_TRACE_VAR(sizeof(lambdaArray100ByValue)) << "\n"
    	<< STD_TRACE_VAR(sizeof(uniquePtr))          << "\n"
    	<< STD_TRACE_VAR(sizeof(uniquePtr.get()))    << "\n"
    	<< STD_TRACE_VAR("") << std::endl;

    return 0;
}
//-------------------------------------------------------------------------------------------------


#if OUTPUT



#endif
