/**
 * \file  stringWithNull.cpp
 * \brief
 */


#include <StdStream.h>
#include <StdTest.h>
#include <Stl.h>
//--------------------------------------------------------------------------------------------------
int main(int, char **)
{
    {
        std::string sFileName;
        sFileName.push_back('x');
        sFileName.push_back('\0');
        sFileName.push_back('y');

        std::string sExceptedChars = "/\0";

        // assert(2 == sExceptedChars.size()); - raise!!!

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

    {
        std::string sFileName;
        sFileName.push_back('x');
        sFileName.push_back('\0');
        sFileName.push_back('y');

        std::string sExceptedChars;
        sExceptedChars.push_back('/');
        sExceptedChars.push_back('\0');

        assert(2 == sExceptedChars.size());

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

    {
        std::string sFileName;
        sFileName.push_back('x');
        sFileName.push_back('\0');
        sFileName.push_back('y');

        char        szExceptedChars[] = {'/', '\0', '\0'};

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

    {
        std::string sFileName;
        sFileName.push_back('x');
        sFileName.push_back('\0');
        sFileName.push_back('y');

        char        chExceptedChars = '\0';

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
