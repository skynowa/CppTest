/**
 * \file  NestedNamespaces.cpp
 * \brief Nested namespaces
 *
 * Using the namespace resolution operator to create nested namespace definitions.
 */


#include <StdStream/StdStream.h>
#include <StdTest/StdTest.h>
#include <Stl.h>
//-------------------------------------------------------------------------------------------------
namespace A
{
namespace B
{
namespace C
{

int i {11};

}
}
}

// vs.
namespace A::B::C
{

int j {17};

}
//-------------------------------------------------------------------------------------------------
int main(int, char **)
{
    std::cout << TRACE_VAR(A::B::C::i) << std::endl;
    std::cout << TRACE_VAR(A::B::C::j) << std::endl;

    return EXIT_SUCCESS;
}
//-------------------------------------------------------------------------------------------------


#if OUTPUT

A::B::C::i: 11
A::B::C::j: 17

#endif
