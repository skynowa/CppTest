/*
Visitor provides a call-back for every item in a collection.  
This allows the implementation of the collection to hidden.

visitor1.cpp is the simplest type of visitor using templates.  
The std::for_each template function that takes any kind of type.  
visitor2.cpp uses the more traditional inheritance-based polymorphism.
*/

#include <vector>
#include <string>
#include <iostream>

class Visitor
{
public:
	virtual ~Visitor() { }
	virtual void on_recipient(const std::string &)=0;
};

class Recipients
{
	std::vector<std::string> recipients;
public:
	void add_recipient(const std::string & recipient)
	{
		recipients.push_back(recipient);
	}
	void visit(Visitor & visitor) const
	{
		for(std::vector<std::string>::const_iterator recipient = recipients.begin();
			recipient != recipients.end(); 
			++recipient)
		{
			visitor.on_recipient(*recipient);
		}
	}
};

class PrintHello : public Visitor
{
public:
	void on_recipient(const std::string & recipient)
	{
		std::cout << "Hello " << recipient << "!" << std::endl;
	}
};

void hello_world(Visitor & visitor)
{
	Recipients recipients;
	recipients.add_recipient("world");
	recipients.visit(visitor);
}

int main()
{
	PrintHello visitor;
	hello_world(visitor);
	return 0;
}
