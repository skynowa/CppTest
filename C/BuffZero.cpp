/**
 * \file  BuffZero.cpp
 * \brief
 *
 * \todo
 */

//---------------------------------------------------------------------------
#include <string>
#include <iostream>
#include <assert.h>
//---------------------------------------------------------------------------
int main(int, char **)
{
    const size_t cuiBuffSize = 5;

   {
        char szBuff[cuiBuffSize] {};

        for (size_t i = 0; i < cuiBuffSize; ++ i) {
            std::cout << "["<< szBuff[0] << "]" << std::endl;
        }

        std::cout << std::endl;

    #if OUTPUT

        [ ]
        [ ]
        [ ]
        [ ]
        [ ]

    #endif
    }

    {
        char *pszBuff = new char[cuiBuffSize];

        for (size_t i = 0; i < cuiBuffSize; ++ i) {
            std::cout << "["<< pszBuff[0] << "]" << std::endl;
        }

        std::cout << std::endl;

    #if OUTPUT

        [═]
        [═]
        [═]
        [═]
        [═]

    #endif
    }

    {
        char *pszBuff = new char[cuiBuffSize]();

        for (size_t i = 0; i < cuiBuffSize; ++ i) {
            std::cout << "["<< pszBuff[0] << "]" << std::endl;
        }

        std::cout << std::endl;

    #if OUTPUT

        [ ]
        [ ]
        [ ]
        [ ]
        [ ]

    #endif
    }

    return EXIT_SUCCESS;
}
//---------------------------------------------------------------------------
