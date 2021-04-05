/**
 * \file  main.cpp
 * \brief Nested namespaces
 *
 * \todo
 *
 * Using the namespace resolution operator to create nested namespace definitions.
 */


#include <StdStream.h>
#include <StdTest.h>
#include <Stl.h>

//-------------------------------------------------------------------------------------------------
namespace A
{
namespace B
{
namespace C
{

int i;

}
}
}

// vs.
namespace A::B::C
{

int j;

}
//-------------------------------------------------------------------------------------------------
int main(int, char **)
{
    // std::cout << TRACE_VAR("") << std::endl;

    return EXIT_SUCCESS;
}
//-------------------------------------------------------------------------------------------------


#if OUTPUT



#endif
