// Make sure the user wants to compile for a POSIX compliant system
#ifdef USE_POSIXTHREADCORE

#include <ThreadCore.h>
#include <pthread.h>
#include <sched.h>

// Posix implementation of the thread core class
class PosixThreadCore : ThreadCore
{
public:
    // empty constructor and destructor
    PosixThreadCore()
    {
    }

    virtual ~PosixThreadCore()
    {
    }

    // start the thread
    virtual void start(Thread * thread)
    {
        pthread_create(&posixThread, NULL, threadStart, thread);
    }

protected:
    pthread_t posixThread;

    static void * threadStart(void * pthreadParam)
    {
        Thread * thread = (Thread*)pthreadParam;
        thread->run();
        return 0;
    }
};

// Simple implementations, but since we do not want a lot of preprocessor
// statements everywhere, we implement them in this file. Implementing these
// functions in this file also helps to ensure that no more than one
// threadcore implementation is linked
ThreadCore * ThreadCore::createCore()
{
    return new PosixThreadCore;
}

void ThreadCore::waitFor(Thread * thread)
{
    PosixThreadCore * core = ((PosixThreadCore*)thread)->core;
    pthread_join(core->posixThread, NULL);
}

void ThreadCore::yield()
{
    sched_yield();
}

#endif
