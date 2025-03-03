/**
 * \file  IpcMutex.cpp
 * \brief
 */


#include <StdStream/StdStream.h>
#include <StdTest/StdTest.h>
#include <Stl.h>
//--------------------------------------------------------------------------------------------------
int main(int, char **)
{
    int err {};

    pthread_mutexattr_t attr {};
    err = pthread_mutexattr_init(&attr); if (err) return err;
    err = pthread_mutexattr_setpshared(&attr, PTHREAD_PROCESS_SHARED); if (err) return err;

    pthread_mutex_t shm_mutex {};
    err = pthread_mutex_init(&shm_mutex, &attr); if (err) return err;
    err = pthread_mutexattr_destroy(&attr); if (err) return err;
    err = pthread_mutex_lock(&shm_mutex); if (err) return err;
    err = pthread_mutex_unlock(&shm_mutex); if (err) return err;
    err = pthread_mutex_destroy(&shm_mutex); if (err) return err;

    return EXIT_SUCCESS;
}
//--------------------------------------------------------------------------------------------------
