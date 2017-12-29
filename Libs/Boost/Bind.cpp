/****************************************************************************
* Class name:  bind
* Description:
* File name:   bind.h
* Compilers:   Visual C++ 2010
* String type: Ansi, Unicode
* Libraries:   WinAPI, Stl, XLib
* Author:      Alca
* E-mail:      dr.web.agent@gmail.com
* Created:     01.12.2010 11:40:32
* Version:     1.0.0.0 Debug
*
*****************************************************************************/


#include <XLib/xCommon.h>
#include <boost/bind.hpp>
#include <boost/function.hpp>


//---------------------------------------------------------------------------
class CButton {
   public:
       boost::function<VOID()> vOnClick;
};
//---------------------------------------------------------------------------
class CPlayer {
   public:
       VOID vPlay() { xSTD_COUT_FUNC; };
       VOID vStop() { xSTD_COUT_FUNC; };
};
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
INT main(INT iArgc, TCHAR *pszArgv[]) {
	CButton playButton;
	CButton stopButton;
	CPlayer thePlayer;

	//connect
	playButton.vOnClick = boost::bind(&CPlayer::vPlay, &thePlayer);
	////stopButton.vOnClick = boost::bind(&CPlayer::vStop, &thePlayer);
	stopButton.vOnClick = boost::bind(&CPlayer::vPlay, &thePlayer);

	//click
	playButton.vOnClick();
	stopButton.vOnClick();

	xSTD_COUT(xT("\n"));
	system("pause");
	return 0;
}
//---------------------------------------------------------------------------
