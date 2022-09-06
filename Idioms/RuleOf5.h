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
	std::size_t i {};

///\name ctors, dtor
///\{
	RuleOf5();
	RuleOf5(const RuleOf5 &obj);
	RuleOf5(RuleOf5 &&obj);

	~RuleOf5();
///\}

	RuleOf5 & operator = (const RuleOf5 &obj);
	RuleOf5 & operator = (RuleOf5 &&obj);
};
//--------------------------------------------------------------------------------------------------
RuleOf5::RuleOf5()
{
	STD_TRACE_FUNC
}
//--------------------------------------------------------------------------------------------------
RuleOf5::RuleOf5(
	const RuleOf5 &a_obj
) :
	i {a_obj.i}
{
	STD_TRACE_FUNC
}
//--------------------------------------------------------------------------------------------------
RuleOf5::RuleOf5(
	RuleOf5 &&a_obj
) :
	i( std::move(a_obj.i) )
{
	STD_TRACE_FUNC
}
//--------------------------------------------------------------------------------------------------
RuleOf5::~RuleOf5() /* final */
{
	STD_TRACE_FUNC
}
//--------------------------------------------------------------------------------------------------
RuleOf5 &
RuleOf5::operator = (
	const RuleOf5 &a_obj
)
{
	STD_TRACE_FUNC

	if (this == &a_obj) {
		return *this;
	}

	i = a_obj.i;

	return *this;
}
//--------------------------------------------------------------------------------------------------
RuleOf5 &
RuleOf5::operator = (
	RuleOf5 &&a_obj
)
{
	STD_TRACE_FUNC

	if (this == &a_obj) {
		return *this;
	}

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
