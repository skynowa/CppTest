/**
 * \file  RvoDisabled
 * \brief When RVO doesn’t / can’t happen
 *
 * \see   https://shaharmike.com/cpp/rvo/#when-rvo-doesn-t-can-t-happen
 *
 * Returning a Parameter / Global
 *
 * When returning an object that is not created in the scope of the function
 * there is no way to do RVO:
 */


#include <StdStream/StdStream.h>
#include <StdTest/StdTest.h>
#include <Stl.h>

#define RULE_5_OPTION_LOG 1

#include <Idioms/RuleOf/Rule5.h>
//--------------------------------------------------------------------------------------------------
Rule5 global_snitch;
//--------------------------------------------------------------------------------------------------
Rule5
returnParameter(Rule5 a_obj)
{
    return a_obj;
}
//--------------------------------------------------------------------------------------------------
Rule5
returnGlobal()
{
    return global_snitch;
}
//--------------------------------------------------------------------------------------------------
int main(int, char **)
{
    Rule5 obj  = ::returnParameter(global_snitch);
    Rule5 obj2 = ::returnGlobal();

    return EXIT_SUCCESS;
}
//--------------------------------------------------------------------------------------------------


#if OUTPUT



#endif
