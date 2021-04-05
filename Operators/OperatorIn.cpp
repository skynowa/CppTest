/**
 * \file
 * \brief
 *
 * \todo
 */


//---------------------------------------------------------------------------
#include <assert.h>
#include <string>
#include <iostream>
#include <sstream>
//---------------------------------------------------------------------------
namespace std {
   typedef basic_string<unsigned char, char_traits<unsigned char>, allocator<unsigned char> > ustring_t;
}
//---------------------------------------------------------------------------
std::basic_ostringstream<char>&
operator << (
   std::basic_ostringstream<char> &osOut,
   const std::ustring_t           &cusValue
)
{
    std::string sRv;

    sRv.assign( cusValue.begin(), cusValue.end() );

    osOut << sRv << std::flush;

    return osOut;
}
//---------------------------------------------------------------------------
int main()
{
    std::ostringstream ossStream;
    std::ustring_t     sRv1(4, 'a');
    std::ustring_t     sRv2(4, 'b');

    ossStream << sRv1 << sRv2;

    std::cout << ossStream.str() << std::endl;

    return 0;
}
//---------------------------------------------------------------------------
#if OUTPUT
// NOTE:

> ./main

    aaaabbbb

#endif