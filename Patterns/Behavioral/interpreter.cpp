/*
Interpreter processes commands and performs actions based on its input.
Here we create a simple command language consisting of single characters.
*/


#include <string>
#include <iostream>
#include <stdexcept>

//-------------------------------------------------------------------------------------------------
class Interpreter
{
public:
	template<typename T>
	void run(T from, T to)
	{
		for (T i = from; i != to; ++ i) {
			switch (*i) {
			case 'h':
				std::cout << "Hello";
				break;
			case ' ':
				std::cout << ' ';
				break;
			case 'w':
				std::cout << "world";
				break;
			case '!':
				std::cout << '!';
				break;
			case 'n':
				std::cout << std::endl;
				break;
			default:
				throw std::runtime_error("Unknown command");
			}
		} // for
	}
};
//-------------------------------------------------------------------------------------------------
void hello_world(const std::string &script)
{
	Interpreter interpreter;
	interpreter.run(script.begin(), script.end());
}
//-------------------------------------------------------------------------------------------------
int main()
{
	hello_world("h w!n");

	return 0;
}
//-------------------------------------------------------------------------------------------------
