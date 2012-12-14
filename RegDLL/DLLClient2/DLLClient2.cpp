/*****************************************************************************************
   File name: DLLClient2.cpp
*****************************************************************************************/

#include <iostream>
#include <conio.h>      // Header file containing getch() prototype
#include <windows.h>

using namespace std; 

int main()
{
  typedef void (*MYFUN1)(char*); // type definition, pointer to: void function(char*)
  typedef int  (*MYFUN2)(int);   // type definition, pointer to: int  function(int)

  MYFUN1  pfun1;              // declaration for the typedef function
  MYFUN2  pfun2;              // declaration for the typedef function
  HMODULE hMod;               // handle to loaded library module
  BOOL    bRes;               // BOOL to check if dll was successfully unloaded

  // returns a handle to the dll, otherwise NULL
  hMod = LoadLibrary("W32DLL.dll"); 

  // returns the address of the dll function, otherwise NULL
  pfun1 = (MYFUN1) GetProcAddress(hMod, "DLLfun1");
  pfun2 = (MYFUN2) GetProcAddress(hMod, "DLLfun2");

  // (Dll function address) (function parameters)
  (pfun1)("This is the string pass to function DLLfun1");

  // (Dll function address) (function parameters)
  int a = (pfun2) (30);
 
  cout << "\nDLL function DLLfun2 return: " << a << endl;
  cout << "Press any key to continue" << endl;
  getch();


  ///////////////////////////////////////////////////////
  // This code will run if you compile the W32DLL project
  // with the W32DLL.def file to explicitly export DLLArg.

  int *i;
  i = (int*) GetProcAddress(hMod, "DLLArg");
  if (i)
  {
	  cout << "Variable DLLArg is: " << *i << endl;
  };

  cout << "Press a key to exit" << endl;
  getch();


  // returns nonzero if sucussful 
  bRes = FreeLibrary(hMod); 

  return 0;
}
