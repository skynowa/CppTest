/**
 * \file  list.cpp
 * \brief
 *
 * \todo
 */


#include <StdStream.h>
#include <StdTest.h>
#include <Stl.h>

using namespace std;

#ifndef CTestH
#define CTestH
//---------------------------------------------------------------------------
class CTest {
	public:
		int _m_iIndex;

		CTest(int iIndex) :
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
int main(int, char **)
{
	int iRv {};

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

		iRv= system("pause");
		STD_UNUSED(iRv);

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

		iRv= system("pause");
		STD_UNUSED(iRv);

		cout << endl;
		cout << endl;

	}

	//-------------------------------------
	//
	cout << endl;
	cout << endl;

	iRv= system("pause");
	STD_UNUSED(iRv);

	return 0;
}
//---------------------------------------------------------------------------
