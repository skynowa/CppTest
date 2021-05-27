/**
 * \file  TypeSizes.cpp
 * \brief
 */


#include <StdStream.h>
#include <StdTest.h>
#include <Stl.h>
//-------------------------------------------------------------------------------------------------
int main(int, char **)
{
    std::cout << TRACE_VAR(sizeof(int8_t)) << std::endl;
    std::cout << TRACE_VAR(sizeof(int16_t)) << std::endl;
    std::cout << TRACE_VAR(sizeof(int32_t)) << std::endl;
    std::cout << TRACE_VAR(sizeof(int64_t)) << std::endl;

    std::cout << std::endl;

    std::cout << TRACE_VAR(sizeof(uint8_t)) << std::endl;
    std::cout << TRACE_VAR(sizeof(uint16_t)) << std::endl;
    std::cout << TRACE_VAR(sizeof(uint32_t)) << std::endl;
    std::cout << TRACE_VAR(sizeof(uint64_t)) << std::endl;

    return EXIT_SUCCESS;
}
//-------------------------------------------------------------------------------------------------


#if OUTPUT

sizeof(int8_t): 1
sizeof(int16_t): 2
sizeof(int32_t): 4
sizeof(int64_t): 8

sizeof(uint8_t): 1
sizeof(uint16_t): 2
sizeof(uint32_t): 4
sizeof(uint64_t): 8

#endif
