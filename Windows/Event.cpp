 /*
 * \file  Main.cpp
 * \brief 
 */


//---------------------------------------------------------------------------

#include <string>
#include <iostream>
#include <assert.h>
#include <windows.h>
#include <process.h>
//---------------------------------------------------------------------------
#if MSDN
    ::SetEvent   - set signaled state
    ::ResetEvent - set nonsignaled state
#endif

#if 0
    const BOOL g_cbManualReset = FALSE;
    const BOOL g_cbIsSignaled  = FALSE;

    /*
    Thread A: start
    Thread A: finished
    Thread B: start
    Thread B: finished
    */
#endif

#if 0
    const BOOL g_cbManualReset = FALSE;
    const BOOL g_cbIsSignaled  = TRUE;

    /*
    Thread A: start
    Thread B: start
    Thread B: finished
    Thread A: finished
    Press any key to exit...
    */
#endif

#if 0
    const BOOL g_cbManualReset = TRUE;
    const BOOL g_cbIsSignaled  = FALSE;

    /*
    Thread A: start
    Thread A: finished
    Thread B: start
    Thread B: ResetEvent
    Thread B: finished
    */
#endif

#if 1
    const BOOL g_cbManualReset = TRUE;
    const BOOL g_cbIsSignaled  = TRUE;

    /*
    Thread A: start
    Thread B: start
    Thread A: finished
    Thread B: ResetEvent
    Thread B: finished
    */
#endif

HANDLE     g_evEvent       = NULL; 
//---------------------------------------------------------------------------
unsigned int __stdcall 
threadA(void *param) {
    std::cout << "Thread A: start" << std::endl;

	BOOL blRv = ::SetEvent(g_evEvent);
    assert(FALSE != blRv);

    std::cout << "Thread A: finished" << std::endl;

	return 0U;
}
//---------------------------------------------------------------------------
unsigned int __stdcall 
threadB(void *param) {
	::WaitForSingleObject(g_evEvent, INFINITE);
    std::cout << "Thread B: start" << std::endl;

    if (TRUE == g_cbManualReset) {
        BOOL blRv = ::ResetEvent(g_evEvent);
        assert(FALSE != blRv);
        std::cout << "Thread B: ResetEvent" << std::endl;
    }

    std::cout << "Thread B: finished" << std::endl;

	return 0U;
}
//---------------------------------------------------------------------------
unsigned int __stdcall 
threadC(void *param) {
	::WaitForSingleObject(g_evEvent, INFINITE);
    std::cout << "Thread C: start" << std::endl;

    if (TRUE == g_cbManualReset) {
        BOOL blRv = ::ResetEvent(g_evEvent);
        assert(FALSE != blRv);
        std::cout << "Thread C: ResetEvent" << std::endl;
    }

    std::cout << "Thread C: finished" << std::endl;

	return 0U;
}
//---------------------------------------------------------------------------
int main(int iArgCount, char **paszArgs)
{
	g_evEvent = ::CreateEvent(NULL, g_cbManualReset, g_cbIsSignaled, NULL);
    assert(NULL != g_evEvent);

	HANDLE handleA = (HANDLE)::_beginthreadex(NULL, 0U, &threadA, NULL, 0U, NULL);
	HANDLE handleB = (HANDLE)::_beginthreadex(NULL, 0U, &threadB, NULL, 0U, NULL);
    //HANDLE handleC = (HANDLE)::_beginthreadex(NULL, 0U, &threadC, NULL, 0U, NULL);

	::WaitForSingleObject(handleA, INFINITE);
	::WaitForSingleObject(handleB, INFINITE);
    //::WaitForSingleObject(handleC, INFINITE);

	::CloseHandle(handleA);
	::CloseHandle(handleB);
    //::CloseHandle(handleC);

	::CloseHandle(g_evEvent);

    std::cout << "Press any key to exit..." << std::endl;
	getchar();

    return EXIT_SUCCESS;
}
//---------------------------------------------------------------------------


#if OUTPUT
// NOTE:

$ ./main


#endif