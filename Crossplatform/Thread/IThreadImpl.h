/**
 * \file   IThreadImpl.h
 * \brief
 *
 * \todo
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
        delete impl; impl = 0;
    }

    IThreadImpl()
    {
    }

    virtual ~IThreadImpl()
    {
    }

    static void  yield();
    static void  waitFor(Thread* thread);
    virtual void start(Thread* thread) = 0;
};
//-------------------------------------------------------------------------------------------------
