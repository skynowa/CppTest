/**
 * \file  PSigInfo.cpp
 * \brief
 *
 * \todo
 */


#include <StdStream/StdStream.h>
#include <StdTest/StdTest.h>
#include <Stl.h>
//--------------------------------------------------------------------------------------------------
void
handler(
    int        sig,
    siginfo_t *sinf,
    void      *ucon
)
{
    (void)sig;
    (void)ucon;

    // Print out what we received.
    ::psiginfo(sinf, "::::: Received signal :::::");

    std::cout << "::::: " << STD_TRACE_VAR(sig) << " :::::" << std::endl;
}
//--------------------------------------------------------------------------------------------------
int main(int, char **)
{
   /**
    * Set up the sigaction structure.  We want to get the
    * extra information about the signal, so set SA_SIGINFO.
    */
    struct sigaction sact {};
    sact.sa_sigaction = ::handler;
    sact.sa_flags     = SA_SIGINFO;
    ::sigemptyset(&sact.sa_mask);

    // Send SIGUSR1 and SIGUSR2 to the handler function.
    if (::sigaction(SIGSEGV, &sact, (struct sigaction *)nullptr) < 0) {
        fprintf(stderr, "cannot set handler for SIGUSR1\n");
        exit(1);
    }

    if (::sigaction(SIGQUIT, &sact, (struct sigaction *)nullptr) < 0) {
        fprintf(stderr, "cannot set handler for SIGUSR2\n");
        exit(1);
    }

    // Now wait for signals to arrive.
    {
        const std::size_t sleepSec {10};

        std::cout << "Sleep " << sleepSec << " second..." << std::endl;
        std::this_thread::sleep_for( std::chrono::seconds(sleepSec) );
    }

    return EXIT_SUCCESS;
}
//--------------------------------------------------------------------------------------------------


#if OUTPUT

Sleep 10 second...
^CCMakeFiles/test_PSigInfo.dir/build.make:57: recipe for target 'CMakeFiles/test_PSigInfo' failed
make[3]: *** [CMakeFiles/test_PSigInfo] Interrupt


#endif
