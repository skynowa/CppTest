/**
 * \file  main.cpp
 * \brief
 */


#include "../StdTest.h"
#include <algorithm>

//-------------------------------------------------------------------------------------------------
enum Type
{
	a    = 1,
	b    = 2,
	c    = 3,
	Last = 4
};

static const Type All[] = {a, b, c};

void log(const Type e)
{
	std::cout << e << ",";
}
//-------------------------------------------------------------------------------------------------
int main(int argsNum, char **args)
{
	// all
	for (const auto e : All) {
		log(e);
	}
	std::cout << std::endl;

	// some
	for (const auto e : {a, c}) {
		log(e);
	}
	std::cout << std::endl;

	// all
	std::for_each(std::begin(All), std::end(All), log);
	std::cout << std::endl;

	// for
	for (Type e = a; e != Last; e = Type(e + 1)) {
		log(e);
	}
	std::cout << std::endl;

	// for (bits)
	enum BitType
	{
		First,
		None  = First,
		Green = 0x1,
		White = 0x2,
		Blue  = 0x4,
		Last  = 0x8,
	};


	// std::cout << BitType(Green << 1) << std::endl;

	// return 0;

	for (BitType e = First; e != Last; e = BitType(e << 1)) {
		std::cout << (int)e << ",";
	}
	std::cout << std::endl;

	return 0;
}
//-------------------------------------------------------------------------------------------------


#if OUTPUT

1,2,3,
1,3,
1,2,3,

#endif
