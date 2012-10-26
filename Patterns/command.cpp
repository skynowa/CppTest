/*
Command contains an action that you need to defer for some reason. 
We split the task into two commands (PrintHello and PrintWorld), 
and queue them up in Commands.
*/

#include <vector>
#include <algorithm>
#include <iostream>

class Command
{
public:
	virtual ~Command() { }
	virtual void execute()=0;
};

class PrintHello : public Command
{
public:
	void execute()
	{
		std::cout << "Hello ";
	}
};

class PrintWorld : public Command
{
public:
	void execute()
	{
		std::cout << "world!" << std::endl;
	}
};

class Commands
{
	std::vector<Command*> commands;
	struct ExecuteCommand
	{
		void operator()(Command * cmd)
		{
			cmd->execute();
		}
	};
public:
	void add_command(Command & cmd)
	{
		commands.push_back(&cmd);
	}
	void execute()
	{
		std::for_each(commands.begin(), commands.end(), ExecuteCommand());
	}
};

void hello_world(Commands & commands)
{
	commands.execute();
}

int main()
{
	Commands commands;
	PrintHello hello;
	PrintWorld world;
	commands.add_command(hello);
	commands.add_command(world);
	hello_world(commands);
	return 0;
}

