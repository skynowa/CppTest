/**
 * \file  LambdaScopeFaultScenario.cpp
 * \brief
 *
 * \review
 */


#include <StdStream/StdStream.h>
#include <StdTest/StdTest.h>
#include <Stl.h>
//--------------------------------------------------------------------------------------------------
std::function<void ()>
getCallBack()
{
	int counter {10};

	// Capturing Local variables by Reference
	auto func = [&counter] () mutable
	{
		std::cout << "Inside Lambda :: " << TRACE_VAR(counter) << std::endl; // TODO: ????

		// Change the counter
		// Change will affect the outer variable because counter variable is
		// captured by Reference in Lambda function
		counter = 20;

		std::cout << "Inside Lambda :: After changing :: " << TRACE_VAR(counter) << std::endl;
	};

	return func;
}
//--------------------------------------------------------------------------------------------------
int main(int, char **)
{
	auto func = getCallBack();

	// Call the Lambda function
	func();

	// Lambda function will access and modify the variable that has been captured it by reference
	// But that variable was actually a local variable on stack which was removed from stack
	// when getCallbacK() returned
	// So, lambda function will basically corrupt the stack

    return EXIT_SUCCESS;
}
//--------------------------------------------------------------------------------------------------


#if OUTPUT

Inside Lambda :: counter: 21881
Inside Lambda :: After changing :: counter: 20

Segmentation fault (core dumped)

#endif
