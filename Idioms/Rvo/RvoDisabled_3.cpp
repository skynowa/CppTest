/**
 * \file  RvoDisabled
 * \brief When RVO doesn’t / can’t happen
 *
 * \see   https://shaharmike.com/cpp/rvo/#when-rvo-doesn-t-can-t-happen
 *
 *
 * Returning by std::move()
 *
 * Returning by calling std::move() on the return value is an anti-pattern.
 * It is wrong most of the times. It will indeed attempt to force move-constructor,
 * but in doing so it will disable RVO. It is also redundant, as move will happen
 * if it can even without explicitly calling std::move()
 */


#include <StdStream/StdStream.h>
#include <StdTest/StdTest.h>
#include <Stl.h>

#define RULE_5_OPTION_LOG 1

#include <Idioms/RuleOf/Rule5.h>
//--------------------------------------------------------------------------------------------------
Rule5
createObj()
{
  Rule5 obj;

  return std::move(obj);
}
//--------------------------------------------------------------------------------------------------
int main(int, char **)
{
    Rule5 obj = ::createObj();

    return EXIT_SUCCESS;
}
//--------------------------------------------------------------------------------------------------


#if OUTPUT



#endif
