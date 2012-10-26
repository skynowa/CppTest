/*
State is like an enum, but we can define different behaviour for each state. 
We could add another class, 
Sad, which did something entirely different when asked to talk().
*/

#include <iostream>

class Mood
{
public:
	virtual ~Mood() { }
	virtual void talk()=0;
};

class Happy : public Mood
{
public:
	void talk() { std::cout << "Hello world!" << std::endl; }
};

void hello_world(Mood & mood)
{
	mood.talk();
}

int main()
{
	Happy mood;
	hello_world(mood);
	return 0;
}

