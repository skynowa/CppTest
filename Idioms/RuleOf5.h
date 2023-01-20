/**
 * \file  RuleOf5.h
 * \brief The rule of three/five/zero
 *
 * \see   https://en.cppreference.com/w/cpp/language/rule_of_three
 *
 * Because the presence of a user-defined destructor, copy-constructor, or copy-assignment operator
 * prevents implicit definition of the move constructor and the move assignment operator, any class
 * for which move semantics are desirable, has to declare all five special member functions
 */


#include <StdStream/StdStream.h>
#include <StdTest/StdTest.h>
#include <Stl.h>
//--------------------------------------------------------------------------------------------------
#if !defined(RULEOF5_OPTION_LOG)
	#define RULEOF5_OPTION_LOG 0
#endif

#if !defined(RULEOF5_OPTION_COPY)
	#define RULEOF5_OPTION_COPY 1
#endif

#if !defined(RULEOF5_OPTION_MOVE)
	#define RULEOF5_OPTION_MOVE 1
#endif
//--------------------------------------------------------------------------------------------------
class RuleOf5
{
public:
	RuleOf5();

	explicit RuleOf5(const std::string &a_value) :
		_value(a_value)
	{
	}

	// explicit - n/a
	RuleOf5(const char *a_value) :
		_value(a_value)
	{
	}

#if RULEOF5_OPTION_COPY
	RuleOf5(const RuleOf5 &obj) noexcept;
	RuleOf5 & operator = (const RuleOf5 &obj) noexcept;
#endif

#if RULEOF5_OPTION_MOVE
	RuleOf5(RuleOf5 &&obj) noexcept;
	RuleOf5 & operator = (RuleOf5 &&obj) noexcept;
#endif

	~RuleOf5();

	friend std::ostream & operator << (std::ostream &os, const RuleOf5 &obj);

private:
	std::string _value {};
};
//--------------------------------------------------------------------------------------------------
RuleOf5::RuleOf5()
{
#if RULEOF5_OPTION_LOG
	std::cout << "[Ctor] Default" << std::endl;
#endif
}
//-------------------------------------------------------------------------------------------------

#if RULEOF5_OPTION_COPY
//--------------------------------------------------------------------------------------------------
RuleOf5::RuleOf5(
	const RuleOf5 &a_obj
) noexcept :
	_value{a_obj._value}
{
#if RULEOF5_OPTION_LOG
	std::cout << "[Ctor] Copy" << std::endl;
#endif
}
//--------------------------------------------------------------------------------------------------
RuleOf5 &
RuleOf5::operator = (
	const RuleOf5 &a_obj
) noexcept
{
	if (this == &a_obj) {
		return *this;
	}

#if RULEOF5_OPTION_LOG
	std::cout << "[Op] Copy assignment" << std::endl;
#endif

	_value = a_obj._value;

	return *this;
}
//-------------------------------------------------------------------------------------------------
#endif

#if RULEOF5_OPTION_MOVE
//--------------------------------------------------------------------------------------------------
RuleOf5::RuleOf5(
	RuleOf5 &&a_obj
) noexcept :
	_value{ std::move(a_obj._value) }
{
#if RULEOF5_OPTION_LOG
	std::cout << "[Ctor] Move" << std::endl;
#endif
}
//--------------------------------------------------------------------------------------------------
RuleOf5 &
RuleOf5::operator = (
	RuleOf5 &&a_obj
) noexcept
{
	if (this == &a_obj) {
		return *this;
	}

#if RULEOF5_OPTION_LOG
	std::cout << "[Op] Move assignment" << std::endl;
#endif

	_value = std::move(a_obj._value);

	return *this;
}
//--------------------------------------------------------------------------------------------------
#endif

//--------------------------------------------------------------------------------------------------
RuleOf5::~RuleOf5() /* final */
{
#if RULEOF5_OPTION_LOG
	std::cout << "[Dtor]" << std::endl;
	std::cout << std::endl;
#endif
}
//--------------------------------------------------------------------------------------------------
inline std::ostream &
operator << (
	std::ostream  &out_os,
	const RuleOf5 &a_obj
)
{
	return out_os << "{" << a_obj._value << "}";
}
//-------------------------------------------------------------------------------------------------
