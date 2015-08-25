/*
State is like an enum, but we can define different behaviour for each state.
We could add another class,
Sad, which did something entirely different when asked to talk().
*/


#include <iostream>

//-------------------------------------------------------------------------------------------------
class IMood
{
public:
	virtual ~IMood() { }
	virtual void talk() = 0;
};
//-------------------------------------------------------------------------------------------------
class Happy : public IMood
{
public:
	void talk()
	{
		std::cout << "Happy mood!" << std::endl;
	}
};
//-------------------------------------------------------------------------------------------------
class Sad : public IMood
{
public:
	void talk()
	{
		std::cout << "Sad mood!" << std::endl;
	}
};
//-------------------------------------------------------------------------------------------------
int main()
{
	Happy happy_mood;
	happy_mood.talk();

	Sad sad_mood;
	sad_mood.talk();

	return 0;
}
//-------------------------------------------------------------------------------------------------
