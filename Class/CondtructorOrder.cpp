/**
 * \file
 * \brief
 *
 * \todo
 */


#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <list>
#include <map>
//---------------------------------------------------------------------------
class CTestA {
	char szArray[256];

	public:
		 CTestA() { std::cout << " CTestA()" << std::endl; };
		~CTestA() { std::cout << "~CTestA()" << std::endl; };
};
//---------------------------------------------------------------------------
class CTestB {
	public:
		 CTestB() { std::cout << " CTestB()" << std::endl; };
		~CTestB() { std::cout << "~CTestB()" << std::endl; };

};
//---------------------------------------------------------------------------
class CTestC {
	public:
		 CTestC() { std::cout << " CTestC()" << std::endl; };
		~CTestC() { std::cout << "~CTestC()" << std::endl; };

};
//---------------------------------------------------------------------------
class CEmpty {
	public:
		const int ciConst;

		CEmpty() : ciConst(3000)  {;};
		~CEmpty() {;};

		//virtual void vVirtualMeth() {;}
		std::string  sGetName1   () { return "simple string";}
		std::string  sGetName2   () { return "simple string";}
};
//---------------------------------------------------------------------------
struct SEmpty {
	public:
		SEmpty() {;};
		~SEmpty() {;};

		//virtual void vVirtualMeth() {;}

		std::string sGetName1() { return "simple string";}
		std::string sGetName2() { return "simple string";}
};
//---------------------------------------------------------------------------
class CWork {
	protected:
		CTestB m_B;

	private:
		CTestC m_C;

	public:
	    CTestA m_A;

	    CWork() {;};
	   ~CWork() {;};
};
//---------------------------------------------------------------------------
class CStaticClass {
	public:
		int m_iA;

		CStaticClass() :
			m_iA(10)
		{
			std::cout << "CStaticClass: construct" << std::endl;
		};
		~CStaticClass() {
			std::cout << "CStaticClass: dectruct" << std::endl;
		};
};
class CStaticClassTest {
	public:
		static CStaticClass m_sSC;

		CStaticClassTest() {
			std::cout << "CStaticClassTest: construct" << std::endl;
		};
		~CStaticClassTest() {
			std::cout << "CStaticClassTest: dectruct" << std::endl;
		};
};
CStaticClass CStaticClassTest::m_sSC;
//---------------------------------------------------------------------------
class CEnumClass {
	public:
		enum ETest {
			a = 1000,
			b = 2000,
			c = 10000,
			d = 20000,
			e = 30000
		};

		ETest m_ETest;

		CEnumClass() {;};
		~CEnumClass() {;};
};
//---------------------------------------------------------------------------
int main(int, char **) {
	//-------------------------------------
	//??????? ??????? ??????
	{
		CWork objW;
	}

	//-------------------------------------
	//??? ????????
	CEmpty objEmptyClass;
	std::cout << "objEmptyClass size: "  << sizeof(objEmptyClass) << std::endl;

	SEmpty objEmptyStruct;
	std::cout << "objEmptyStruct size: " << sizeof(objEmptyStruct) << std::endl;

	//-------------------------------------
	//throw
	if (true) {
		////throw "Could not start WSA";
		//throw;
	}

	//-------------------------------------
	//?????????????? ??? ???
	{
		CStaticClassTest stTest;

		std::cout << CStaticClassTest::m_sSC.m_iA << std::endl;
		std::cout << CStaticClassTest::m_sSC.m_iA << std::endl;
	}

	//-------------------------------------
	//CEnumClass
	{
		CEnumClass objCEnumClass;

		std::cout << "sizeof(objCEnumClass): " << sizeof(objCEnumClass) << std::endl;


		std::cout << "objCEnumClass.e: " << objCEnumClass.e << std::endl;
	}



	system("pause");
	return 0;
}
//---------------------------------------------------------------------------
