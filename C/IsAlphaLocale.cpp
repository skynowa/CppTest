/**
 * \file  IsAlphaLocale.cpp
 * \brief std::isalpha with locale
 */


#include <StdStream/StdStream.h>
#include <StdTest/StdTest.h>
#include <Stl.h>
//--------------------------------------------------------------------------------------------------
int main(int, char **)
{
    // немецкая буква ß в ISO-8859-1
    const unsigned char ch = '\xdf';

    {
        const auto is_alpha = static_cast<bool>( std::isalpha(ch) );

        std::cout
            << "std::isalpha(\'\\xdf\', Locale: default C) - "
            << std::boolalpha << is_alpha << std::endl;
    }

    {
        std::setlocale(LC_ALL, "de_DE.iso88591");

        const auto is_alpha = static_cast<bool>( std::isalpha(ch) );

        std::cout
            << "std::isalpha(\'\\xdf\', Locale: ISO-8859-1) - "
            << std::boolalpha << is_alpha << std::endl;
    }

    return EXIT_SUCCESS;
}
//--------------------------------------------------------------------------------------------------


#if OUTPUT

isalpha('\xdf', default C locale)  - false
isalpha('\xdf', ISO-8859-1 locale) - false /// TODO: must be - true

#endif
