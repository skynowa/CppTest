/**
 * \file  NewDelete.cpp
 * \brief replace operator new and delete to log allocations
 */


#include <StdStream/StdStream.h>
#include <StdTest/StdTest.h>
#include <Stl.h>
//-------------------------------------------------------------------------------------------------
void *
operator new(std::size_t n)
{
    std::cout << __FUNCTION__ << ": [Allocating " << n << " bytes]\n";

    return malloc(n);
}
//-------------------------------------------------------------------------------------------------
void
operator delete(void *p)
{
    std::cout << __FUNCTION__ << std::endl;

    free(p);
}
//-------------------------------------------------------------------------------------------------
void
operator delete(void *p, std::size_t n)
{
    STD_UNUSED(n);

    std::cout << __FUNCTION__ << std::endl;

    free(p);
}
//-------------------------------------------------------------------------------------------------
std::string
buildString()
{
    return "This string is so long it can't possibly be inline (SSO)";
}
//-------------------------------------------------------------------------------------------------
int main(int, char **)
{
    buildString();

    return EXIT_SUCCESS;
}
//-------------------------------------------------------------------------------------------------


#if OUTPUT

operator new: [Allocating 57 bytes]
operator delete

#endif
