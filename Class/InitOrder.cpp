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
int main(int, char **) {
	//-------------------------------------
	//������� ������ �������������, ������������
	{
		CWork objW;
	}

	//-------------------------------------
	//������ ������� �������
	CEmpty objEmptyClass;
	std::cout << "objEmptyClass size: " << sizeof(objEmptyClass) << std::endl;

	SEmpty objEmptyStruct;
	std::cout << "objEmptyStruct size: " << sizeof(objEmptyStruct) << std::endl;
	

	system("pause");
	return 0;
}
//---------------------------------------------------------------------------
