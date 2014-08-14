/*********************************************************************************
   File name: DLLCode.cpp

   The header file, DLLCode.h, prototypes all of the DLL interface objects 
**********************************************************************************/
#include "Stdafx.h"
#include "DLLCode.h"
#include <iostream>

using namespace std;

void DLLfun1(char* a)
{
   cout << a << endl;
};

int DLLfun2(int a) { return a<<1; };

int DLLArg = 100;

Dllclass::Dllclass() {};

Dllclass::~Dllclass() {};

int Dllclass::Add(int a, int b)
{
   return a + b;
};

int Dllclass::Sub(int a, int b)
{
   return a - b;
};
