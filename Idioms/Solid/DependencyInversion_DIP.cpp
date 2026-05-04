/**
 * \file  DependencyInversion_DIP.cpp
 * \brief Classes should depend upon interfaces instead of concrete classes and functions
 *
 * Demonstrates sending notifications through an abstract message sender.
 */


#include <StdStream/StdStream.h>
#include <StdTest/StdTest.h>
#include <Stl.h>
//--------------------------------------------------------------------------------------------------
class IMessageSender
{
public:
	virtual ~IMessageSender() = default;

	virtual void send(const std::string &a_to, const std::string &a_text) = 0;
};
//--------------------------------------------------------------------------------------------------
class EmailSender :
	public IMessageSender
{
public:
	void send(const std::string &a_to, const std::string &a_text) override
	{
		std::cout << "email to " << a_to << ": " << a_text << std::endl;
	}
};
//--------------------------------------------------------------------------------------------------
class Notification
{
public:
	explicit Notification(IMessageSender &a_sender) :
		_sender{a_sender}
	{
	}

	void notify(const std::string &a_user)
	{
		_sender.send(a_user, "build finished");
	}

private:
	IMessageSender &_sender;
};
//--------------------------------------------------------------------------------------------------
int main(int, char **)
{
	EmailSender  sender;
	Notification notification(sender);

	notification.notify("dev@example.com");

    return EXIT_SUCCESS;
}
//--------------------------------------------------------------------------------------------------


#if OUTPUT

email to dev@example.com: build finished

#endif
