/**
 * \file  FlyWeight.cpp
 * \brief Flyweight creates objects as they are needed
 *
 * Because keeping them around is unnecessary.
 * Here the Character class is a flyweight that is ONLY used for the duration of the inner loop
 */


#include <StdStream.h>
#include <StdTest.h>
#include <Stl.h>
//--------------------------------------------------------------------------------------------------
class Character
{
public:
	explicit Character(const char c) :
		_ch(c)
	{
	}

	void output() const
	{
		std::cout << _ch;
	}

private:
	const char _ch {};
};
//--------------------------------------------------------------------------------------------------
int main()
{
	const std::string msg = "Hello world!\n";

	std::for_each(msg.cbegin(), msg.cend(),
		[](const char a_ch) -> void
		{
			Character character(a_ch);
			character.output();
		});

	return 0;
}
//--------------------------------------------------------------------------------------------------

#if OUTPUT

Hello world!

#endif
