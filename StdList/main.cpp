#include <windows.h>
#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <iostream>
#include <list>
#include <assert.h>

using namespace std;

#ifndef CTestH
#define CTestH
//---------------------------------------------------------------------------
class CTest {
	public:
		INT _m_iIndex;

		CTest(INT iIndex) :
			_m_iIndex(iIndex)
		{
			cout << "CTest(): "  << _m_iIndex << endl; 
	    };
	   ~CTest() {
		    cout << "~CTest(): " << _m_iIndex <<endl; 
		};
};
//---------------------------------------------------------------------------
#endif	//CTestH
//---------------------------------------------------------------------------
int main(int argc, char* argv[]) {
	//CTest *pT1 = new CTest(1);
	//CTest *pT2 = new CTest(2);
	//CTest *pT3 = new CTest(3);
	//CTest *pT4 = new CTest(4);
	//
	//
	//std::list<CTest *> mylist;
	//mylist.push_back(pT1);
	//mylist.push_back(pT2);
	//mylist.push_back(pT3);
	//mylist.push_back(pT4);

	//cout << "mylist contains:";
	//for (std::list<CTest *>::iterator it = mylist.begin(); it != mylist.end(); ++ it) {
	//	cout << " " << (*it)->_m_iIndex;
	//}
	//cout << endl;
	//cout << endl;
	//system("pause");

	////-------------------------------------
	////
	//cout << "mylist removing element:";
	//cout << endl;
	//mylist.remove(pT2);

	//assert(NULL != pT1);
	//assert(NULL != pT2);
	//assert(NULL != pT3);
	//assert(NULL != pT4);

	////-------------------------------------
	////
	//cout << "mylist contains:";
	//for (std::list<CTest *>::iterator it = mylist.begin(); it != mylist.end(); ++ it) {
	//	cout << " " << (*it)->_m_iIndex;
	//}
	//cout << endl;
	//cout << endl;
	//system("pause");



	//delete pT4;
	//delete pT3;
	//delete pT2;
	//delete pT1;


	////-------------------------------------
	////
	//system("pause");
	//return 0;

	{
		CTest pT1(1);
		CTest pT2(2);
		CTest pT3(3);
		CTest pT4(4);


		std::list<CTest> mylist;
		mylist.push_back(pT1);
		mylist.push_back(pT2);
		mylist.push_back(pT3);
		mylist.push_back(pT4);

		cout << "mylist contains:";
		for (std::list<CTest>::iterator it = mylist.begin(); it != mylist.end(); ++ it) {
			cout << " " << (*it)._m_iIndex;
		}
		cout << endl;
		cout << endl;
		system("pause");
		cout << endl;
		cout << endl;

		//-------------------------------------
		//
		cout << "mylist removing element:";
		cout << endl;
		//mylist.remove(pT2);

		std::list<CTest>::iterator it = mylist.begin();
		mylist.erase(it);

		//-------------------------------------
		//
		cout << "mylist contains:";
		for (std::list<CTest>::iterator it = mylist.begin(); it != mylist.end(); ++ it) {
			cout << " " << (*it)._m_iIndex;
		}
		cout << endl;
		cout << endl;
		system("pause");
		cout << endl;
		cout << endl;

	}




	//-------------------------------------
	//
	cout << endl;
	cout << endl;
	system("pause");
	return 0;

}
//---------------------------------------------------------------------------
