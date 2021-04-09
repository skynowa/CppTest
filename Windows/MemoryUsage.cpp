/**
 * \file  MemoryUsage.cpp
 * \brief
 *
 * \todo
 */


#include <windows.h>
#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
HWND GetConsoleHwnd(void)
{
#define MY_BUFSIZE 1024
	HWND hwndFound;
	char pszNewWindowTitle[MY_BUFSIZE];
	char pszOldWindowTitle[MY_BUFSIZE];
	GetConsoleTitle(pszOldWindowTitle, MY_BUFSIZE);
	wsprintf(pszNewWindowTitle,"%d/%d",
		GetTickCount(),
		GetCurrentProcessId());
	SetConsoleTitle(pszNewWindowTitle);
	hwndFound=FindWindow(NULL, pszNewWindowTitle);
	SetConsoleTitle(pszOldWindowTitle);
	return(hwndFound);
}
int main(int, char **) {
	char src[80];
	char dest[80];
	int Div=1024;
	int old = 0;
	HWND Whwnd=GetConsoleHwnd();
	MEMORYSTATUS stat;
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	SetWindowPos(Whwnd ,HWND_TOPMOST,0,0,380,160, SWP_SHOWWINDOW );
	strcpy(src,"��������� ������");CharToOem(src,dest);
	SetConsoleTitle(dest);
	SetConsoleTextAttribute ( hStdout,  BACKGROUND_BLUE |7 );
	system("cls");
	GlobalMemoryStatus (&stat);
	strcpy(src,"���������� ������ ��������");CharToOem(src,dest);
	printf("%s\t%ld Kb\n",dest, stat.dwTotalPhys/Div);
	strcpy(src,"���������� ������ ��������");CharToOem(src,dest);
	printf("%s\t%ld Kb\n",dest, stat.dwAvailPhys/Div);
	strcpy(src,"���� �������� ��������");CharToOem(src,dest);
	printf("%s\t\t%ld Kb\n",dest, stat.dwTotalPageFile/Div);
	strcpy(src,"���� �������� ��������");CharToOem(src,dest);
	printf("%s\t\t%ld Kb\n",dest, stat.dwAvailPageFile/Div);
	strcpy(src,"����������� ������ ��������");CharToOem(src,dest);
	printf("%s\t%ld Kb\n",dest, stat.dwTotalVirtual/Div);
	strcpy(src,"����������� ������ ��������");CharToOem(src,dest);
	printf("%s\t%ld Kb\n\n",dest, stat.dwAvailVirtual/Div);
	printf ("%ld%%",stat.dwMemoryLoad);
	SetConsoleTextAttribute ( hStdout,  BACKGROUND_BLUE |14 );
	do
	{
		::Sleep(40);
		::GlobalMemoryStatus (&stat);
		strcpy(src,"������ ������������ ");CharToOem(src,dest);

		printf ("\r\t  %ld%% %s",stat.dwMemoryLoad,dest);
		if (stat.dwMemoryLoad == old) {

		} else {
			strcpy(src,"��������e���");CharToOem(src,dest);
			sprintf (src,"%ld%% %s",stat.dwMemoryLoad,dest);
			SetConsoleTitle(src);
		}
		old=stat.dwMemoryLoad;
	}
	while(true);

	system("pause");
	return 0;
}

//---------------------------------------------------------------------------