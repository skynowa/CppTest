/**
 * \file
 * \brief
 *
 * \todo
 */

/*
Command contains an action that you need to defer for some reason.
We split the task into two commands (CommandDefence and CommandAttack),
and queue them up in Commands.
*/


#include <vector>
#include <algorithm>
#include <iostream>

//-------------------------------------------------------------------------------------------------
class ICommand
{
public:
	virtual ~ICommand() { }
	virtual void execute() = 0;
};
//-------------------------------------------------------------------------------------------------
class CommandDefence : public ICommand
{
public:
	void execute()
	{
		std::cout << "command_defence;";
	}
};
//-------------------------------------------------------------------------------------------------
class CommandAttack : public ICommand
{
public:
	void execute()
	{
		std::cout << "command_attack;" << std::endl;
	}
};
//-------------------------------------------------------------------------------------------------
class Commands
{
	std::vector<ICommand *> _commands;

	struct ExecuteCommand
	{
		void operator()(ICommand *command)
		{
			command->execute();
		}
	};

public:
	void addCommand(ICommand &command)
	{
		_commands.push_back(&command);
	}

	void execute()
	{
		std::for_each(_commands.begin(), _commands.end(), ExecuteCommand());
	}
};
//-------------------------------------------------------------------------------------------------
int main()
{
	CommandDefence command_defence;
	CommandAttack  command_attack;

	Commands commands;
	commands.addCommand(command_defence);
	commands.addCommand(command_attack);
	commands.execute();

	return 0;
}
//-------------------------------------------------------------------------------------------------
