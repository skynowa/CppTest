 /*
 * \file  Main.cpp
 * \brief exception
 *
 * \todo
 */


//---------------------------------------------------------------------------
#include <string>
#include <iostream>
#include <assert.h>
//---------------------------------------------------------------------------
void foo() {
    std::cout << __FUNCTION__ << " - begin" << std::endl;

    throw 1.0;

    // if type of exception differs from 'int',
    // for example: double (1.0), unsigned int (1U), etc
    // than output (unhandled exception):
    //     foo - begin

    std::cout << __FUNCTION__ << " - end"   << std::endl;
}
//---------------------------------------------------------------------------
int main()
{
   try {
      foo();
      std::cout << "foo() done" << std::endl;
   }
   catch (const int &i) {
      std::cout << "catch (int &i) - begin" << std::endl;
      throw;
      std::cout << "catch (int &i) - end"   << std::endl;
   }

   std::cout << "finished" << std::endl;

   return EXIT_SUCCESS;
}
//---------------------------------------------------------------------------



#if OUTPUT_GCC

foo - begin
catch (int &i) - begin


stderr:
terminate called after throwing an instance of 'int'

#endif

#if OUTPUT_MSVC

Unhandled exception at at 0x752DB9BC in Exception.exe:
Microsoft C++ exception: int at memory location 0x0020FBAC

#endif
