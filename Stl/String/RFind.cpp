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
void trace(
    const std::string &logTitle, ///<
    const std::string &strOrig,  ///<
    std::string       &str,      ///< [out]
    const std::string &key,      ///<
    const std::size_t  pos       ///<
)
{
    std::cout
        << "// " << logTitle << ": " << "\n"
        << "key '" << key << "' at " << STD_TRACE_VAR(pos) << std::endl;

    if (pos == std::string::npos) {
        std::cout << STD_TRACE_VAR(key) << " - Not found" << std::endl;
        return;
    }

    str.erase(pos, std::string::npos);

    std::cout
        << "Erase:\n"
        << STD_TRACE_VAR(strOrig) << " -> "
        << STD_TRACE_VAR(str) << ", "<< STD_TRACE_VAR(str.size()) << "\n"
        << std::endl;
}
//--------------------------------------------------------------------------------------------------
int main(int, char **)
{
    const std::string strOrig = "aaa|bbb|ccc|ddd|eee";
    const std::size_t sizeMax = 15;

    std::string       str     = strOrig;
    const std::string key     = "|";

    // BookedAvailGdsHotelRoom.xml
    {
        const std::size_t pos = str.rfind(key);

        ::trace("str.rfind(key)", strOrig, str, key, pos);
    }

    // BookedAvailGdsHotelRoom.xml
    {
        const std::size_t pos = str.rfind(key, sizeMax);

        ::trace("str.rfind(key, sizeMax)", strOrig, str, key, pos);
    }

    // AvailAffiliateHotelRoom.xml
    {
        const std::size_t pos = str.find(key, sizeMax);

        ::trace("str.find(key, sizeMax)", strOrig, str, key, pos);
    }

    return EXIT_SUCCESS;
}
//--------------------------------------------------------------------------------------------------
/**
 * // str.rfind(key):
 * key '|' at pos: 15
 * Erase:
 * strOrig: aaa|bbb|ccc|ddd|eee -> str: aaa|bbb|ccc|ddd, str.size(): 15
 *
 * // str.rfind(key, sizeMax):
 * key '|' at pos: 15
 * Erase:
 * strOrig: aaa|bbb|ccc|ddd|eee -> str: aaa|bbb|ccc|ddd, str.size(): 15
 *
 * // str.find(key, sizeMax):
 * key '|' at pos: 15
 * Erase:
 * strOrig: aaa|bbb|ccc|ddd|eee -> str: aaa|bbb|ccc|ddd, str.size(): 15
 */
