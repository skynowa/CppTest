/**
 * \file
 * \brief
 *
 * \todo
 */


/*****************************************************************************************
   File name: DLLClient1.cpp
*****************************************************************************************/

#include <iostream>
#include <conio.h>
#include <windows.h>
#include "DLLCode.h"
#pragma comment(lib,"W32DLL.lib")

using namespace std;

int main()
{
   int a, b, c;
   Dllclass classFromDLL;

   classFromDLL.Arg = 6;

   a = classFromDLL.Add(3, 2);
   b = classFromDLL.Sub(3, 2);
   c = classFromDLL.Arg;


   cout << "DLL class Add function return: " << a << endl;
   cout << "DLL class Sub function return: " << b << endl;
   cout << "DLL class Arg Variable return: " << c << endl;
   cout << "Press any key to continue" << endl;
   getch();

   a = DLLArg;
   b = DLLfun2(30);
   DLLfun1("This is the string pass to function DLLfun1");
   cout << "\n\nDLL Variable DLLArg return: " << a << endl;
   cout << "DLL function DLLfun2 return: " << b << endl;
   cout << "Press any key to continue" << endl;
   getch();

   return 0;
}
