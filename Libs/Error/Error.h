 /*
 * \file  Error.h
 * \brief
 */


#pragma once

#include <StdStream/StdStream.h>
#include <StdTest/StdTest.h>
#include <Stl.h>
//--------------------------------------------------------------------------------------------------
class Error
{
public:
	enum class Level
	{
		Ok      = 0,
		Trace   = 1,
		Debug   = 2,
		Info    = 3,
		Warning = 4,
		Error   = 5,
		Fatal   = 6
	};

///@name ctors, dtor
///@{
	Error();
	Error(const Level level, const int code, const std::string &msg, const bool expr);
   ~Error();
///@}

	bool isOk() const;

///@name static
///@{
	static Error ok();
	static Error error(const Level level, const int code, const std::string &msg, const bool expr);
	static Error test(const bool expr);
///@}

private:
	const Level       _level {};
	const int         _code {};
	const std::string _msg {};
	// module
	// file
	// line
	// function
	const bool        _expr {true};
	// stackTrace


	friend
	std::ostream &operator << (std::ostream &stream, const Error &error);
};

template <typename T>
using error_expected_t = std::tuple<T, Error>;
//--------------------------------------------------------------------------------------------------
#define WTSCHECK(expr, e) \
	e = Error::Assert(expr); \
	if (e) { auto p = e.data(); \
		p->setExpression(#expr); \
		LOG_ADD_POSITION((*p)); \
		LOG_ADD_BACKTRACE((*p)); \
		p->setMessage("NOT "#expr); \
	}

#define WTSERROR_INFO(e, msg, ...) \
	LOG_ADD_INFO((*e.data()), msg, __VA_ARGS__)

#define WTSERROR_DATA(e, d) \
	auto &d = *e.data()

#define STREAMLOG_WTSERROR(log, e) \
	log.logger().put(e)
//--------------------------------------------------------------------------------------------------
