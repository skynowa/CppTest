/**
 * \file  main.cpp
 * \brief
 *
 * COMMENTS
 */


#include <StdStream.h>
#include <StdTest.h>
#include <Stl.h>

#include <iostream>
#include <cstdlib>
//-------------------------------------------------------------------------------------------------
class Static
{
public:
    ~Static()
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
Static static_variable; // dtor of this object *will* be called

void atexit_handler()
{
    STD_TRACE_FUNC;
}
//-------------------------------------------------------------------------------------------------
int main(int, char **)
{
    int iRv {};

    Local local_variable; // dtor of this object will *not* be called

    iRv = std::atexit(atexit_handler); // handler will be called
    STD_TEST_RET(iRv == 0, EXIT_FAILURE);

    std::exit(EXIT_FAILURE);

    std::cout << "After std::exit()" << std::endl;
    // std::cout << TRACE_VAR("") << std::endl;

    return EXIT_SUCCESS;
}
//-------------------------------------------------------------------------------------------------


#if OUTPUT



#endif
