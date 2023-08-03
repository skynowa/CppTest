/**
 * \file  Rule3Copy.h
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
#if !defined(RULE_3_COPY_OPTION_LOG)
	#define RULE_3_COPY_OPTION_LOG 0
#endif
//--------------------------------------------------------------------------------------------------
class Rule3Copy
{
public:
	Rule3Copy();
	explicit Rule3Copy(const std::string &value);

	Rule3Copy(const Rule3Copy &obj) noexcept;
	Rule3Copy & operator = (const Rule3Copy &obj) noexcept;

	Rule3Copy(Rule3Copy &&obj) noexcept = delete;
	Rule3Copy & operator = (Rule3Copy &&obj) noexcept = delete;

	~Rule3Copy();

	friend std::ostream & operator << (std::ostream &os, const Rule3Copy &obj);

private:
	std::string _value {};

	void _log(const std::string &title, const std::string &msg) const;
};
//--------------------------------------------------------------------------------------------------
Rule3Copy::Rule3Copy()
{
	_log("Ctor", "Default");
}
//-------------------------------------------------------------------------------------------------
Rule3Copy::Rule3Copy(
	const std::string &a_value
) :
	_value(a_value)
{
	_log("Ctor", "const std::string &");
}
//-------------------------------------------------------------------------------------------------
Rule3Copy::Rule3Copy(
	const Rule3Copy &a_obj
) noexcept :
	_value{a_obj._value}
{
	_log("Ctor", "Copy");
}
//--------------------------------------------------------------------------------------------------
Rule3Copy &
Rule3Copy::operator = (
	const Rule3Copy &a_obj
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
Rule3Copy::~Rule3Copy() /* final */
{
	_log("Dtor", "");
	_log("", "");
}
//--------------------------------------------------------------------------------------------------
void
Rule3Copy::_log(
	const std::string &a_title,
	const std::string &a_msg
) const
{
#if RULE_3_COPY_OPTION_LOG
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
	const Rule3Copy &a_obj
)
{
	return out_os << "{" << a_obj._value << "}";
}
//-------------------------------------------------------------------------------------------------
