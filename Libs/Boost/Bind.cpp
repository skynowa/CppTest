/**
 * \file  Bind.cpp
 * \brief boost::bind
 */


#include <StdStream/StdStream.h>
#include <StdTest/StdTest.h>
#include <Stl.h>

#if BOOST_VERSION > 0

#include <boost/bind/bind.hpp>
#include <boost/function.hpp>
//-------------------------------------------------------------------------------------------------
class Button
{
public:
    boost::function<void()> onClick {};
};
//-------------------------------------------------------------------------------------------------
class Player
{
public:
	void play() { STD_TRACE_FUNC; };
	void stop() { STD_TRACE_FUNC; };
};

#endif
//-------------------------------------------------------------------------------------------------
int main(int , char **)
{
#if BOOST_VERSION > 0
	Player player;

	{
		Button btn;
		btn.onClick = boost::bind(&Player::play, &player);
		btn.onClick();
	}

	{
		Button btn;
		btn.onClick = boost::bind(&Player::stop, &player);
		btn.onClick();
	}
#else
	std::cout << "Boost - not instaled, skip" << std::endl;
#endif

    return EXIT_SUCCESS;
}
//-------------------------------------------------------------------------------------------------

#if OUTPUT

	::: play :::
	::: stop :::

#endif
