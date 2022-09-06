/**
 * \file  RuleOf5.h
 * \brief
 *
 * \see   https://en.cppreference.com/w/cpp/language/rule_of_three
 * \todo
 */


#include <StdStream/StdStream.h>
#include <StdTest/StdTest.h>
#include <Stl.h>
//--------------------------------------------------------------------------------------------------
class IRuleOf5
{
public:
///\name ctors, dtor
///\{
	IRuleOf5() {};
	IRuleOf5(const IRuleOf5 &) {};
	IRuleOf5(IRuleOf5 &&) {};

	virtual ~IRuleOf5() {};
///\}

	virtual const IRuleOf5 & operator = (const IRuleOf5 &) = 0;
	virtual IRuleOf5 &       operator = (IRuleOf5 &&) = 0;
};
//--------------------------------------------------------------------------------------------------
class RuleOf5 final :
	public IRuleOf5
{
public:
///\name ctors, dtor
///\{
	RuleOf5();
	RuleOf5(const RuleOf5 &value);
	RuleOf5(RuleOf5 &&value);

	~RuleOf5() final;
///\}

	const IRuleOf5 & operator = (const IRuleOf5 &value) final;
	IRuleOf5 &       operator = (IRuleOf5 &&value) final;
};
//--------------------------------------------------------------------------------------------------
RuleOf5::RuleOf5()
{
	STD_TRACE_FUNC
}
//--------------------------------------------------------------------------------------------------
RuleOf5::RuleOf5(
	const RuleOf5 &a_value
) :
	IRuleOf5()
{
	STD_UNUSED(a_value);

	STD_TRACE_FUNC
}
//--------------------------------------------------------------------------------------------------
RuleOf5::RuleOf5(
	RuleOf5 &&a_value
)
{
	STD_UNUSED(a_value);

	STD_TRACE_FUNC
}
//--------------------------------------------------------------------------------------------------
RuleOf5::~RuleOf5() /* final */
{
	STD_TRACE_FUNC
}
//--------------------------------------------------------------------------------------------------
const IRuleOf5 &
RuleOf5::operator = (
	const IRuleOf5 &a_value
) /* final */
{
	STD_TRACE_FUNC

	if (this == &a_value) {
		return *this;
	}

	return a_value;
}
//--------------------------------------------------------------------------------------------------
IRuleOf5 &
RuleOf5::operator = (
	IRuleOf5 &&a_value
) /* final */
{
	STD_TRACE_FUNC

	if (this == &a_value) {
		return *this;
	}

	return a_value;
}
//--------------------------------------------------------------------------------------------------
