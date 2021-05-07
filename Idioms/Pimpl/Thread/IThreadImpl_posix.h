/**
 * \file  IThreadImpl_posix.h
 * \brief
 */


#include "IThreadImpl.h"

#if USE_THREADIMPL_POSIX

#include <pthread.h>
#include <sched.h>
//-------------------------------------------------------------------------------------------------
class Thread_posix :
    IThreadImpl
{
public:
    Thread_posix()
    {
    }

    virtual ~Thread_posix()
    {
    }

    virtual void start(Thread* thread)
    {
        ::pthread_create(&_handle, NULL, _worker, thread);
    }

protected:
    pthread_t _handle;

    static void* _worker(void* param)
    {
        Thread* thread = (Thread*)param;
        thread->run();

        return 0;
    }
};
//-------------------------------------------------------------------------------------------------
// Simple implementations, but since we do not want a lot of preprocessor
// statements everywhere, we implement them in this file. Implementing these
// functions in this file also helps to ensure that no more than one
// IThreadImpl implementation is linked
IThreadImpl*
IThreadImpl::construct()
{
    return new Thread_posix;
}
//-------------------------------------------------------------------------------------------------
void
IThreadImpl::waitFor(Thread* thread)
{
    Thread_posix* impl = ((Thread_posix*)thread)->impl;
    ::pthread_join(impl->_handle, NULL);
}
//-------------------------------------------------------------------------------------------------
void
IThreadImpl::yield()
{
    ::sched_yield();
}
//-------------------------------------------------------------------------------------------------

#endif
