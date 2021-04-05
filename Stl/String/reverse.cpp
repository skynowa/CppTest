/**
 * \file
 * \brief
 *
 * \todo
 */


//---------------------------------------------------------------------------
#include <string>
#include <iostream>
#include <assert.h>
#include <algorithm>
//---------------------------------------------------------------------------
int main()
{
   char str[] = "abcde";

   std::reverse(&str[0], &str[5]);

   std::cout << str << std::endl;

    return EXIT_SUCCESS;
}
//---------------------------------------------------------------------------


#if OUTPUT

    edcba

#endif