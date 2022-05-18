/**
 * \file  Wait.cpp
 * \brief
 *
 * https://www.ibm.com/support/knowledgecenter/SSLTBW_2.1.0/com.ibm.zos.v2r1.bpxbd00/rtwaip.htm
 *
 * The following function suspends the calling process using waitpid() until a child process ends
 */


#include <StdStream/StdStream.h>
#include <StdTest/StdTest.h>
#include <Stl.h>

#include <sys/wait.h>
//-------------------------------------------------------------------------------------------------
int main(int, char **)
{
	pid_t pid = ::fork();
	if (pid < 0) {
		// Child Error
		::perror("fork() error");
	}
	else if (pid == 0) {
		// Child Ok
		::sleep(3);
		::exit(123);
	}
	else {
		// ParentOk
		do {
			int status {};

			pid = ::waitpid(pid, &status, WNOHANG);
			if      (pid == -1) {
				std::cout << STD_TRACE_VAR(pid) << ", ";
				::perror("waitpid() - error");
			}
			else if (pid == 0) {
				std::cout << STD_TRACE_VAR(pid) << ", ";

				time_t t {};
				time(&t);

				printf("Child running at %s", ctime(&t));
				::sleep(1);
			}
			else {
				std::cout << "\n" << STD_TRACE_VAR(pid) << ", ";

				if ( WIFEXITED(status) )
					printf("Child exited with status of %d (%d)\n", WEXITSTATUS(status), status);
				else
					puts("Child did not exit successfully");
			}
		}
		while (pid == 0);
	}

	return EXIT_SUCCESS;
}
//-------------------------------------------------------------------------------------------------

#if OUTPUT

pid: 0, Child running at Wed Jun  9 11:28:05 2021
pid: 0, Child running at Wed Jun  9 11:28:06 2021
pid: 0, Child running at Wed Jun  9 11:28:07 2021
pid: 0, Child running at Wed Jun  9 11:28:08 2021

pid: 11699, Child exited with status of 123 (31488)

#endif
