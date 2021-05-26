/**
 * \file  OverloadingInputOutputOperator.cpp
 * \brief
 */


#include <StdStream.h>
#include <StdTest.h>
#include <Stl.h>
//--------------------------------------------------------------------------------------------------
class Point
{
public:
	Point(
		double x = 0.0,
		double y = 0.0,
		double z = 0.0
	) :
		m_x(x),
		m_y(y),
		m_z(z)
	{
	}

	friend
	std::ostream &operator << (std::ostream &out, const Point &point);

	friend
	std::istream &operator >> (std::istream &in, Point &point);

private:
	double m_x{}, m_y{}, m_z{};
};
//--------------------------------------------------------------------------------------------------
// If you try to return std::ostream by value, you’ll get a compiler error.
// This happens because std::ostream specifically disallows being copied.
std::ostream &
operator<< (std::ostream &out, const Point &point)
{
	out << "Point(" << point.m_x << ", " << point.m_y << ", " << point.m_z << ")";

	return out;
}
//--------------------------------------------------------------------------------------------------
std::istream &
operator >> (std::istream &in, Point &point)
{
	in >> point.m_x;
	in >> point.m_y;
	in >> point.m_z;

	return in;
}
//--------------------------------------------------------------------------------------------------
int main()
{
	Point p1(1.0, 2.0, 3.0);
	Point p2(4.0, 5.0, 6.0);

	std::cout << p1 << " " << p2 << std::endl;

	Point p3;
	std::cin >> p3;

	std::cout << "You entered " << p3 << std::endl;

    return EXIT_SUCCESS;
}
//--------------------------------------------------------------------------------------------------


#if OUTPUT

Point(1, 2, 3) Point(4, 5, 6)

1
2
3333

You entered Point(1, 2, 3333)

#endif
