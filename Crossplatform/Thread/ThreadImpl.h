#include <Thread.h>
//-------------------------------------------------------------------------------------------------
class Thread;

// Abstract core class for Thread
class ThreadImpl
{
public:
    static ThreadImpl* createCore();

    static void deleteCore(ThreadImpl * core)
    {
        delete core; core = 0;
    }

    ThreadImpl()
    {
    }

    virtual ~ThreadImpl()
    {
    }

    static void  yield();
    static void  waitFor(Thread* thread);
    virtual void start(Thread* thread) = 0;
};
//-------------------------------------------------------------------------------------------------
