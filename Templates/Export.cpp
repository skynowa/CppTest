/**
 * \file  Export.cpp
 * \brief
 */


#include "Export.h"

//-------------------------------------------------------------------------------------------------
template<typename T>
T
func(const T a_value)
{
    return a_value;
}
//-------------------------------------------------------------------------------------------------
int main(int, char **)
{
    std::cout << TRACE_VAR(func(111)) << std::endl;

    return 0;
}
//-------------------------------------------------------------------------------------------------


#if OUTPUT



#endif

