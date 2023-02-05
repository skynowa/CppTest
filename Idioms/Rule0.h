/**
 * \file  Rule0.h
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
//--------------------------------------------------------------------------------------------------
class Rule0
{
public:
	Rule0();
	explicit Rule0(const std::string &value);
	Rule0(const char *value);	// explicit - n/a

	Rule0(const Rule0 &obj) noexcept = delete;
	Rule0 & operator = (const Rule0 &obj) noexcept = delete;

	Rule0(Rule0 &&obj) noexcept = delete;
	Rule0 & operator = (Rule0 &&obj) noexcept = delete;

	~Rule0();

	friend std::ostream & operator << (std::ostream &os, const Rule0 &obj);

private:
	std::string _value {};

	void _log(const std::string &title, const std::string &msg) const;
};
//--------------------------------------------------------------------------------------------------
Rule0::Rule0()
{
	_log("Ctor", "Default");
}
//-------------------------------------------------------------------------------------------------
Rule0::Rule0(
	const std::string &a_value
) :
	_value(a_value)
{
	_log("Ctor", "const std::string &");
}
//-------------------------------------------------------------------------------------------------
// explicit - n/a
Rule0::Rule0(
	const char *a_value
) :
	_value(a_value)
{
	_log("Ctor", "const char *");
}
//--------------------------------------------------------------------------------------------------
Rule0::~Rule0() /* final */
{
	_log("Dtor", "");
	_log("", "");
}
//--------------------------------------------------------------------------------------------------
void
Rule0::_log(
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
	const Rule0 &a_obj
)
{
	return out_os << "{" << a_obj._value << "}";
}
//-------------------------------------------------------------------------------------------------
