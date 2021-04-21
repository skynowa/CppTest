/*!
@file Error.cc

@brief      This file implements Error.
*/

#include "Error.h"


//--------------------------------------------------------------------------------------------------
Error::Error()
{
}
//--------------------------------------------------------------------------------------------------
Error::Error(
	const Level        a_level,
	const int          a_code,
	const std::string &a_msg,
	const bool         a_expr
) :
	_level{a_level},
	_code {a_code},
	_msg  {a_msg},
	_expr {a_expr}
{
}
//--------------------------------------------------------------------------------------------------
Error::~Error()
{
}
//--------------------------------------------------------------------------------------------------
bool
Error::isOk() const
{
	if (_level == Level::Ok &&
		_code  == 0 &&
		_msg.empty() &&
		_expr)
	{
		return true;
	}

	return false;
}
//-------------------------------------------------------------------------------------------------


/**************************************************************************************************
*   static
*
**************************************************************************************************/

//--------------------------------------------------------------------------------------------------
/* static */
Error
Error::ok()
{
	return Error();
}
//--------------------------------------------------------------------------------------------------
/* static */
Error
Error::error(
	const Level        a_level,
	const int          a_code,
	const std::string &a_msg,
	const bool         a_expr
)
{
	return {a_level, a_code, a_msg, a_expr};
}
//--------------------------------------------------------------------------------------------------
/* static */
Error
Error::test(
	const bool a_expr
)
{
	return a_expr ? Error::ok() : Error::error(Level::Error, 10, "Test fail", false);
}
//-------------------------------------------------------------------------------------------------


/**************************************************************************************************
*   friend
*
**************************************************************************************************/

//--------------------------------------------------------------------------------------------------
/* friend */
std::ostream &
operator << (
	std::ostream &a_stream,
	const Error  &a_error
)
{
	a_stream
		<< ">>> Error: {"
		<< a_error.isOk()      << ", "
		<< (int)a_error._level << ", "
		<< a_error._code       << ", "
		<< a_error._msg        << ", "
		<< a_error._expr
		<< "}"
		;

	return a_stream;
}
//--------------------------------------------------------------------------------------------------
int main(int, char **)
{
    std::cout << Error::ok() << std::endl;
    std::cout << Error::error(Error::Level::Warning, 202, "Warning fail", false) << std::endl;
    std::cout << Error::test(true) << std::endl;
    std::cout << Error::test(false) << std::endl;
    std::cout << std::endl;
    std::cout << Error() << std::endl;
    std::cout << Error(Error::Level::Warning, 202, "Warning fail", false) << std::endl;
//    std::cout << Error(true) << std::endl;
//    std::cout << Error(false) << std::endl;

    return EXIT_SUCCESS;
}
//--------------------------------------------------------------------------------------------------



