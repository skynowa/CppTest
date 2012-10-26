/*
Null object creates a special object to mean nothing/null/absent/default.  
It means that the default behaviour can be implementer in the null object 
instead of making an explicit check for null, or using NULL pointers.
*/


#include <iostream>
#include <string>

class Recipient
{
public:
	virtual ~Recipient() { }
	virtual std::string name() const=0;
};

class NullRecipient : public Recipient
{
public:
	std::string name() const { return "nobody"; }
};

class World : public Recipient
{
public:
	std::string name() const { return "world"; }
};

void hello_world(const Recipient & recipient = NullRecipient())
{
	std::cout << "Hello " << recipient.name() << "!" << std::endl;
}

int main()
{
	hello_world(World());
	return 0;
}

