/**
 * \file  IThreadImpl.h
 * \brief
 */


#include "Thread.h"
//-------------------------------------------------------------------------------------------------
class Thread;

class IThreadImpl
{
public:
    static IThreadImpl* construct();

    static void destruct(IThreadImpl* impl)
    {
        delete impl;
        impl = 0;
    }

    IThreadImpl()
    {
    }

    virtual ~IThreadImpl()
    {
    }

    virtual void start(Thread* thread) = 0;

    static void  yield();
    static void  waitFor(Thread* thread);
};
//-------------------------------------------------------------------------------------------------
