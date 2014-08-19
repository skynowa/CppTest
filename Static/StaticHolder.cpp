 /*
 * \file  main.cpp
 * \brief
 */


#include <string>
#include <iostream>
#include <assert.h>

//-------------------------------------------------------------------------------------------------
#define TRACE_VAR(v) \
    #v ": " << (v)
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
int main(int argsNum, char **args)
{
    IntStaticHolder holder;

    std::cout << TRACE_VAR(holder.value) << std::endl;

    return 0;
}
//-------------------------------------------------------------------------------------------------


#if OUTPUT

holder.value: 3

#endif
 /*
 * \file  main.cpp
 * \brief
 */


#include <string>
#include <iostream>
#include <assert.h>

//-------------------------------------------------------------------------------------------------
#define TRACE_VAR(v) \
    #v ": " << (v)
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
int main(int argsNum, char **args)
{
    IntStaticHolder holder;

    std::cout << TRACE_VAR(holder.value) << std::endl;

    return 0;
}
//-------------------------------------------------------------------------------------------------


#if OUTPUT

holder.value: 3

#endif
