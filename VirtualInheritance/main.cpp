#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <tchar.h>

#include <XLib/xCommon.h>
//---------------------------------------------------------------------------
class CInterface {
	public:
		              CInterface() { xSTD_COUT(xT(" CInterface()")); };
		 virtual     ~CInterface() { xSTD_COUT(xT("~CInterface()")); };

		 virtual void vFoo() /*= 0*/   { xSTD_COUT(xT(" CInterface::vFoo()")); };
};
//---------------------------------------------------------------------------
class CTestA : public /*virtual*/ CInterface {
	public:
		              CTestA() { xSTD_COUT(xT(" CTestA()")); };
		virtual      ~CTestA() { xSTD_COUT(xT("~CTestA()")); };

		virtual void  vFoo()   { xSTD_COUT(xT(" CTestA::vFoo()")); };
};
//---------------------------------------------------------------------------
class CTestB : public /*virtual*/ CInterface {
	public:
		              CTestB() { xSTD_COUT(xT(" CTestB()")); };
		virtual      ~CTestB() { xSTD_COUT(xT("~CTestB()")); };

		virtual void  vFoo()   { xSTD_COUT(xT(" CTestB::vFoo()")); };
};
//---------------------------------------------------------------------------
class CTestX : public CTestA, public CTestB {
	public:
		              CTestX() { xSTD_COUT(xT(" CTestX()")); };
		virtual      ~CTestX() { xSTD_COUT(xT("~CTestX()")); };

	    virtual void  vFoo()   { xSTD_COUT(xT(" CTestX::vFoo()")); };
};
//---------------------------------------------------------------------------


//---------------------------------------------------------------------------
int _tmain(int argc, TCHAR *argv[]) {
	//-------------------------------------
	{
		CTestX X;

		//X.CTestA::vFoo();
		//X.CTestB::vFoo();
		X.vFoo();
	}
	xSTD_COUT(xT("-------------------------"));
	/*
	CInterface()
	CTestA()
	CTestB()
	CTestX()
	CTestA::vFoo()
	CTestB::vFoo()
	CTestX::vFoo()
	~CTestX()
	~CTestB()
	~CTestA()
	~CInterface()
	*/

	//-------------------------------------
	////{
	////	CTestA *pI = new CTestA();
	////	pI->vFoo();
	////	delete pI;
	////}
	////xSTD_COUT(xT("-------------------------"));
	/*
	CInterface()
	CTestA()
	CTestA::vFoo()
	~CTestA()
	~CInterface()
	*/

	//-------------------------------------
	////{
	////	CTestB *pI = new CTestB();
	////	pI->vFoo();
	////	delete pI;
	////}
	////xSTD_COUT(xT("-------------------------"));
	/*
	CInterface()
	CTestB()
	CTestB::vFoo()
	~CTestB()
	~CInterface()
	*/

	//-------------------------------------
	////{
	////	CInterface *pI = new CTestA();
	////	pI->vFoo();
	////	delete pI;
	////}
	////xSTD_COUT(xT("-------------------------"));
	/*
	CInterface()
	CTestA()
	CTestA::vFoo()
	~CTestA()
	~CInterface()
	*/

	//-------------------------------------
	////{
	////	CInterface *pI = new CTestB();
	////	pI->vFoo();
	////	delete pI;
	////}
	////xSTD_COUT(xT("-------------------------"));
	/*
	CInterface()
	CTestB()
	CTestB::vFoo()
	~CTestB()
	~CInterface()
	*/


	system("pause");
	return 0;
}
//---------------------------------------------------------------------------

