/**
 * \file  ScopesByValue.cpp
 * \brief
 */


#include <StdStream/StdStream.h>
#include <StdTest/StdTest.h>
#include <Stl.h>
//--------------------------------------------------------------------------------------------------
int main(int, char **)
{
	std::string msg     = "Hello";
	int         counter = 10;

	// Defining Lambda function and
	// Capturing Local variables by Value
	auto func = [msg, counter] () mutable -> void
	{
		std::cout << "Inside Lambda :: msg = " << msg << std::endl;
		std::cout << "Inside Lambda :: counter = " << counter << std::endl;

		// Change the counter & msg
		// Change will not affect the outer variable because counter variable is
		// captured by value in Lambda function
		msg     = "Temp";
		counter = 20;

		std::cout << "Inside Lambda :: After changing :: msg = " << msg << std::endl;
		std::cout << "Inside Lambda :: After changing :: counter = " << counter << std::endl;
	};

	// Call the Lambda function
	func();

	// Values of local variables are not changed.
	std::cout << "msg = " << msg << std::endl;
	std::cout << "counter = " << counter << std::endl;

    return EXIT_SUCCESS;
}
//--------------------------------------------------------------------------------------------------


#if OUTPUT

Inside Lambda :: msg = Hello
Inside Lambda :: counter = 10
Inside Lambda :: After changing :: msg = Temp
Inside Lambda :: After changing :: counter = 20
msg = Hello
counter = 10

#endif
