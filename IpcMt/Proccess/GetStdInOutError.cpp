/**
 * \file  GetStdInOutError.cpp
 * \brief Catch stderr and stdout from external program
 *
 * \review
 *
 * http://www.cplusplus.com/forum/unices/82836/
 */


#include <StdStream/StdStream.h>
#include <StdTest/StdTest.h>
#include <Stl.h>

#include <sys/wait.h>
//-------------------------------------------------------------------------------------------------
int main(int, char **argv)
{
	int iRv {};

	enum ProcessStatus : pid_t
	{
		ChildError = - 1, ///< returned in the parent, no child process is created, errno is set
		ChildOk    = 0,   ///< PID of the child process - in parent, 0 - in child
		ParentOk          ///< value > 0, creates a new child process (waitpid)
	};

	enum FdIndex : std::size_t
	{
		Read  = 0,
		Write = 1
	};

	int pipeIn[2] {};
	iRv = ::pipe(pipeIn);
	STD_UNUSED(iRv);

	int pipeOut[2] {};
	iRv = ::pipe(pipeOut);
	STD_UNUSED(iRv);

	int pipeErr[2] {};
	iRv = ::pipe(pipeErr);
	STD_UNUSED(iRv);

	const int pid = ::fork();
	if (pid == ProcessStatus::ChildOk) {
		std::cout << "Child: " << TRACE_VAR(pid) << std::endl;

		dup2(pipeIn[FdIndex::Read],   STDIN_FILENO);
		dup2(pipeOut[FdIndex::Write], STDOUT_FILENO);
		dup2(pipeErr[FdIndex::Write], STDERR_FILENO);

		// close all other inherited descriptors child doesn't need
		::close(pipeIn[FdIndex::Read]);
		::close(pipeOut[FdIndex::Write]);
		::close(pipeErr[FdIndex::Write]);

		::execvp("/bin/ls", argv);

		::_exit(127);
	}

	::close(pipeIn[FdIndex::Read]);
	::close(pipeOut[FdIndex::Write]);
	::close(pipeErr[FdIndex::Write]);

	if (pid <= ProcessStatus::ChildError) {
		// failure, close the other ends of pipes
		std::cout << "Child Error: " << TRACE_VAR(pid) << std::endl;
	} else {
		// ProcessStatus::ParentOk

		// Here you can:
		//   - write to   pipeIn[FdIndex::Write]
		//   - read  from pipeOut[FdIndex::Read]
		//   - read  from pipeErr[FdIndex::Read]
		// to communicate with the child process
		std::cout << "Parent: " << TRACE_VAR(pid) << std::endl;

		// read
		::sleep(2);
		std::cout << "Parent: readed" << std::endl;

		// wait
		int status {};
		::waitpid(pid, &status, 0);

		std::cout << "Parent: waited, " << TRACE_VAR(status) << std::endl;
	}

	std::cout << "Finished: " << TRACE_VAR(pid) << std::endl;

	return EXIT_SUCCESS;
}
//-------------------------------------------------------------------------------------------------

#if OUTPUT

Parent: pid: 21470
Child: pid: 0
Parent: readed
Parent: waited, status: 0
Finished: pid: 21470

#endif
