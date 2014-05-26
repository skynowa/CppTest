// Wrapper class for a operating-system thread.
// Check to make sure that the user wants to compile for win32 systems


#ifdef USE_THREADIMPL_WIN

#include <ThreadImpl.h>
#include <windows.h>
//-------------------------------------------------------------------------------------------------
class ThreadImpl_win :
    ThreadImpl
{
public:
    ThreadImpl_win()
    {
    }

    virtual ~ThreadImpl_win()
    {
    }

    virtual void start(Thread * thread)
    {
        threadHandle = ::CreateThread(NULL, 0, threadStart, thread, 0, &threadID);
    }

protected:
    DWORD threadID;

    HANDLE threadHandle;

    static DWORD threadStart(void * win32Param)
    {
        ((Thread*)win32Param)->run();
        return 0;
    }
};
//-------------------------------------------------------------------------------------------------
ThreadImpl*
ThreadImpl::createCore()
{
    return new ThreadImpl_win;
}
//-------------------------------------------------------------------------------------------------
void
ThreadImpl::waitFor(Thread* thread)
{
    ThreadImpl_win* core = (ThreadImpl_win*)thread->core;
    WaitForSingleObjectEx(core->threadHandle, INFINITY, TRUE);
}
//-------------------------------------------------------------------------------------------------
void
ThreadImpl::yield()
{
    SwitchToThread();
}
//-------------------------------------------------------------------------------------------------
#endif
