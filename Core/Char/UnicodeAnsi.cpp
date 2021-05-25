/**
 * \file  UnicodeAnsi.cpp
 * \brief
 */


#include <StdStream.h>
#include <StdTest.h>
#include <Stl.h>
//--------------------------------------------------------------------------------------------------
int main(int, char **) {
	// ANSI
	{
		std::string buff_A = "SomeText";

		std::cout << "sizeof_A: " << sizeof("SomeText") << std::endl;
		std::cout << "size_A:   " << buff_A.size()      << std::endl << std::endl;
	}

	// Unicode
	{
		std::wstring buff_W = L"SomeText";

		std::cout << "sizeof_W: " << sizeof(L"SomeText") << std::endl;
		std::cout << "size_W:   " << buff_W.size()      << std::endl << std::endl;
	}

	// TCHAR
	{
		std::wstring buff_T = L"SomeText";

		std::cout << "sizeof_T: " << sizeof(L"SomeText") << std::endl;
		std::cout << "size_T:   " << buff_T.size()      << std::endl << std::endl;
	}

	{
		std::wstring str = L"Some string!!!";
		/// ::send(0, reinterpret_cast<char const*>(str.data()), str.size() * sizeof(std::wstring::value_type), 0);
	}

	std::cout << std::endl << std::endl;
	std::cout << "sizeof_CHAR:         " << sizeof("SomeText")               << std::endl;
	std::cout << "sizeof_WCHAR:        " << sizeof(L"SomeText")              << std::endl;
	std::cout << "sizeof_std::string:  " << sizeof(std::string::value_type)  << std::endl;
	std::cout << "sizeof_std::wstring: " << sizeof(std::wstring::value_type) << std::endl;
	std::cout << "sizeof_char:         " << sizeof(char)                     << std::endl;
	std::cout << "sizeof_wchar_t:      " << sizeof(wchar_t)                  << std::endl;

	return EXIT_SUCCESS;
}
//---------------------------------------------------------------------------

#if OUTPUT

sizeof_A: 9
size_A:   8
sizeof_W: 36
size_W:   8
sizeof_T: 36
size_T:   8


sizeof_CHAR:         9
sizeof_WCHAR:        36
sizeof_std::string:  1
sizeof_std::wstring: 4
sizeof_char:         1
sizeof_wchar_t:      4


#endif