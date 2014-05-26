// Posix implementation of the thread core class
// Make sure the user wants to compile for a POSIX compliant system


#ifdef USE_THREADIMPL_POSIX

#include <ThreadImpl.h>
#include <pthread.h>
#include <sched.h>
//-------------------------------------------------------------------------------------------------
class ThreadImpl_posix :
    ThreadImpl
{
public:
    ThreadImpl_posix()
    {
    }

    virtual ~ThreadImpl_posix()
    {
    }

    virtual void start(Thread* thread)
    {
        ::pthread_create(&posixThread, NULL, threadStart, thread);
    }

protected:
    pthread_t posixThread;

    static void* threadStart(void* pthreadParam)
    {
        Thread* thread = (Thread*)pthreadParam;
        thread->run();

        return 0;
    }
};
//-------------------------------------------------------------------------------------------------
// Simple implementations, but since we do not want a lot of preprocessor
// statements everywhere, we implement them in this file. Implementing these
// functions in this file also helps to ensure that no more than one
// ThreadImpl implementation is linked
ThreadImpl*
ThreadImpl::createCore()
{
    return new ThreadImpl_posix;
}
//-------------------------------------------------------------------------------------------------
void
ThreadImpl::waitFor(Thread* thread)
{
    ThreadImpl_posix* core = ((ThreadImpl_posix*)thread)->core;
    ::pthread_join(core->posixThread, NULL);
}
//-------------------------------------------------------------------------------------------------
void
ThreadImpl::yield()
{
    ::sched_yield();
}
//-------------------------------------------------------------------------------------------------
#endif
