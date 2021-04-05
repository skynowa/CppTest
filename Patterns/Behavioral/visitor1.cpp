/**
 * \file
 * \brief
 *
 * \todo
 */

/*
Visitor provides a call-back for every item in a collection.
This allows the implementation of the collection to hidden.

visitor1.cpp is the simplest type of visitor using templates.
The std::for_each template function that takes any kind of type.
visitor2.cpp uses the more traditional inheritance-based polymorphism.
*/

#include <iostream>
#include <string>
#include <algorithm>

struct PrintChar
{
	void operator()(char ch)
	{
		std::cout << ch;
	}
};

template<typename Visitor>
void hello_world(Visitor & visitor)
{
	std::string hw("Hello world!\n");
	std::for_each(hw.begin(), hw.end(), visitor);
}

int main()
{
	PrintChar print_char;
	hello_world(print_char);
	return 0;
}
