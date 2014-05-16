#ifdef _POSIX
    #include <pthread.h>
    #include <sched.h>
#elif defined(_WIN32)
    #include <windows.h>
#endif

// Class representing an operating system execution thread
class Thread
{
public:
    Thread()
    {
    }
    virtual ~Thread()
    {
    }

#ifdef _POSIX
    void * threadStart(void * p)
    {
        ((Thread*)p)->run();
    }
#elif defined(_WIN32)
    DWORD WINAPI threadStart(void * p)
    {
        ((Thread*)p)->run();
    }
#endif

    // This function will halt until the passed in thread finishes its execution
    static void waitFor(Thread * thread)
    {
    #ifdef _POSIX
        pthread_join(thread->pthreadObject, NULL);
    #elif defined(_WIN32)
        WaitForSingleObject(thread->threadHandle, INFINITY, TRUE);
    #endif
    }

    // This function will make the current thread attempt to give back the
    // remaining time slice to the operating system
    static void yield()
    {
    #ifdef _POSIX
        sched_yield();
    #elif defined(_WIN32)
        SwitchToThread();
    #endif
    }

    // this function will start the thread
    void start()
    {
    #ifdef _POSIX
        pthread_create(&pthreadObject, NULL, threadStart, NULL);
    #elif defined(_WIN32)
        threadHandle = CreateThread(NULL, 0, threadStart, thread, 0, &threadID);
    #endif
    }

    // One must implement this function in order to use the thread class. When
    // the start function of a thread is called, this function is executed.
    virtual void run() = 0;

protected:
    #ifdef _POSIX
        pthread_t pthreadObject;
    #elif defined(_WIN32)
        DWORD     threadID;
        HANDLE    threadHandle;
    #endif
};
