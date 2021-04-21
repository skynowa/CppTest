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
	const std::string &a_msg
) :
	_level{a_level},
	_code {a_code},
	_msg  {a_msg}
{
}
//-------------------------------------------------------------------------------------------------
Error::~Error()
{
}
//--------------------------------------------------------------------------------------------------
bool
Error::isOk() const
{
	if (_level == Level::Ok &&
		_code  == 0 &&
		_msg.empty())
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
	const std::string &a_msg
)
{
	return {a_level, a_code, a_msg};
}
//--------------------------------------------------------------------------------------------------
/*static*/
Error
Error::test(bool expr)
{
	return expr ? Error::ok() : Error::error(Level::Error, 10, "Test fail");
}
//--------------------------------------------------------------------------------------------------
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
		<< a_error._msg        << "}";

	return a_stream;
}
//--------------------------------------------------------------------------------------------------
int main(int, char **)
{
    std::cout << Error::ok() << std::endl;
    std::cout << Error::error(Error::Level::Warning, 202, "Warning fail") << std::endl;
    std::cout << Error::test(true) << std::endl;
    std::cout << Error::test(false) << std::endl;

    return EXIT_SUCCESS;
}
//--------------------------------------------------------------------------------------------------



