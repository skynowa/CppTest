/**
 * \file  RFind.cpp
 * \brief Find last occurrence of content in string
 *
 * \see   https://cplusplus.com/reference/string/string/rfind/
 */


#include <StdStream/StdStream.h>
#include <StdTest/StdTest.h>
#include <Stl.h>
//--------------------------------------------------------------------------------------------------
int main(int, char **)
{
    const std::string strOrig = "aaa|bbb|ccc|ddd";
    std::string       str     = strOrig;
    const std::string key     = "|";

    const std::size_t pos = str.rfind(key);
    if (pos == std::string::npos) {
        return EXIT_FAILURE;
    }

    std::cout << "key '" << key << "' at " << STD_TRACE_VAR(pos) << std::endl;

    str.erase(pos);

    std::cout
        << "Erase: "
        << STD_TRACE_VAR(strOrig) << " -> " << STD_TRACE_VAR(str) << std::endl;

    return EXIT_SUCCESS;
}
//--------------------------------------------------------------------------------------------------


#if OUTPUT

key '|' at pos: 11
Erase: strOrig: aaa|bbb|ccc|ddd -> str: aaa|bbb|ccc

#endif
