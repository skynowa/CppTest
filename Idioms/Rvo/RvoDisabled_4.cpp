/**
 * \file  RvoDisabled
 * \brief When RVO doesn’t / can’t happen
 *
 * \see   https://shaharmike.com/cpp/rvo/#when-rvo-doesn-t-can-t-happen
 *
 * Assignment
 *
 * RVO can only happen when an object is created from a returned value.
 * Using operator= on an existing object rather than copy/move constructor might be mistakenly
 * thought of as RVO, but it isn’t:
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
  return Rule5();
}
//--------------------------------------------------------------------------------------------------
int main(int, char **)
{
    Rule5 obj = ::createObj();
    obj = ::createObj();

    return EXIT_SUCCESS;
}
//--------------------------------------------------------------------------------------------------


#if OUTPUT



#endif
