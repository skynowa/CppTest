/**
 * \file  RvoDisabled
 * \brief When RVO doesn’t / can’t happen
 *
 * \see   https://shaharmike.com/cpp/rvo/#when-rvo-doesn-t-can-t-happen
 *
 *
 * Deciding on Instance at Runtime
 *
 * When the compiler can’t know from within the function which instance will be returned
 * it must disable RVO:
 */


#include <StdStream/StdStream.h>
#include <StdTest/StdTest.h>
#include <Stl.h>

#define RULE_5_OPTION_LOG 1

#include <Idioms/RuleOf/Rule5.h>
//--------------------------------------------------------------------------------------------------
Rule5
createObj(const bool a_isRuntimeCondition)
{
    Rule5 a, b;

    if (a_isRuntimeCondition) {
        return a;
    }

    return b;
}
//--------------------------------------------------------------------------------------------------
int main(int, char **)
{
    Rule5 obj = ::createObj(true);

    return EXIT_SUCCESS;
}
//--------------------------------------------------------------------------------------------------


#if OUTPUT



#endif
