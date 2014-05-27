/**
 * \file   Thread_win.h
 * \brief
 */


#include "IThreadImpl.h"

#if USE_THREADIMPL_WIN

#include <windows.h>
//-------------------------------------------------------------------------------------------------
class Thread_win :
    IThreadImpl
{
public:
    Thread_win()
    {
    }

    virtual ~Thread_win()
    {
    }

    virtual void start(Thread* thread)
    {
        _handle = ::CreateThread(NULL, 0, _worker, thread, 0, &_id);
    }

protected:
    DWORD  _id;
    HANDLE _handle;

    static DWORD _worker(void* param)
    {
        ((Thread*)param)->run();
        return 0;
    }
};
//-------------------------------------------------------------------------------------------------
IThreadImpl*
IThreadImpl::construct()
{
    return new Thread_win;
}
//-------------------------------------------------------------------------------------------------
void
IThreadImpl::waitFor(Thread* thread)
{
    Thread_win* impl = (Thread_win*)thread->impl;
    ::WaitForSingleObjectEx(impl->_handle, INFINITY, TRUE);
}
//-------------------------------------------------------------------------------------------------
void
IThreadImpl::yield()
{
    ::SwitchToThread();
}
//-------------------------------------------------------------------------------------------------

#endif
