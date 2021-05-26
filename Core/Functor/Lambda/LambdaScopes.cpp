/**
 * \file  LambdaScopes.cpp
 * \brief
 */


#include <StdStream.h>
#include <StdTest.h>
#include <Stl.h>
//--------------------------------------------------------------------------------------------------
int main(int, char **)
{
	int arr[] = {1, 2, 3, 4, 5};
	int mul = 5;

	std::for_each(arr, arr + sizeof(arr)/sizeof(int),
		[&](int x){
			std::cout << x <<" ";
			// Can modify 'mul' inside this function because all outer scope elements has write access.
			mul = 9;
		});

	std::cout << std::endl;
	std::cout << "mul = " << mul << std::endl;

	std::for_each(arr, arr + sizeof(arr)/sizeof(int),
		[=](int x){
			std::cout << x <<" ";
			// Cannot modify 'mul' inside this function because all outer scope elements has read only access.
			// m = 2;  Not Allowed
			// std::cout << mul << std::endl; Allowed
		});

	std::cout << std::endl;
	std::cout << "mul = " << mul << std::endl;

	std::for_each(arr, arr + sizeof(arr) / sizeof(int),
		[] (int x)
		{
			(void)x;

			// No access to mul inside this lambda function because
			// all outer scope elements are not visible here.
			// std::cout << mul << " ";
        });

    std::cout << std::endl;

    return EXIT_SUCCESS;
}
//--------------------------------------------------------------------------------------------------


#if OUTPUT

1 2 3 4 5
mul = 9
1 2 3 4 5
mul = 9


#endif
