/**
 * \file  ClassTemplateArgDeduction_CTAD.cpp
 * \brief CTAD - Class template argument deduction
 *
 * https://en.cppreference.com/w/cpp/language/class_template_argument_deduction
 *
 * In order to instantiate a class template, every template argument must be known,
 * but not every template argument has to be specified.
 * In the following contexts the compiler will deduce the template arguments from the type of the
 * initializer
 */


#include <StdStream/StdStream.h>
#include <StdTest/StdTest.h>
#include <Stl.h>
//--------------------------------------------------------------------------------------------------
// new-expressions
template<class T>
class A
{
public:
	explicit A(
		const T a_t1,
		const T a_t2
	) :
		_t1{a_t1},
		_t2{a_t2}
	{
	}

	void
	print(std::ostream &out_os) const
	{
		out_os << "{" << _t1 << "," << _t2 << "}";
	}

private:
	const T _t1 {};
	const T _t2	{};
};
//--------------------------------------------------------------------------------------------------
int main(int, char **)
{
	// any declaration that specifies initialization of a variable and variable template
	{
		// deduces to std::pair<int, double> p(2, 4.5);
		std::pair p(2, 4.5);
		std::cout << TRACE_VAR(p) << std::endl;

		// same as auto t = std::make_tuple(4, 3, 2.5);
		std::tuple t(4, 3, 2.5);
		std::cout << TRACE_VAR(t) << std::endl;

		// same as std::less<void> l;
		std::less l;
		std::cout << TRACE_VAR(l(1, 2)) << std::endl;

		// std::vector<unsigned int>
		std::vector v{1U, 2U, 3U};
		std::cout << TRACE_VAR(v) << std::endl;
	}

	// new-expressions
	{
		auto a = new A{'a', 'b'}; // allocated type is A<char>
		std::cout << TRACE_VAR(*a) << std::endl;
	}

	// function-style cast expressions
	{
		// deduces to std::lock_guard<std::mutex>
		{
			std::mutex m;

			auto locker = std::lock_guard(m);
		}

		// deduces to std::back_insert_iterator<T>,
		// where T is the type of the container vi2
		if constexpr (0) {
			std::vector<int> v1;
			std::vector<int> v2;

			std::copy_n(v1, 3, std::back_insert_iterator(v2));
		}
	}

    return EXIT_SUCCESS;
}
//--------------------------------------------------------------------------------------------------


#if OUTPUT

p: std::pair: {2,4.5}
t: std::tuple (size=3): {4,3,2.5}
l(1, 2): 1
v: std::vector (size=3): {1,2,3}
*a: {a,b}

#endif
