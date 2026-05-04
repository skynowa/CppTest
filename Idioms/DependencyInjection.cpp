/**
 * \file  DependencyInjection.cpp
 * \brief An object receives dependencies from outside instead of creating them itself
 *
 * Demonstrates passing a service dependency through a constructor.
 *
 * \see   https://github.com/boost-ext/di
 */


#include <StdStream/StdStream.h>
#include <StdTest/StdTest.h>
#include <Stl.h>
//--------------------------------------------------------------------------------------------------
class ILogger
{
public:
	virtual ~ILogger() = default;

	virtual void write(const std::string &a_message) = 0;
};
//--------------------------------------------------------------------------------------------------
class ConsoleLogger :
	public ILogger
{
public:
	void write(const std::string &a_message) override
	{
		std::cout << "log: " << a_message << std::endl;
	}
};
//--------------------------------------------------------------------------------------------------
class UserService
{
public:
	explicit UserService(ILogger &a_logger) :
		_logger{a_logger}
	{
	}

	void createUser(const std::string &a_name)
	{
		_logger.write("create user '" + a_name + "'");
	}

private:
	ILogger &_logger;
};
//--------------------------------------------------------------------------------------------------
int main(int, char **)
{
	ConsoleLogger logger;
	UserService service(logger);

	service.createUser("Alex");

    return EXIT_SUCCESS;
}
//--------------------------------------------------------------------------------------------------


#if OUTPUT

log: create user 'Alex'

#endif
