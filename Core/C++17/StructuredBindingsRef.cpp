/**
 * \file  StructuredBindingsRef.cpp
 * \brief
 */


#include <StdStream.h>
#include <StdTest.h>
#include <Stl.h>
//--------------------------------------------------------------------------------------------------
struct Point
{
	int x;
	int y;
};
//--------------------------------------------------------------------------------------------------
int main(int, char **)
{
	Point p {1, 2};

	// Structure binding
	auto &[x_coord, y_coord] = p;

    // std::cout << "type: " << typeid( decltype([x_coord, y_coord]) ).name() << std::endl;

	std::cout << TRACE_VAR(x_coord) << std::endl;
	std::cout << TRACE_VAR(y_coord) << std::endl;

	x_coord = 7;
	y_coord = 8;

	std::cout << TRACE_VAR(x_coord) << std::endl;
	std::cout << TRACE_VAR(y_coord) << std::endl;

  	std::cout << TRACE_VAR(p.x) << std::endl;
  	std::cout << TRACE_VAR(p.y) << std::endl;

    return EXIT_SUCCESS;
}
//-------------------------------------------------------------------------------------------------


#if OUTPUT

x_coord: 1
y_coord: 2
x_coord: 7
y_coord: 8
p.x: 7
p.y: 8

#endif
