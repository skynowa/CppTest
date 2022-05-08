 /*
 * \file  SignalsToException_2.cpp
 * \brief
 *
 * \review
 */


#include <StdStream/StdStream.h>
#include <StdTest/StdTest.h>
#include <Stl.h>
#include "SignalHandler.h"
//-------------------------------------------------------------------------------------------------
int main(int argsNum, char **)
{
	int exitCode {};

	try {
		SignalHandler signalHandler;

		// Register signal handler to handle kill signal
		signalHandler.setupSignalHandlers();

		// Infinite loop until signal ctrl-c (KILL) received
		while ( !signalHandler.gotExitSignal() ) {
			std::cout << "Sleep..." << std::endl;
			::sleep(1);

			int iRv = 0;

			std::cout << iRv << std::endl;
			iRv = 10 / (1 - argsNum);
			std::cout << iRv << std::endl;
		}

		exitCode = EXIT_SUCCESS;
	}
	catch (const SignalException &e) {
		std::cout << "SignalException: " << e.what() << std::endl;

		exitCode = EXIT_FAILURE;
	}

	return exitCode;
}
//-------------------------------------------------------------------------------------------------


#if OUTPUT



#endif
