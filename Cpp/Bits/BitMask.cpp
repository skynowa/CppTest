/**
 * \file  BitMask.cpp
 * \brief
 */


#include <StdStream/StdStream.h>
#include <StdTest/StdTest.h>
#include <Stl.h>
//-------------------------------------------------------------------------------------------------
int main(int, char **)
{
    #define GROUP_ROOMS_BY_MEALS	0x01  // [Default]
    #define GROUP_ROOMS_BY_RATE		0x02  // [Default]
    #define GROUP_ROOMS_BY_ADULTS	0x04
    #define GROUP_ROOMS_BY_BEDS		0x08  // [Default]
    #define GROUP_ROOMS_BY_VIEW		0x10  // [Default]
    #define GROUP_ROOMS_BY_SMOK		0x20  // [Default]
    #define GROUP_ROOMS_BY_MATCHING	0x40
    #define GROUP_ROOMS_BY_PRICE	0x80
    #define GROUP_ROOMS_BY_SIZE		0x100
    #define DEFAULT_GROUPING        (GROUP_ROOMS_BY_RATE|GROUP_ROOMS_BY_MEALS|GROUP_ROOMS_BY_BEDS|GROUP_ROOMS_BY_VIEW|GROUP_ROOMS_BY_SMOK)

    const int group_params = DEFAULT_GROUPING;

	if ((group_params & GROUP_ROOMS_BY_MATCHING) != 0) {
		std::cout << "GROUP_ROOMS_BY_MATCHING" << std::endl;
	}

	// [1] [use]
	if ((group_params & GROUP_ROOMS_BY_SIZE) != 0) {
		std::cout << "GROUP_ROOMS_BY_SIZE" << std::endl;
	}

	// [2] [Default]
	if ((group_params & GROUP_ROOMS_BY_BEDS) != 0) {
		std::cout << "GROUP_ROOMS_BY_BEDS" << std::endl;
	}

	// [3] [Default]
	if ((group_params & GROUP_ROOMS_BY_VIEW) != 0) {
		std::cout << "GROUP_ROOMS_BY_VIEW" << std::endl;
	}

	// [4] [Default]
	if ((group_params & GROUP_ROOMS_BY_SMOK) != 0) {
		std::cout << "GROUP_ROOMS_BY_SMOK" << std::endl;
	}

	// [5] [Default]
	if ((group_params & GROUP_ROOMS_BY_MEALS) != 0) {
		std::cout << "GROUP_ROOMS_BY_MEALS" << std::endl;
	}

	// [6] [use]
	if ((group_params & GROUP_ROOMS_BY_ADULTS) != 0) {
		std::cout << "GROUP_ROOMS_BY_ADULTS" << std::endl;
	}

	// [7] [Default]
	if ((group_params & GROUP_ROOMS_BY_RATE) != 0) {
		std::cout << "GROUP_ROOMS_BY_RATE" << std::endl;
	}

    return EXIT_SUCCESS;
}
//-------------------------------------------------------------------------------------------------


#if OUTPUT

---------------------------------------------
GROUP_ROOMS_BY_BEDS
GROUP_ROOMS_BY_VIEW
GROUP_ROOMS_BY_SMOK
GROUP_ROOMS_BY_MEALS
GROUP_ROOMS_BY_RATE
---------------------------------------------

#endif
