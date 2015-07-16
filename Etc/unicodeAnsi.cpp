#include <winsock2.h>
#pragma comment(lib, "wsock32") 
#include <windows.h>
#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>

#include <XLib/Common.h>
//---------------------------------------------------------------------------
int main(int argc, char* argv[]) {
	//ANSI
	{
		std::string sBuff_A = "SomeText";

		std::cout << "sizeof_A: " << sizeof("SomeText") << std::endl; 
		std::cout << "size_A:   " << sBuff_A.size()      << std::endl; 
	}

	//Unicode
	{
		std::wstring sBuff_W = L"SomeText";

		std::cout << "sizeof_W: " << sizeof(L"SomeText") << std::endl; 
		std::cout << "size_W:   " << sBuff_W.size()      << std::endl; 
	}

	//TCHAR
	{
		tstring sBuff_T = _T("SomeText");

		std::cout << "sizeof_T: " << sizeof(_T("SomeText")) << std::endl; 
		std::cout << "size_T:   " << sBuff_T.size()      << std::endl; 
	}
	
	{
		tstring sStr = _T("Some string!!!");
		::send(0, reinterpret_cast<char const*>(sStr.data()), sStr.size() * sizeof(tstring::value_type), 0);
	}



	std::cout << std::endl << std::endl << std::endl; 
	std::cout << "sizeof_CHAR:         " << sizeof("SomeText")               << std::endl; 
	std::cout << "sizeof_WCHAR:        " << sizeof(L"SomeText")              << std::endl; 
	std::cout << "sizeof_std::string:  " << sizeof(std::string::value_type)  << std::endl; 
	std::cout << "sizeof_std::wstring: " << sizeof(std::wstring::value_type) << std::endl; 
	std::cout << "sizeof_char:         " << sizeof(char)                     << std::endl; 
	std::cout << "sizeof_wchar_t:      " << sizeof(wchar_t)						<< std::endl; 




	system("pause");
	return 0;
}
//---------------------------------------------------------------------------