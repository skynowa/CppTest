/**
 * \file   Thread.h
 * \brief
 *
 * \todo
 */


#define USE_THREADIMPL_POSIX 1
#define USE_THREADIMPL_WIN   0

#include "IThreadImpl.h"
//-------------------------------------------------------------------------------------------------
class Thread
{
public:
    Thread()
    {
        _impl = IThreadImpl::construct();
    }

    virtual ~Thread()
    {
        IThreadImpl::destruct(_impl);
    }

    static void waitFor(Thread* thread)
    {
        IThreadImpl::waitFor(thread);
    }

    static void yield()
    {
        IThreadImpl::yield();
    }

    void start()
    {
        _impl->start(this);
    }

    virtual void run() = 0;

protected:
    IThreadImpl* _impl;

    friend class IThreadImpl;
};
//-------------------------------------------------------------------------------------------------
