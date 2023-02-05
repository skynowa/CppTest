/**
 * \file  Rule5.h
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
class Rule5
{
public:
	Rule5();
	explicit Rule5(const std::string &value);
	Rule5(const char *value);	// explicit - n/a

#if RULEOF5_OPTION_COPY
	Rule5(const Rule5 &obj) noexcept;
	Rule5 & operator = (const Rule5 &obj) noexcept;
#endif

#if RULEOF5_OPTION_MOVE
	Rule5(Rule5 &&obj) noexcept;
	Rule5 & operator = (Rule5 &&obj) noexcept;
#endif

	~Rule5();

	friend std::ostream & operator << (std::ostream &os, const Rule5 &obj);

private:
	std::string _value {};

	void _log(const std::string &title, const std::string &msg) const;
};
//--------------------------------------------------------------------------------------------------
Rule5::Rule5()
{
	_log("Ctor", "Default");
}
//-------------------------------------------------------------------------------------------------
Rule5::Rule5(
	const std::string &a_value
) :
	_value(a_value)
{
	_log("Ctor", "const std::string &");
}
//-------------------------------------------------------------------------------------------------
// explicit - n/a
Rule5::Rule5(
	const char *a_value
) :
	_value(a_value)
{
	_log("Ctor", "const char *");
}
//-------------------------------------------------------------------------------------------------

#if RULEOF5_OPTION_COPY
//--------------------------------------------------------------------------------------------------
Rule5::Rule5(
	const Rule5 &a_obj
) noexcept :
	_value{a_obj._value}
{
	_log("Ctor", "Copy");
}
//--------------------------------------------------------------------------------------------------
Rule5 &
Rule5::operator = (
	const Rule5 &a_obj
) noexcept
{
	if (this == &a_obj) {
		return *this;
	}

	_log("Op", "Copy");

	_value = a_obj._value;

	return *this;
}
//-------------------------------------------------------------------------------------------------
#endif

#if RULEOF5_OPTION_MOVE
//--------------------------------------------------------------------------------------------------
Rule5::Rule5(
	Rule5 &&a_obj
) noexcept :
	_value{ std::move(a_obj._value) }
{
	_log("Ctor", "Move");
}
//--------------------------------------------------------------------------------------------------
Rule5 &
Rule5::operator = (
	Rule5 &&a_obj
) noexcept
{
	if (this == &a_obj) {
		return *this;
	}

	_log("Op", "Move");

	_value = std::move(a_obj._value);

	return *this;
}
//--------------------------------------------------------------------------------------------------
#endif

//--------------------------------------------------------------------------------------------------
Rule5::~Rule5() /* final */
{
	_log("Dtor", "");
	_log("", "");
}
//--------------------------------------------------------------------------------------------------
void
Rule5::_log(
	const std::string &a_title,
	const std::string &a_msg
) const
{
#if RULEOF5_OPTION_LOG
	std::cout << "[" << a_title << "] " << a_msg << std::endl;
#else
	STD_UNUSED(a_title);
	STD_UNUSED(a_msg);
#endif
}
//--------------------------------------------------------------------------------------------------
inline std::ostream &
operator << (
	std::ostream  &out_os,
	const Rule5 &a_obj
)
{
	return out_os << "{" << a_obj._value << "}";
}
//-------------------------------------------------------------------------------------------------
