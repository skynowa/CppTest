/**
 * \file  RuleOfFive.cpp
 * \brief Rule of five
 *
 * Because the presence of a user-defined destructor, copy-constructor, or copy-assignment operator
 * prevents implicit definition of the move constructor and the move assignment operator, any class
 * for which move semantics are desirable, has to declare all five special member functions
 */


#include <StdStream.h>
#include <StdTest.h>
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

	// copy constructor
	RuleOfFive(const RuleOfFive &a_other) :
		RuleOfFive(a_other._buff)
	{
		_trace("RuleOfFive(const RuleOfFive &)");
	}

	// move constructor
	RuleOfFive(RuleOfFive &&a_other) noexcept :
		_buff(std::exchange(a_other._buff, nullptr))
	{
		_trace("RuleOfFive(RuleOfFive &&a_other)");
	}
///@}

///@name ops
///@{
	// copy assignment
	RuleOfFive &
	operator = (const RuleOfFive &a_other)
	{
		_trace("operator = (const RuleOfFive &)");

		return *this = RuleOfFive(a_other);
	}

	// move assignment
	RuleOfFive &
	operator = (RuleOfFive &&a_other) noexcept
	{
		_trace("operator = (RuleOfFive &&)");

		std::swap(_buff, a_other._buff);

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
int main(int, char **)
{
	std::cout << std::endl;
	std::cout << "------------------------------" << std::endl;

	{
		std::cout << "Ctor default:\n" << std::endl;

		RuleOfFive a;
	}
	std::cout << "------------------------------" << std::endl;

	{
		std::cout << "Ctor 1 param:\n" << std::endl;

		RuleOfFive a("a");
	}
	std::cout << "------------------------------" << std::endl;

	{
		std::cout << "Ctor copy:\n" << std::endl;

		RuleOfFive b("b");

		RuleOfFive a = b;
	}
	std::cout << "------------------------------" << std::endl;

	return EXIT_SUCCESS;
}
//--------------------------------------------------------------------------------------------------


#if OUTPUT



#endif
