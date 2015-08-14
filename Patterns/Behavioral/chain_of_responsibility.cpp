/*
Performs staged processing using a series of different objects.
*/


#include <string>
#include <iostream>

//-------------------------------------------------------------------------------------------------
class Output
{
public:
	void output(const std::string &str)
	{
		std::cout << str << std::endl;
	}
};
//-------------------------------------------------------------------------------------------------
class World
{
public:
	World(Output & out) : out(out) { }

	void output(const std::string & str)
	{
		out.output(str + " world!");
	}

private:
	Output &out;
};
//-------------------------------------------------------------------------------------------------
class Hello
{
public:
	Hello(World & world) : world(world) { }

	void output()
	{
		world.output("Hello");
	}

private:
	World &world;
};
//-------------------------------------------------------------------------------------------------
void hello_world(Hello & hello)
{
	hello.output();
}
//-------------------------------------------------------------------------------------------------
int main()
{
	Output output;
	World world(output);
	Hello hello(world);

	hello_world(hello);

	return 0;
}
//-------------------------------------------------------------------------------------------------
