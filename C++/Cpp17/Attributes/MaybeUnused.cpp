/**
 * \file  maybe_unused.cpp
 * \brief [[maybe_unused]]
 *
 * This attribute is used to suppress compiler/analyzer warnings for unused variables,
 * function parameters, static functions, and more.
 */


#include <StdStream/StdStream.h>
#include <StdTest/StdTest.h>
#include <Stl.h>
//-------------------------------------------------------------------------------------------------
// The warning will be suppressed
[[maybe_unused]] static void SomeUnusedFunc() { /* .... */ }

// The warning will be suppressed
void Foo([[maybe_unused]] int a) { /* .... */ }

void Func()
{
  // The warning will be suppressed
  [[maybe_unused]] int someUnusedVar = 42;
  //....
}
//-------------------------------------------------------------------------------------------------
int main(int, char **)
{
    return EXIT_SUCCESS;
}
//-------------------------------------------------------------------------------------------------


#if OUTPUT

// no warnings

#endif
