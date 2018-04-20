/**
 * \file  main.cpp
 * \brief
 */


#include <StdTest.h>

#include <cstdint>

//-------------------------------------------------------------------------------------------------
int main(int, char **)
{
    std::cout << STD_TRACE_VAR(sizeof(int8_t)) << std::endl;
    std::cout << STD_TRACE_VAR(sizeof(int16_t)) << std::endl;
    std::cout << STD_TRACE_VAR(sizeof(int32_t)) << std::endl;
    std::cout << STD_TRACE_VAR(sizeof(int64_t)) << std::endl;

    std::cout << std::endl;

    std::cout << STD_TRACE_VAR(sizeof(uint8_t)) << std::endl;
    std::cout << STD_TRACE_VAR(sizeof(uint16_t)) << std::endl;
    std::cout << STD_TRACE_VAR(sizeof(uint32_t)) << std::endl;
    std::cout << STD_TRACE_VAR(sizeof(uint64_t)) << std::endl;

    return 0;
}
//-------------------------------------------------------------------------------------------------


#if OUTPUT

sizeof(int8_t):  1
sizeof(int16_t): 2
sizeof(int32_t): 4
sizeof(int64_t): 8

sizeof(uint8_t):  1
sizeof(uint16_t): 2
sizeof(uint32_t): 4
sizeof(uint64_t): 8

#endif

