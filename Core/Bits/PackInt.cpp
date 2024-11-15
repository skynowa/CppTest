/**
 * \file  main.cpp
 * \brief
 *
 * \review
 */


#include <StdStream/StdStream.h>
#include <StdTest/StdTest.h>
#include <Stl.h>
//--------------------------------------------------------------------------------------------------
// Packs a 5-character string and an integer into a single uint64_t
uint64_t pack(const std::string& str, int num)
{
    uint64_t packed = 0;

    // Pack the integer in the highest 24 bits
    packed |= (static_cast<uint64_t>(num) & 0xFFFFFF) << 40;

    // Pack the first 5 characters of the string into the lower 40 bits
    for (int i = 0; i < 5; ++i) {
        // Ensure we do not go out of bounds in case the string is shorter than 5 characters
        packed |= (static_cast<uint64_t>(str[i]) & 0xFF) << (8 * (4 - i));
    }

    return packed;
}
//--------------------------------------------------------------------------------------------------
// Unpacks the uint64_t back into a 5-character string and an integer
void unpack(uint64_t packed, std::string& str, int& num)
{
    // Unpack the integer from the highest 24 bits
    num = static_cast<int>((packed >> 40) & 0xFFFFFF);

    // Unpack the 5-character string from the lower 40 bits
    str.clear(); // Clear the string before appending characters
    for (int i = 0; i < 5; ++i) {
        str.push_back(static_cast<char>((packed >> (8 * (4 - i))) & 0xFF));
    }
}
//--------------------------------------------------------------------------------------------------
int main(int, char **)
{
    const std::string originalStr = "en-US";
    const int         originalNum = 42;

    // Pack the string and integer into a single uint64_t
    const uint64_t packed = ::pack(originalStr, originalNum);

    // Unpack them back
    std::string unpackedStr;
    int         unpackedNum {};
    ::unpack(packed, unpackedStr, unpackedNum);

    std::cout << STD_TRACE_VAR2(originalStr, originalNum) << std::endl;
    std::cout << STD_TRACE_VAR2(unpackedStr, unpackedNum) << std::endl;

    return EXIT_SUCCESS;
}
//--------------------------------------------------------------------------------------------------


#if OUTPUT

originalStr: en-US, originalNum: 42
unpackedStr: en-US, unpackedNum: 42

#endif
