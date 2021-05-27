 /*
 * \file  GlobalVar2.cpp
 * \brief
 */


#include <StdStream.h>
#include <StdTest.h>
#include <Stl.h>
//-------------------------------------------------------------------------------------------------
void onExit()
{
    std::cout << __FUNCTION__ << std::endl;
}
//-------------------------------------------------------------------------------------------------
class Global
{
public:
    ~Global()
    {
        std::cout << __FUNCTION__ << std::endl;
    }
};
//-------------------------------------------------------------------------------------------------
class Local
{
public:
    ~Local()
    {
        std::cout << __FUNCTION__ << std::endl;
    }
};
//-------------------------------------------------------------------------------------------------


Global Global_variable; // dtor of this object *will* be called

//-------------------------------------------------------------------------------------------------
int main(int, char **)
{
    Local local_variable; // !!! dtor of this object will *not* be called !!!

    const int iRv = std::atexit(onExit); // handler will be called
    if (iRv != 0) {
        std::cerr << "atexit registration failed" << std::endl;
        return EXIT_FAILURE;
    }

    std::cout << __FUNCTION__ << std::endl;

#if 1
    // Local - dtor will *not* be called !!!
    std::exit(EXIT_SUCCESS);
#else
    // Local - dtor will be *called* !!!
    return EXIT_SUCCESS;
#endif
}
//-------------------------------------------------------------------------------------------------


#if OUTPUT

main
onExit
~Global

#endif
