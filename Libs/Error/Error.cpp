 /*
 * \file  Error.cc
 * \brief
 *
 * \todo
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
	return {Level::Error, 10, "Test fail", a_expr};
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
		<< "{"
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
    std::cout << "ok: "    << Error::ok() << std::endl;
    std::cout << "error: " << Error::error(Error::Level::Warning, 202, "Warning fail", false) << std::endl;
    std::cout << "test: "  << Error::test(true) << std::endl;
    std::cout << "test: "  << Error::test(false) << std::endl;
    std::cout << std::endl;
    std::cout << "ok: "    << Error() << std::endl;
    std::cout << "error: " << Error(Error::Level::Warning, 202, "Warning fail", false) << std::endl;
//    std::cout << "xxx: " << Error(true) << std::endl;
//    std::cout << "xxx: " << Error(false) << std::endl;

    return EXIT_SUCCESS;
}
//--------------------------------------------------------------------------------------------------

#if OUTPUT

ok:    {1, 0, 0, , 1}
error: {0, 4, 202, Warning fail, 0}
test:  {0, 5, 10, Test fail, 1}
test:  {0, 5, 10, Test fail, 0}

ok:    {1, 0, 0, , 1}
error: {0, 4, 202, Warning fail, 0}

#endif
