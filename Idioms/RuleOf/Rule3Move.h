/**
 * \file  Rule3Move.h
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
#if !defined(RULE_3_MOVE_OPTION_LOG)
	#define RULE_3_MOVE_OPTION_LOG 0
#endif
//--------------------------------------------------------------------------------------------------
class Rule3Move
{
public:
	Rule3Move();
	explicit Rule3Move(const std::string &value);

	Rule3Move(const Rule3Move &obj) noexcept = delete;
	Rule3Move & operator = (const Rule3Move &obj) noexcept = delete;

	Rule3Move(Rule3Move &&obj) noexcept;
	Rule3Move & operator = (Rule3Move &&obj) noexcept;

	~Rule3Move();

	friend std::ostream & operator << (std::ostream &os, const Rule3Move &obj);

private:
	std::string _value {};

	void _log(const std::string &title, const std::string &msg) const;
};
//--------------------------------------------------------------------------------------------------
Rule3Move::Rule3Move()
{
	_log("Ctor", "Default");
}
//-------------------------------------------------------------------------------------------------
Rule3Move::Rule3Move(
	const std::string &a_value
) :
	_value(a_value)
{
	_log("Ctor", "const std::string &");
}
//-------------------------------------------------------------------------------------------------
Rule3Move::Rule3Move(
	Rule3Move &&a_obj
) noexcept :
	_value{ std::move(a_obj._value) }
{
	_log("Ctor", "Move");
}
//--------------------------------------------------------------------------------------------------
Rule3Move &
Rule3Move::operator = (
	Rule3Move &&a_obj
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
Rule3Move::~Rule3Move() /* final */
{
	_log("Dtor", "");
	_log("", "");
}
//--------------------------------------------------------------------------------------------------
void
Rule3Move::_log(
	const std::string &a_title,
	const std::string &a_msg
) const
{
#if RULE_3_MOVE_OPTION_LOG
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
	const Rule3Move &a_obj
)
{
	return out_os << "{" << a_obj._value << "}";
}
//-------------------------------------------------------------------------------------------------
