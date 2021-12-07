/**
 * \file  ForEnum.cpp
 * \brief
 *
 * \review
 */


#include <StdStream.h>
#include <StdTest.h>
#include <Stl.h>
//-------------------------------------------------------------------------------------------------
enum Type
{
	a    = 1,
	b    = 2,
	c    = 3,
	Last = c + 1
};

static const Type All[] {a, b, c};

void trace(const Type e)
{
	std::cout << e << ",";
}
//-------------------------------------------------------------------------------------------------
int main(int, char **)
{
	// all
	for (const auto e : All) {
		trace(e);
	}
	std::cout << std::endl;

	// some
	for (const auto e : {a, c}) {
		trace(e);
	}
	std::cout << std::endl;

	// all
	std::for_each(std::begin(All), std::end(All), trace);
	std::cout << std::endl;

	// for
	for (Type e = a; e != Last; e = Type(e + 1)) {
		trace(e);
	}
	std::cout << std::endl;

	// TODO: for (bits)
	enum BitType
	{
		First,
		None  = First,
		Green = 0x1,
		White = 0x2,
		Blue  = 0x4,
		Last  = 0x8
	};

	// std::cout << BitType(Green << 1) << std::endl;

	// for (BitType e = First; e != Last; e = BitType(e << 1)) {
	// 	std::cout << (int)e << ",";
	// }
	// std::cout << std::endl;

    return EXIT_SUCCESS;
}
//--------------------------------------------------------------------------------------------------


#if OUTPUT

1,2,3,
1,3,
1,2,3,
1,2,3,

#endif
