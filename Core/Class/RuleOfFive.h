/**
 * \file  RuleOfFive.h
 * \brief Rule of five
 *
 * Because the presence of a user-defined destructor, copy-constructor, or copy-assignment operator
 * prevents implicit definition of the move constructor and the move assignment operator, any class
 * for which move semantics are desirable, has to declare all five special member functions
 */


#include <StdStream/StdStream.h>
#include <StdTest/StdTest.h>
#include <Stl.h>
//--------------------------------------------------------------------------------------------------
class RuleOfFive
{
public:
///@name ctors, dtor
///@{
	RuleOfFive()
	{
		_trace("RuleOfFive()");
	}

	explicit RuleOfFive(const char *a_buff)
	{
		if (a_buff) {
			std::size_t n = std::strlen(a_buff) + 1;
			_buff = new char[n];
			std::memcpy(_buff, a_buff, n);
		}

		_trace("RuleOfFive(const char *)");
	}

	~RuleOfFive()
	{
		delete[] _buff;
		_buff = nullptr;

		_trace("~RuleOfFive()");
	}
///@}

///@name Copy
///@{
	// Ctor
	RuleOfFive(const RuleOfFive &a_other) :
		RuleOfFive(a_other._buff)
	{
		_trace("RuleOfFive(const RuleOfFive &)");
	}

	// Assignment
	RuleOfFive &
	operator = (const RuleOfFive &a_other)
	{
		*this = RuleOfFive(a_other);

		_trace("operator = (const RuleOfFive &)");

		return *this;
	}
///@}

///@name Move
///@{
	// Ctor
	RuleOfFive(RuleOfFive &&a_other) noexcept :
		_buff(std::exchange(a_other._buff, nullptr))
	{
		_trace("RuleOfFive(RuleOfFive &&a_other)");
	}

	// Assignment
	RuleOfFive &
	operator = (RuleOfFive &&a_other) noexcept
	{
		std::swap(_buff, a_other._buff);

		_trace("operator = (RuleOfFive &&)");

		return *this;
	}
///@}

private:
	char *_buff {};

	void
	_trace(const std::string &a_funcName) const
	{
		std::cout << a_funcName << ": " << (_buff ? _buff : "nullptr") << std::endl; \
	}
};
//--------------------------------------------------------------------------------------------------
