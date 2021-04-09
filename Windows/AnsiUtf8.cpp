/**
 * \file  AnsiUtf8.cpp
 * \brief
 */


//---------------------------------------------------------------------------
#include <windows.h>
#include <tchar.h>
#include <iostream>
#include <string>
//---------------------------------------------------------------------------
std::wstring
strtows(const std::string &str, UINT codePage)
{
	std::wstring ws;
	int n = MultiByteToWideChar(codePage, 0, str.c_str(), str.size()+1, /*dst*/NULL, 0);
	if (n) {
		ws.resize(n-1);
		ws[0] = L'\0';
		MultiByteToWideChar(codePage, 0, str.c_str(), str.size()+1, /*dst*/&ws[0], n);
	}

	return ws;
}
//---------------------------------------------------------------------------
std::string
wstostr(const std::wstring &ws, UINT codePage)
{
	std::string str;
	int n = WideCharToMultiByte(codePage, 0, ws.c_str(), ws.size()+1, /*dst*/NULL, 0, /*defchr*/0, NULL);
	if (n) {
		str.resize(n-1);
		str[0] = '\0';
		WideCharToMultiByte(codePage, 0, ws.c_str(), ws.size()+1, /*dst*/&str[0], n, /*defchr*/0, NULL);
	}

	return str;
}
//---------------------------------------------------------------------------
std::string
chcp(const std::string &str, UINT codePageSrc, UINT codePageDst)
{
	return wstostr(strtows(str, codePageSrc), codePageDst);
}
//---------------------------------------------------------------------------
int main(int, char **)
{
	std::string strAcpSrc = "ANSI ������";
	std::string strUtf = chcp(strAcpSrc, CP_ACP, CP_UTF8);
	std::string strAcp = chcp(strUtf, CP_UTF8, CP_ACP);

	if (strAcpSrc == strAcp) {
		std::cout << "success";
	} else {
		std::cout << "error";
	}

	return 0;
}
//---------------------------------------------------------------------------