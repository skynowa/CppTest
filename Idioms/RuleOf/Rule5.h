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
// Logs
#if !defined(RULE_5_OPTION_LOG)
	#define RULE_5_OPTION_LOG 0
#endif

#if !defined(RULE_5_OPTION_COPY)
	#define RULE_5_OPTION_COPY 1
#endif

#if !defined(RULE_5_OPTION_MOVE)
	#define RULE_5_OPTION_MOVE 1
#endif
//--------------------------------------------------------------------------------------------------
class Rule5
{
public:
	Rule5();
	explicit Rule5(const std::string &value);

#if RULE_5_OPTION_COPY
	Rule5(const Rule5 &obj) noexcept;
	Rule5 & operator = (const Rule5 &obj) noexcept;
#else
	Rule5(const Rule5 &obj) noexcept = delete;
	Rule5 & operator = (const Rule5 &obj) noexcept = delete;
#endif

#if RULE_5_OPTION_MOVE
	Rule5(Rule5 &&obj) noexcept;
	Rule5 & operator = (Rule5 &&obj) noexcept;
#else
	Rule5(Rule5 &&obj) noexcept = delete;
	Rule5 & operator = (Rule5 &&obj) noexcept = delete;
#endif

	~Rule5();

	friend std::ostream & operator << (std::ostream &os, const Rule5 &obj);

private:
	std::string _value;

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

#if RULE_5_OPTION_COPY
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

#if RULE_5_OPTION_MOVE
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
#if RULE_5_OPTION_LOG
	const std::string title = a_title.empty() ? a_title : ("[" + a_title + "] ");

	std::cout << title << a_msg << std::endl;
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
