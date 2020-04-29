/**
 * \file  main.cpp
 * \brief
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
	FILE  *read_fd;
	FILE  *write_fd;
	pid_t  child_pid;
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
spc_fork(void) {
	pid_t childpid;

	if ((childpid = ::fork()) == -1) {
		return -1;
	}

	/* Reseed PRNGs in both the parent and the child */
	/* See Chapter 11 for examples */

	/* If this is the parent process, there's nothing more to do */
	if (childpid != 0) {
		return childpid;
	}

	/* This is the child process */
#if 0
	spc_sanitize_files();   /* Close all open files.  See Recipe 1.1 */
	spc_drop_privileges(1); /* Permanently drop privileges.  See Recipe 1.3 */
#endif

	return 0;
}
//-------------------------------------------------------------------------------------------------
/**
 * If spc_popen( ) is successful, the SPC_PIPE object it returns contains two FILE objects:
 * read_fd can be used to read data written by the new program to its stdout file descriptor.
 * write_fd can be used to write data to the new program for reading from its stdin file descriptor.
 * Unlike popen( ), which in its most portable form is unidirectional, spc_popen( ) is bidirectional
 */
SPC_PIPE *
spc_popen(
	const char *path,
	char *const argv[],
	char *const envp[]
)
{
	SPC_PIPE *p {};
	int       stdin_pipe[2] {};
	int       stdout_pipe[2] {};

	if (!(p = (SPC_PIPE *)malloc(sizeof(SPC_PIPE)))) {
		return 0;
	}

	p->read_fd   = 0;
	p->write_fd  = 0;
	p->child_pid = -1;

	if (::pipe(stdin_pipe) == -1) {
		free(p);

		return 0;
	}

	if (::pipe(stdout_pipe) == -1) {
		::close(stdin_pipe[1]);
		::close(stdin_pipe[0]);
		free(p);

		return 0;
	}

	if (!(p->read_fd = ::fdopen(stdout_pipe[0], "r"))) {
		::close(stdout_pipe[1]);
		::close(stdout_pipe[0]);
		::close(stdin_pipe[1]);
		::close(stdin_pipe[0]);
		free(p);

		return 0;
	}

	if (!(p->write_fd = ::fdopen(stdin_pipe[1], "w"))) {
		fclose(p->read_fd);
		::close(stdout_pipe[1]);
		::close(stdin_pipe[1]);
		::close(stdin_pipe[0]);
		free(p);

		return 0;
	}

	if ((p->child_pid = ::spc_fork()) == -1) {
		fclose(p->write_fd);
		fclose(p->read_fd);
		::close(stdout_pipe[1]);
		::close(stdin_pipe[0]);
		free(p);

		return 0;
	}

	if (!p->child_pid) {
		/* this is the child process */
		::close(stdout_pipe[0]);
		::close(stdin_pipe[1]);

		if (stdin_pipe[0] != 0) {
			::dup2(stdin_pipe[0], 0);
			::close(stdin_pipe[0]);
		}

		if (stdout_pipe[1] != 1) {
			::dup2(stdout_pipe[1], 1);
			::close(stdout_pipe[1]);
		}

		::execve(path, argv, envp);
		::exit(127);
	}

	::close(stdout_pipe[1]);
	::close(stdin_pipe[0]);

	return p;
}
//-------------------------------------------------------------------------------------------------
int
spc_pclose(
	SPC_PIPE *p
)
{
	int   status {};
	pid_t pid {};

	if (p->child_pid != -1) {
		do {
			pid = ::waitpid(p->child_pid, &status, 0);
		}
		while (pid == -1 &&errno == EINTR);
	}

	if (p->read_fd) {
		::fclose(p->read_fd);
	}

	if (p->write_fd) {
		::fclose(p->write_fd);
	}

	::free(p);

	if (pid != -1 && WIFEXITED(status)) {
		return WEXITSTATUS(status);
	}

	return (pid == -1 ? -1 : 0);
}
//-------------------------------------------------------------------------------------------------
int main(int, char *const argv[], char *const envp[])
{
	const std::string path = "/usr/bin/git";
	std::cout << TRACE_VAR(path) << std::endl;

	SPC_PIPE *p = ::spc_popen(path.c_str(), argv, envp);
	(int)::spc_pclose(p);

	return EXIT_SUCCESS;
}
//-------------------------------------------------------------------------------------------------

#if OUTPUT

#endif
