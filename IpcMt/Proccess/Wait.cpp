/**
 * \file  main.cpp
 * \brief
 *
 * \todo
 *
 * https://www.ibm.com/support/knowledgecenter/SSLTBW_2.1.0/com.ibm.zos.v2r1.bpxbd00/rtwaip.htm
 *
 * The following function suspends the calling process using &waitpid until a child process ends
 */

#include <StdStream.h>
#include <StdTest.h>
#include <Stl.h>

#include <sys/wait.h>
//-------------------------------------------------------------------------------------------------
int main(int, char **)
{
	pid_t  pid {};
	time_t t {};
	int    status {};

	pid = ::fork();
	if (pid < 0) {
		// ChildError
		::perror("fork() error");
	}
	else if (pid == 0) {
		// ChildOk
		::sleep(3);
		::exit(123);
	}
	else {
		// ParentOk
		do {
			pid = ::waitpid(pid, &status, WNOHANG);
			if      (pid == -1) {
				::perror("wait() error");
			}
			else if (pid == 0) {
				time(&t);
				printf("child is still running at %s", ctime(&t));
				::sleep(1);
			}
			else {
				if ( WIFEXITED(status) )
					printf("child exited with status of %d (%d)\n", WEXITSTATUS(status), status);
				else
					puts("child did not exit successfully");
			}
		}
		while (pid == 0);
	}

	// std::cout << TRACE_VAR("") << std::endl;

	return EXIT_SUCCESS;
}
//-------------------------------------------------------------------------------------------------

#if OUTPUT

child is still running at Sat May  9 01:33:23 2020
child is still running at Sat May  9 01:33:24 2020
child is still running at Sat May  9 01:33:25 2020
child is still running at Sat May  9 01:33:26 2020
child exited with status of 123 (31488)

#endif
