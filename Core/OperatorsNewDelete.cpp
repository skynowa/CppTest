/**
 * \file
 * \brief
 *
 * \todo
 */


#include <StdStream.h>
#include <StdTest.h>
#include <Stl.h>

//-------------------------------------------------------------------------------------------------
// replace operator new and delete to log allocations
void *
operator new(std::size_t n)
{
    std::cout << __FUNCTION__ << ": [Allocating " << n << " bytes]\n";
    return malloc(n);
}
//-------------------------------------------------------------------------------------------------
void
operator delete(void* p)
{
    std::cout << __FUNCTION__ << std::endl;
    free(p);
}
//-------------------------------------------------------------------------------------------------
std::string
buildLongString()
{
    return "This string is so long it can't possibly be inline (SSO)";
}
//-------------------------------------------------------------------------------------------------
int main(int, char **)
{
    buildLongString();

    // std::cout << TRACE_VAR("") << std::endl;

    return 0;
}
//-------------------------------------------------------------------------------------------------


#if OUTPUT

operator new: [Allocating 57 bytes]
operator delete

#endif
