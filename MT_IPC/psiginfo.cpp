#include <signal.h>
#include <cstdlib>
#include <cstdio>
#include <iostream>

using namespace std;

void handler(int, siginfo_t *, void *);

int
main(void)
{
    struct sigaction sact;

    /*
     * Set up the sigaction structure.  We want to get the
     * extra information about the signal, so set SA_SIGINFO.
     */
    sact.sa_sigaction = handler;
    sact.sa_flags = SA_SIGINFO;
    sigemptyset(&sact.sa_mask);

    /*
     * Send SIGUSR1 and SIGUSR2 to the handler function.
     */
    if (sigaction(SIGSEGV, &sact, (struct sigaction *) NULL) < 0) {
        fprintf(stderr, "cannot set handler for SIGUSR1\n");
        exit(1);
    }

    if (sigaction(SIGQUIT, &sact, (struct sigaction *) NULL) < 0) {
        fprintf(stderr, "cannot set handler for SIGUSR2\n");
        exit(1);
    }

    /*
     * Now wait for signals to arrive.
     */
    for (;;)
        system("pause");
}

/*
 * handler - handle a signal.
 */
void
handler(int sig, siginfo_t *sinf, void *ucon)
{
    /*
     * Print out what we received.
     */
    psiginfo(sinf, "Received signal");
}
