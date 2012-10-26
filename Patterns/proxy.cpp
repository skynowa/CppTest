/*
Proxy allows one object to stand for something else.  
So whilst you think you are dealing with one object, 
you are actually dealing with something else.  
In this example, CoutProxy stands for std::cout.
*/

#include <iostream>
#include <string>

class CoutProxy
{
public:
	void write(const std::string & str) const
	{
		std::cout << str;
	}
};

void hello_world(const CoutProxy & cout)
{
	cout.write("Hello world!\n");
}

int main()
{
	hello_world(CoutProxy());
	return 0;
}

