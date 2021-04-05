/**
 * \file  bind.cpp
 * \brief Boost.Bind
 *
 * \todo
 */


#include <StdStream.h>
#include <StdTest.h>
#include <Stl.h>

#include <boost/bind.hpp>
#include <boost/function.hpp>

//-------------------------------------------------------------------------------------------------
class CButton
{
public:
    boost::function<void()> vOnClick {};
};
//-------------------------------------------------------------------------------------------------
class CPlayer
{
public:
	void vPlay() { STD_TRACE_FUNC; };
	void vStop() { STD_TRACE_FUNC; };
};
//-------------------------------------------------------------------------------------------------
int main(int , char **)
{
	CButton playButton;
	CButton stopButton;
	CPlayer thePlayer;

	// connect
	playButton.vOnClick = boost::bind(&CPlayer::vPlay, &thePlayer);
	/// stopButton.vOnClick = boost::bind(&CPlayer::vStop, &thePlayer);
	stopButton.vOnClick = boost::bind(&CPlayer::vPlay, &thePlayer);

	// click
	playButton.vOnClick();
	stopButton.vOnClick();

	return 0;
}
//-------------------------------------------------------------------------------------------------
