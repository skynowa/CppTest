// WaitForSingleObject Sample.cpp 

#include <windows.h>
#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>

using namespace std;


HANDLE hEvent;

DWORD WINAPI SampleThread(LPVOID iValue) {
	int iFinish = 10000;
	for	(int i=0; i <= iFinish; i++) {
		cout << i << endl;
	}
	SetEvent(hEvent);
		
	return 0;
}

void main() {
	HANDLE hThread;
	DWORD dwGenericThread;
	hThread = CreateThread(NULL, 0, SampleThread, NULL, 0, &dwGenericThread);
	if (hThread == NULL) {
		DWORD dwError = GetLastError();
		cout << "SCM:Error in Creating thread" << dwError << endl ;
		return;
	}

	hEvent = CreateEvent(NULL, FALSE, FALSE, "Test");
	cout << "Started waiting for the thread to complete.." << endl ;
	WaitForSingleObject(hEvent, INFINITE);
	cout << "Thread Completed." <<endl ;

	CloseHandle(hEvent);

	system("pause");
}
