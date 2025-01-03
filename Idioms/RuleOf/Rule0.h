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
#if !defined(RULE_0_OPTION_LOG)
	#define RULE_0_OPTION_LOG 0
#endif
//--------------------------------------------------------------------------------------------------
class Rule0
{
public:
	Rule0();
	explicit Rule0(const std::string &value);

	Rule0(const Rule0 &obj) noexcept = delete;
	Rule0 & operator = (const Rule0 &obj) noexcept = delete;

	Rule0(Rule0 &&obj) noexcept = delete;
	Rule0 & operator = (Rule0 &&obj) noexcept = delete;

	~Rule0();

    const std::string &value() const;

	friend std::ostream & operator << (std::ostream &os, const Rule0 &obj);

private:
	std::string _value;

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
Rule0::~Rule0() /* final */
{
	_log("Dtor", "");
	_log("", "");
}
//--------------------------------------------------------------------------------------------------
const std::string &
Rule0::value() const
{
    return _value;
}
//--------------------------------------------------------------------------------------------------
void
Rule0::_log(
	const std::string &a_title,
	const std::string &a_msg
) const
{
#if RULE_0_OPTION_LOG
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
	std::ostream &out_os,
	const Rule0  &a_obj
)
{
	return out_os << "{" << a_obj._value << "}";
}
//-------------------------------------------------------------------------------------------------
