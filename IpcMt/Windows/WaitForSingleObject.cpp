/**
 * \file  WaitForSingleObject.cpp
 * \brief
 *
 * \review
 */

//-------------------------------------------------------------------------------------------------
#include <StdStream/StdStream.h>
#include <StdTest/StdTest.h>
#include <Stl.h>

#include <windows.h>
//-------------------------------------------------------------------------------------------------
HANDLE hEvent {};
//-------------------------------------------------------------------------------------------------
DWORD WINAPI
SampleThread(LPVOID iValue)
{
	const int iFinish = 10000;

	for	(int i = 0; i <= iFinish; ++ i) {
		std::cout << i << std::endl;
	}

	::SetEvent(::hEvent);

	return 0;
}
//-------------------------------------------------------------------------------------------------
int main(int, char **)
{
	DWORD dwGenericThread {};
	HANDLE hThread = ::CreateThread(nullptr, 0, SampleThread, nullptr, 0, &dwGenericThread);
	if (hThread == nullptr) {
		DWORD dwError = ::GetLastError();
		std::cout << "SCM:Error in Creating thread: " << dwError << std::endl;
		return EXIT_SUCCESS;
	}

	::hEvent = CreateEvent(nullptr, FALSE, FALSE, "Test");
	std::cout << "Started waiting for the thread to complete.." << std::endl;

	::WaitForSingleObject(::hEvent, INFINITE);
	std::cout << "Thread Completed." << std::endl;

	::CloseHandle(::hEvent);

    return EXIT_SUCCESS;
}
//--------------------------------------------------------------------------------------------------


#if OUTPUT



#endif
