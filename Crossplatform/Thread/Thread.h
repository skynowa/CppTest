#include <ThreadImpl.h>
//-------------------------------------------------------------------------------------------------
class Thread
{
public:
    Thread()
    {
        core = ThreadImpl::createCore();
    }

    virtual ~Thread()
    {
        ThreadImpl::deleteCore(core);
    }

    static void waitFor(Thread * thread)
    {
        ThreadImpl::waitFor(thread);
    }

    static void yield()
    {
        ThreadImpl::yield();
    }

    void start()
    {
        core->start(this);
    }

    virtual void run() = 0;

protected:
    ThreadImpl* core;

    friend class ThreadImpl;
};
//-------------------------------------------------------------------------------------------------
