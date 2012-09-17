/**
 * \file  FunctionPointer.cpp
 * \brief pointer to function
 */

 
#include <iostream>
#include <string>

//---------------------------------------------------------------------------
int (*piFunc)(const std::string &csVal) = NULL;
//---------------------------------------------------------------------------
int 
iFunc(const std::string &csVal) {
   std::cout << csVal << std::endl;
   
   return 0;  
}
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
int 
main() {
   piFunc = iFunc;

   (*iFunc)("Test!!");
   iFunc("Test!!");   
  
   (*piFunc)("Test!!");
   piFunc("Test!!");    
     
   return 0;
}
//---------------------------------------------------------------------------
