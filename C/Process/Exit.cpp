/**
 * \file  Exit.cpp
 * \brief
 */


#include <StdStream/StdStream.h>
#include <StdTest/StdTest.h>
#include <Stl.h>

#include <iostream>
#include <cstdlib>
//-------------------------------------------------------------------------------------------------
class Static1
{
public:
    ~Static1()
    {
        STD_TRACE_FUNC;
    }
};
//-------------------------------------------------------------------------------------------------
class Static2
{
public:
    ~Static2()
    {
        STD_TRACE_FUNC;
    }
};
//-------------------------------------------------------------------------------------------------
class Global
{
public:
    ~Global()
    {
        STD_TRACE_FUNC;
    }
};
//-------------------------------------------------------------------------------------------------
class Local
{
public:
    ~Local()
    {
        STD_TRACE_FUNC;
    }
};
//-------------------------------------------------------------------------------------------------
void onExit()
{
    STD_TRACE_FUNC;
}
//-------------------------------------------------------------------------------------------------
static Static1 staticVar1;  // dtor of this object *will* be called
Global globalVar;           // dtor of this object *will* be called

int main(int, char **)
{
    static Static2 staticVar2;  // dtor of this object *will* be called
    Local          localVar;    // dtor of this object will *not* be called

    int iRv = std::atexit(onExit); // handler will be called
    STD_TEST_RET(iRv == 0, EXIT_FAILURE);

    std::exit(EXIT_FAILURE);

    std::cout << "After std::exit()" << std::endl;  // code not reached
    // std::cout << STD_TRACE_VAR("") << std::endl;

    return EXIT_SUCCESS;
}
//-------------------------------------------------------------------------------------------------


#if OUTPUT

::: onExit :::
::: ~Static2 :::
::: ~Global :::
::: ~Static1 :::

#endif
