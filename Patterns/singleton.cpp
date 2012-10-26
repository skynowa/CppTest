/*
Singleton ensures that there is one, and only one instance of a class.  
Like global variables, everybody has access to that instance.  
Singleton should be used sparingly since the assumption that 
there should be just one of something usually ends up being wrong.  
Singleton is hard to write unit tests with.
*/

#include <iostream>

class HelloWorld
{
	HelloWorld() { }
	HelloWorld(const HelloWorld&);
public:
	void output()
	{
		std::cout << "Hello world!" << std::endl;
	}
	static HelloWorld & get()
	{
		static HelloWorld singleton;
		return singleton;
	}
};

void hello_world()
{
	HelloWorld::get().output();
}

int main()
{
	hello_world();
	return 0;
}

