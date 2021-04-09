/**
 * \file  DLLCode.cpp
 * \brief
 */


/*****************************************************************************************
   File name: DLLCode.cpp

   The header file, DLLCode.h, prototypes all of the DLL interface objects
*****************************************************************************************/
#include "StdAfx.h"
#include "DLLCode.h"

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

void DrawEllipse ( CRect rect, CDC *pDC )
{

	CBrush brush;
	brush.CreateSolidBrush(RGB(0,0,255));
	pDC->SelectObject(&brush);

	pDC->Ellipse(&rect);
};
