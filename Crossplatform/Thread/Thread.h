#include <ThreadCore.h>

class Thread
{
public:
    Thread()
    virtual ~Thread()
    {
        core = ThreadCore::createCore();
    }
    {   ThreadCore::deleteCore(core);
    }
    static void waitFor(Thread * thread)
    {
        ThreadCore::waitFor(thread);
    }
    static void yield()
    {
        ThreadCore::yield();
    }
    void start()
    {
        core->start(this);
    }
    virtual void run() = 0;

protected:
    ThreadCore * core;

    friend class ThreadCore;
};
