/**
 * \file  Grasp.cpp
 * \brief GRASP (object-oriented design) - General Responsibility Assignment Software Patterns (or Principles)
 *
 * Demonstrates assigning order calculations to the objects that own the data.
 */


#include <StdStream/StdStream.h>
#include <StdTest/StdTest.h>
#include <Stl.h>
//--------------------------------------------------------------------------------------------------
class OrderLine
{
public:
	OrderLine(std::string a_name, double a_price, size_t a_count) :
		_name{std::move(a_name)},
		_price{a_price},
		_count{a_count}
	{
	}

	double subtotal() const
	{
		return _price * static_cast<double>(_count);
	}

	const std::string &
	name() const
	{
		return _name;
	}

private:
	std::string _name;
	double      _price {};
	size_t      _count {};
};
//--------------------------------------------------------------------------------------------------
class Order
{
public:
	void add(OrderLine a_line)
	{
		_lines.push_back(std::move(a_line));
	}

	double total() const
	{
		return std::accumulate(_lines.begin(), _lines.end(), 0.0,
			[](double a_sum, const OrderLine &a_line)
			{
				return a_sum + a_line.subtotal();
			});
	}

	void print() const
	{
		for (const auto &line : _lines) {
			std::cout << line.name() << ": " << line.subtotal() << std::endl;
		}

		std::cout << "total: " << total() << std::endl;
	}

private:
	std::vector<OrderLine> _lines;
};
//--------------------------------------------------------------------------------------------------
int main(int, char **)
{
	Order order;

	order.add(OrderLine("book", 10.0, 2));
	order.add(OrderLine("pen", 1.5, 3));

	order.print();

    return EXIT_SUCCESS;
}
//--------------------------------------------------------------------------------------------------


#if OUTPUT

book: 20
pen: 4.5
total: 24.5

#endif
