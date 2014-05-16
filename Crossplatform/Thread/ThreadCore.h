// Forward declare the thread class.
#include <Thread.h>

class Thread;

// Abstract core class for Thread
class ThreadCore
{
public:
    // Provide a platform independent way for a thread core to be created
    static ThreadCore * createCore();

    // A safe-delete for thread cores. More functionality should be added.
    static void deleteCore(ThreadCore * core)
    {
        if (core)
            delete core;
    }
    // Constructor and destructor, don’t need to do anything
    ThreadCore()
    {
    }

    virtual ~ThreadCore()
    {
    }
    // The following functions are all platform dependent in their operations,
    // so make any platform-specific instance implement these functions.
    static void yield();
    static void waitFor(Thread * thread);
    virtual void start(Thread * thread) = 0;
};
