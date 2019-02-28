 /*
 * \file  main.cpp
 * \brief
 */


#include <StdTest.h>
#include <Stl.h>
#include "SignalHandler.h"
#include <iostream>
#include <unistd.h>
#include <stdlib.h>

using namespace std;


//-------------------------------------------------------------------------------------------------
int main(int argsNum, char **)
{
	int iret;

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

		iret = EXIT_SUCCESS;
	}
	catch (SignalException& e) {
		std::cout << "SignalException: " << e.what() << std::endl;
		iret = EXIT_FAILURE;
	}

	return(iret);
}
//-------------------------------------------------------------------------------------------------


#if OUTPUT



#endif

