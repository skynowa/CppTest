#include <ThreadCore.h>

// Wrapper class for a operating-system thread.
// Check to make sure that the user wants to compile for win32 systems
#ifdef USE_WIN32THREADCORE

#include <ThreadCore.h>
#include <windows.h>

class Win32ThreadCore : ThreadCore
{
public:
    inline Win32ThreadCore()
    {
    }

    inline virtual ~Win32ThreadCore()
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
ThreadCore * ThreadCore::createCore()
{
    return new Win32ThreadCore;
}

void ThreadCore::waitFor(Thread * thread)
{
    Win32ThreadCore * core = (Win32ThreadCore*)thread->core;
    WaitForSingleObjectEx(core->threadHandle, INFINITY, TRUE);
}

void ThreadCore::yield()
{
    SwitchToThread();
}

#endif
