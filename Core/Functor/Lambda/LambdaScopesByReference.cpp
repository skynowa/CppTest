/**
 * \file  LambdaScopesByReference.cpp
 * \brief
 */


#include <StdStream.h>
#include <StdTest.h>
#include <Stl.h>
//--------------------------------------------------------------------------------------------------
int main(int, char **)
{
	std::string msg     = "Hello";
	int         counter = 10;

	// Defining Lambda function and
	// Capturing Local variables by Reference
	auto func = [&msg, &counter] () -> void
	{
		std::cout << "Inside Lambda :: msg = "     << msg     << std::endl;
		std::cout << "Inside Lambda :: counter = " << counter << std::endl;

		// Change the counter & msg
		// Change will affect the outer variable because counter variable is
		// captured by Reference in Lambda function
		msg     = "Temp";
		counter = 20;

		std::cout << "Inside Lambda :: After changing :: msg = "     << msg     << std::endl;
		std::cout << "Inside Lambda :: After changing :: counter = " << counter << std::endl;
	};

	// Call the Lambda function
	func();

	std::cout << "Outside Lambda msg = "     << msg     << std::endl;
	std::cout << "Outside Lambda counter = " << counter << std::endl;

    return EXIT_SUCCESS;
}
//--------------------------------------------------------------------------------------------------


#if OUTPUT

Inside Lambda :: msg = Hello
Inside Lambda :: counter = 10
Inside Lambda :: After changing :: msg = Temp
Inside Lambda :: After changing :: counter = 20
Outside Lambda msg = Temp
Outside Lambda counter = 20

#endif
