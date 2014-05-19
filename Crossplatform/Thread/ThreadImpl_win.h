#include <ThreadImpl.h>

// Wrapper class for a operating-system thread.
// Check to make sure that the user wants to compile for win32 systems
#ifdef USE_ThreadImpl_win

#include <ThreadImpl.h>
#include <windows.h>

class ThreadImpl_win : ThreadImpl
{
public:
    inline ThreadImpl_win()
    {
    }

    inline virtual ~ThreadImpl_win()
    {
    }

    virtual void start(Thread * thread)
    {
        threadHandle = CreateThread(NULL, 0, threadStart, thread, 0, &threadID);
    }

protected:
    DWORD threadID;

    // thread id
    HANDLE threadHandle;// thread handle

    static DWORD threadStart(void * win32Param)
    {
        ((Thread*)win32Param)->run();
        return 0;
    }
};

// Simple implementations
ThreadImpl * ThreadImpl::createCore()
{
    return new ThreadImpl_win;
}

void ThreadImpl::waitFor(Thread * thread)
{
    ThreadImpl_win * core = (ThreadImpl_win*)thread->core;
    WaitForSingleObjectEx(core->threadHandle, INFINITY, TRUE);
}

void ThreadImpl::yield()
{
    SwitchToThread();
}

#endif
