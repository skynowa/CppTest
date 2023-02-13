/**
 * \file  RvoDisabled
 * \brief When RVO doesn’t / can’t happen
 *
 * \see   https://shaharmike.com/cpp/rvo/#when-rvo-doesn-t-can-t-happen
 */


#include <StdStream/StdStream.h>
#include <StdTest/StdTest.h>
#include <Stl.h>

#define RULE_5_OPTION_LOG 1

#include <Idioms/RuleOf/Rule5.h>
//--------------------------------------------------------------------------------------------------
int main(int, char **)
{
   /**
    * Deciding on Instance at Runtime
    *
    * When the compiler can’t know from within the function which instance will be returned
    * it must disable RVO:
    */
    {

    }

   /**
    * Returning a Parameter / Global
    *
    * When returning an object that is not created in the scope of the function
    * there is no way to do RVO:
    */
    {

    }

   /**
    * Returning by std::move()
    *
    * Returning by calling std::move() on the return value is an anti-pattern.
    * It is wrong most of the times. It will indeed attempt to force move-constructor,
    * but in doing so it will disable RVO. It is also redundant, as move will happen
    * if it can even without explicitly calling std::move()
    */
    {

    }

   /**
    * Assignment
    *
    * RVO can only happen when an object is created from a returned value.
    * Using operator= on an existing object rather than copy/move constructor might be mistakenly
    * thought of as RVO, but it isn’t:
    */
    {

    }

   /**
    * Returning Member
    *
    * In some cases even an unnamed variable can’t RVO:
    */
    {

    }


    return EXIT_SUCCESS;
}
//--------------------------------------------------------------------------------------------------


#if OUTPUT



#endif
