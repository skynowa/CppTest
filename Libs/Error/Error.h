/*!
@file Error.h

@brief      This file implements Error.
*/

#pragma once

#include <StdStream.h>
#include <StdTest.h>
#include <Stl.h>

#include <memory>
#include <tuple>
#include <ostream>
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
	Error(const Level level, const int code, const std::string &msg);
   ~Error();
///@}

	explicit operator bool() const;

	static Error ok();
	static Error error(const Level level, const int code, const std::string &msg);
	static Error test(bool expr);

private:
	Level       _level {};
	int         _code {};
	std::string _msg {};
	// module
	// file
	// line
	// function
	// expression
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
