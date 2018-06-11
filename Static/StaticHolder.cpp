 /*
 * \file  main.cpp
 * \brief
 */


#include <StdTest.h>
#include <string>
#include <iostream>
#include <assert.h>
//-------------------------------------------------------------------------------------------------
template<int valueT>
struct StaticHolder
{
   static int value;
};

template<int valueT>
int StaticHolder<valueT>::value = valueT;

typedef StaticHolder<3> IntStaticHolder;
//-------------------------------------------------------------------------------------------------
int main(int, char **)
{
    IntStaticHolder holder;

    std::cout << STD_TRACE_VAR(holder.value) << std::endl;

    return 0;
}
//-------------------------------------------------------------------------------------------------


#if OUTPUT

holder.value: 3

#endif
