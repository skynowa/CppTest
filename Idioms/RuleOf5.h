/**
 * \file  RuleOf5.h
 * \brief The rule of three/five/zero
 *
 * \see   https://en.cppreference.com/w/cpp/language/rule_of_three
 */


#include <StdStream/StdStream.h>
#include <StdTest/StdTest.h>
#include <Stl.h>
//--------------------------------------------------------------------------------------------------
class RuleOf5
{
public:
///\name ctors, dtor
///\{
	RuleOf5();
	RuleOf5(const RuleOf5 &obj);
	RuleOf5(RuleOf5 &&obj);

	~RuleOf5();
///\}

///\name operators
///\{
	RuleOf5 & operator = (const RuleOf5 &obj);
	RuleOf5 & operator = (RuleOf5 &&obj);

	friend std::ostream & operator << (std::ostream &os, const RuleOf5 &obj);
///\}

private:
	std::size_t i {};
};
//--------------------------------------------------------------------------------------------------
RuleOf5::RuleOf5()
{
	std::cout << "\t::: [Ctor] Default :::" << std::endl;
}
//--------------------------------------------------------------------------------------------------
RuleOf5::RuleOf5(
	const RuleOf5 &a_obj
) :
	i{a_obj.i}
{
	std::cout << "\t::: [Ctor] Copy :::" << std::endl;
}
//--------------------------------------------------------------------------------------------------
RuleOf5::RuleOf5(
	RuleOf5 &&a_obj
) :
	i{ std::move(a_obj.i) }
{
	std::cout << "\t::: [Ctor] Move :::" << std::endl;
}
//--------------------------------------------------------------------------------------------------
RuleOf5::~RuleOf5() /* final */
{
	std::cout << "\t::: [Dtor] :::" << std::endl;
}
//--------------------------------------------------------------------------------------------------
RuleOf5 &
RuleOf5::operator = (
	const RuleOf5 &a_obj
)
{
	if (this == &a_obj) {
		return *this;
	}

	std::cout << "\t::: [Op] Copy assignment :::" << std::endl;

	i = a_obj.i;

	return *this;
}
//--------------------------------------------------------------------------------------------------
RuleOf5 &
RuleOf5::operator = (
	RuleOf5 &&a_obj
)
{
	if (this == &a_obj) {
		return *this;
	}

	std::cout << "\t::: [Op] Move assignment :::" << std::endl;

	i = std::move(a_obj.i);

	return *this;
}
//--------------------------------------------------------------------------------------------------
inline std::ostream &
operator << (
	std::ostream  &out_os,
	const RuleOf5 &a_obj
)
{
	return out_os << "{" << a_obj.i << "}";
}
//-------------------------------------------------------------------------------------------------
