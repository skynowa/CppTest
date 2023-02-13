/**
 * \file  In.cpp
 * \brief
 */


#include <StdStream/StdStream.h>
#include <StdTest/StdTest.h>
#include <Stl.h>
//--------------------------------------------------------------------------------------------------
namespace std
{

using ustring_t = basic_string<unsigned char, char_traits<unsigned char>, allocator<unsigned char>>;

}
//--------------------------------------------------------------------------------------------------
std::basic_ostringstream<char>&
operator << (
   std::basic_ostringstream<char> &osOut,
   const std::ustring_t           &cusValue
)
{
    std::string sRv(cusValue.cbegin(), cusValue.cend());

    osOut << sRv << std::flush;

    return osOut;
}
//--------------------------------------------------------------------------------------------------
int main()
{
    std::ostringstream ossStream;
    std::ustring_t     sRv1(4, 'a');
    std::ustring_t     sRv2(4, 'b');

    ossStream << sRv1 << sRv2;

    std::cout << ossStream.str() << std::endl;

    return EXIT_SUCCESS;
}
//--------------------------------------------------------------------------------------------------

#if OUTPUT

aaaabbbb

#endif