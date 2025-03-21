/**
 * \file  NamedConstructor.cpp
 * \brief Public static methods that construct and return an object
 *
 * The problem is that constructors always have the same name as the class.
 * Therefore the only way to differentiate between the various constructors of a class
 * is by the parameter list. But if there are lots of constructors, the differences between
 * them become somewhat subtle and error prone.
 * With the Named Constructor Idiom, you declare all the class's constructors in the private or
 * protected sections, and you provide public static methods that return an object.
 * These static methods are the so-called "Named Constructors."
 * In general there is one such static method for each different way to construct an object.
 */


#include <StdStream/StdStream.h>
#include <StdTest/StdTest.h>
#include <Stl.h>
//--------------------------------------------------------------------------------------------------
class Game
{
public:
	// Named ctor
	static
	Game singlePlayer()
	{
		return Game("Single");
	}

	// Named ctor
	static
	Game multiPlayer()
	{
		return Game("Multi");
	}

	void print() const
	{
		std::cout << STD_TRACE_VAR(_type) << std::endl;
	}

protected:
	const std::string _type;

	explicit Game(const std::string &a_type) :
		_type{a_type}
	{
	}
};
//--------------------------------------------------------------------------------------------------
int main(int, char **)
{
	{
		Game single = Game::singlePlayer();
		single.print();
	}

	{
		Game milti = Game::multiPlayer();
		milti.print();
	}

	// multiplayer game; without named constructor (does not compile)
	{
	#if 0
		Game single = Game("Single");
		game.print();
	#endif
	}

	return EXIT_SUCCESS;
}
//--------------------------------------------------------------------------------------------------


#if OUTPUT

_type: Single
_type: Multi

#endif
