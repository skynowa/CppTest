/**
 * \file  StaticHolder.cpp
 * \brief
 */


#include <StdStream/StdStream.h>
#include <StdTest/StdTest.h>
#include <Stl.h>
//-------------------------------------------------------------------------------------------------
template<int valueT>
struct StaticHolder
{
   static int value;
};

template<int valueT>
int StaticHolder<valueT>::value {valueT};

using int_static_holder_t = StaticHolder<3>;
//-------------------------------------------------------------------------------------------------
int main(int, char **)
{
    int_static_holder_t holder;

    std::cout << TRACE_VAR(holder.value) << std::endl;

    return EXIT_SUCCESS;
}
//-------------------------------------------------------------------------------------------------


#if OUTPUT

holder.value: 3

#endif
