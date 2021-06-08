/**
 * \file  Event.cpp
 * \brief
 *
 * \review
 */


//-------------------------------------------------------------------------------------------------
#include <StdStream.h>
#include <StdTest.h>
#include <Stl.h>

#include <windows.h>
#include <process.h>
//-------------------------------------------------------------------------------------------------
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

HANDLE g_evEvent {};
//-------------------------------------------------------------------------------------------------
unsigned int __stdcall
threadA(void *param)
{
    std::cout << "Thread A: start" << std::endl;

	BOOL blRv = ::SetEvent(g_evEvent);
    assert(FALSE != blRv);

    std::cout << "Thread A: finished" << std::endl;

	return 0U;
}
//-------------------------------------------------------------------------------------------------
unsigned int __stdcall
threadB(void *param)
{
	::WaitForSingleObject(g_evEvent, INFINITE);
    std::cout << "Thread B: start" << std::endl;

    if (g_cbManualReset == TRUE) {
        BOOL blRv = ::ResetEvent(g_evEvent);
        assert(FALSE != blRv);
        std::cout << "Thread B: ResetEvent" << std::endl;
    }

    std::cout << "Thread B: finished" << std::endl;

	return 0U;
}
//-------------------------------------------------------------------------------------------------
unsigned int __stdcall
threadC(void *param)
{
	::WaitForSingleObject(g_evEvent, INFINITE);
    std::cout << "Thread C: start" << std::endl;

    if (g_cbManualReset == TRUE) {
        BOOL blRv = ::ResetEvent(g_evEvent);
        assert(FALSE != blRv);
        std::cout << "Thread C: ResetEvent" << std::endl;
    }

    std::cout << "Thread C: finished" << std::endl;

	return 0U;
}
//-------------------------------------------------------------------------------------------------
int main(int, char **)
{
	g_evEvent = ::CreateEvent(nullptr, g_cbManualReset, g_cbIsSignaled, nullptr);
    assert(g_evEvent != nullptr);

	HANDLE handleA = (HANDLE)::_beginthreadex(nullptr, 0U, &threadA, nullptr, 0U, nullptr);
	HANDLE handleB = (HANDLE)::_beginthreadex(nullptr, 0U, &threadB, nullptr, 0U, nullptr);
    // HANDLE handleC = (HANDLE)::_beginthreadex(nullptr, 0U, &threadC, nullptr, 0U, nullptr);

	::WaitForSingleObject(handleA, INFINITE);
	::WaitForSingleObject(handleB, INFINITE);
    // ::WaitForSingleObject(handleC, INFINITE);

	::CloseHandle(handleA);
	::CloseHandle(handleB);
    // ::CloseHandle(handleC);

	::CloseHandle(g_evEvent);

    std::cout << "Press any key to exit..." << std::endl;
	getchar();

    return EXIT_SUCCESS;
}
//-------------------------------------------------------------------------------------------------


#if OUTPUT

$ ./main

#endif