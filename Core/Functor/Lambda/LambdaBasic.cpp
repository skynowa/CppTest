/**
 * \file  LambdaBasic.cpp
 * \brief
 */


#include <StdStream.h>
#include <StdTest.h>
#include <Stl.h>
//--------------------------------------------------------------------------------------------------
int main(int, char **)
{
	int arr[] = {1, 2, 3, 4, 5};

	std::for_each(arr, arr + sizeof(arr)/sizeof(int),
		[](int x){
			std::cout << x <<" ";
		});

	std::cout << std::endl;

    return EXIT_SUCCESS;
}
//--------------------------------------------------------------------------------------------------


#if OUTPUT

1 2 3 4 5

#endif
