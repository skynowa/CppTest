/**
 * \file  main.cpp
 * \brief
 *
 * \todo
 *
 * https://www.oreilly.com/library/view/secure-programming-cookbook/0596003943/ch01s07.html
 */

#include <StdStream.h>
#include <StdTest.h>
#include <Stl.h>

#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
//-------------------------------------------------------------------------------------------------
struct SPC_PIPE
{
	FILE  *fdRead {};
	FILE  *fdWrite {};
	pid_t  pidChild {};

	void clear()
	{
		fdRead   = 0;
		fdWrite  = 0;
		pidChild = -1;
	};
};
//-------------------------------------------------------------------------------------------------
/**
 * The following function, spc_fork( ) , is a wrapper around fork( ). As presented here,
 * the code is incomplete when using an application-level random number generator;
 * it will require the appropriate code to reseed whatever PRNG you’re using.
 * It assumes that the new child process is the process that will be used to perform any work
 * that does not require any extra privileges that the process may have.
 * It is rare that when a process is forked, the original process is used to execute another
 * program or the new process is used to continue primary execution of the program.
 * In other words, the new process is most often the worker process.
 */
pid_t
spc_fork()
{
	pid_t pidChild = ::fork();
	if (pidChild == -1) {
		return -1;
	}

	// Reseed PRNGs in both the parent and the child
	// See Chapter 11 for examples

	// If this is the parent process, there's nothing more to do
	if (pidChild != 0) {
		return pidChild;
	}

	// This is the child process
#if 0
	spc_sanitize_files();   /* Close all open files.  See Recipe 1.1 */
	spc_drop_privileges(1); /* Permanently drop privileges.  See Recipe 1.3 */
#endif

	return 0;
}
//-------------------------------------------------------------------------------------------------
/**
 * If spc_popen( ) is successful, the SPC_PIPE object it returns contains two FILE objects:
 * fdRead can be used to read data written by the new program to its stdout file descriptor.
 * fdWrite can be used to write data to the new program for reading from its stdin file descriptor.
 * Unlike popen( ), which in its most portable form is unidirectional, spc_popen( ) is bidirectional
 */
bool
spc_popen(
	SPC_PIPE   &out_p,	///< [in,out]
	const char *path,
	char *const argv[],
	char *const envp[]
)
{
	out_p.clear();

	int iRv {};

	// StdIn
	int pipeStdIn[2] {};
	{
		iRv = ::pipe(pipeStdIn);
		STD_TEST_RET(iRv != -1, false);

		out_p.fdWrite = ::fdopen(pipeStdIn[1], "w");
		STD_TEST_RET(out_p.fdWrite != nullptr, false);
	}

	// StdOut
	int pipeStdOut[2] {};
	{
		iRv = ::pipe(pipeStdOut);
		STD_TEST_RET(iRv != -1, false);

		out_p.fdRead = ::fdopen(pipeStdOut[0], "r");
		STD_TEST_RET(out_p.fdRead != nullptr, false);
	}

	// fork
	out_p.pidChild = ::spc_fork();
	STD_TEST_RET(iRv != -1, false);

	// child process
	if (out_p.pidChild == 0) {
		::close(pipeStdOut[0]);

		if (pipeStdIn[0] != 0) {
			::dup2(pipeStdIn[0], 0);
			::close(pipeStdIn[0]);
		}

		if (pipeStdOut[1] != 1) {
			::dup2(pipeStdOut[1], 1);
			::close(pipeStdOut[1]);
		}

		// execute
		::execve(path, argv, envp);

		::exit(127);
	}

	::close(pipeStdOut[1]);
	::close(pipeStdIn[0]);

	return true;
}
//-------------------------------------------------------------------------------------------------
int
spc_pclose(
	SPC_PIPE &out_p
)
{
	int   status {};
	pid_t pid {};

	if (out_p.pidChild != -1) {
		do {
			pid = ::waitpid(out_p.pidChild, &status, 0);
		}
		while (pid == -1 &&errno == EINTR);
	}

	if (out_p.fdRead != nullptr) {
		::fclose(out_p.fdRead);
	}

	if (out_p.fdWrite != nullptr) {
		::fclose(out_p.fdWrite);
	}

	if (pid != -1 && WIFEXITED(status)) {
		return WEXITSTATUS(status);
	}

	return (pid == -1 ? -1 : 0);
}
//-------------------------------------------------------------------------------------------------
int main(int, char *const argv[], char *const envp[])
{
	bool bRv {};
	int  iRv {};

	SPC_PIPE p;

	const std::string path = "/usr/bin/git";

	bRv = ::spc_popen(p, path.c_str(), argv, envp);
	iRv = ::spc_pclose(p);

	std::cout << TRACE_VAR3(path, bRv, iRv) << std::endl;

	return EXIT_SUCCESS;
}
//-------------------------------------------------------------------------------------------------

#if OUTPUT

path: /usr/bin/git, bRv: 1, iRv: 1

#endif
