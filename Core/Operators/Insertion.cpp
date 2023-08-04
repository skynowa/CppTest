/**
 * \file  Insertion.cpp
 * \brief Output stream insertion (<<) operator for custom types
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
   std::basic_ostringstream<char> &out_os,
   const std::ustring_t           &a_value
)
{
    const std::string sRv(a_value.cbegin(), a_value.cend());

    out_os << sRv << std::flush;

    return out_os;
}
//--------------------------------------------------------------------------------------------------
int main(int, char **)
{
    const std::ustring_t sRv1(4, 'a');
    const std::ustring_t sRv2(1, '-');
    const std::ustring_t sRv3(4, 'b');

    std::ostringstream oss;
    oss << sRv1 << sRv2 << sRv3;

    std::cout << oss.str() << std::endl;

    return EXIT_SUCCESS;
}
//--------------------------------------------------------------------------------------------------

#if OUTPUT

aaaa-bbbb

#endif
