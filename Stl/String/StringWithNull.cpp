/**
 * \file  StringWithNull.cpp
 * \brief
 */


#include <StdStream/StdStream.h>
#include <StdTest/StdTest.h>
#include <Stl.h>
//--------------------------------------------------------------------------------------------------
int main(int, char **)
{
    // #1
    {
        std::string sFileName;
        sFileName.push_back('x');
        sFileName.push_back('\0');
        sFileName.push_back('y');

        std::string sExceptedChars = "/\0";

        // STD_TEST_PTR(sExceptedChars.size() == 2); - raise!!!

        size_t uiPos = sFileName.find_first_of(sExceptedChars);
        if (std::string::npos == uiPos) {
            std::cout << "Not found" << std::endl;
        } else {
            std::cout << "Found" << std::endl;
        }

        #if OUTPUT
            Not found
        #endif
    }

    // #2
    {
        std::string sFileName;
        sFileName.push_back('x');
        sFileName.push_back('\0');
        sFileName.push_back('y');

        std::string sExceptedChars;
        sExceptedChars.push_back('/');
        sExceptedChars.push_back('\0');

        STD_TEST_PTR(sExceptedChars.size() == 2);

        size_t uiPos = sFileName.find_first_of(sExceptedChars);
        if (std::string::npos == uiPos) {
            std::cout << "Not found" << std::endl;
        } else {
            std::cout << "Found" << std::endl;
        }

        #if OUTPUT
            Found
        #endif
    }

    // #3
    {
        std::string sFileName;
        sFileName.push_back('x');
        sFileName.push_back('\0');
        sFileName.push_back('y');

        char szExceptedChars[] = {'/', '\0', '\0'};

        size_t uiPos = sFileName.find_first_of(szExceptedChars);
        if (std::string::npos == uiPos) {
            std::cout << "Not found" << std::endl;
        } else {
            std::cout << "Found" << std::endl;
        }

        #if OUTPUT
            Not found
        #endif
    }

    // #4
    {
        std::string sFileName;
        sFileName.push_back('x');
        sFileName.push_back('\0');
        sFileName.push_back('y');

        char chExceptedChars = '\0';

        size_t uiPos = sFileName.find_first_of(chExceptedChars);
        if (std::string::npos == uiPos) {
            std::cout << "Not found" << std::endl;
        } else {
            std::cout << "Found" << std::endl;
        }

        #if OUTPUT
            Found
        #endif
    }

    return EXIT_SUCCESS;
}
//--------------------------------------------------------------------------------------------------

#if OUTPUT

Not found
Found
Not found
Found

#endif
