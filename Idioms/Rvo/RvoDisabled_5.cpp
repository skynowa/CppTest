/**
 * \file  RvoDisabled
 * \brief When RVO doesn’t / can’t happen
 *
 * \see   https://shaharmike.com/cpp/rvo/#when-rvo-doesn-t-can-t-happen
 *
 *
 * Returning Member
 *
 * In some cases even an unnamed variable can’t RVO:
 */


#include <StdStream/StdStream.h>
#include <StdTest/StdTest.h>
#include <Stl.h>

#define RULE_5_OPTION_LOG 1

#include <Idioms/RuleOf/Rule5.h>
//--------------------------------------------------------------------------------------------------
struct Wrapper
{
    Rule5 obj;
};
//--------------------------------------------------------------------------------------------------
Rule5 foo()
{
    return Wrapper().obj;
}
//--------------------------------------------------------------------------------------------------
int main(int, char **)
{
    Rule5 s = ::foo();

    return EXIT_SUCCESS;
}
//--------------------------------------------------------------------------------------------------


#if OUTPUT



#endif
