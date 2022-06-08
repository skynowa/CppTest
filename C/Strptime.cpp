/**
 * \file  Strptime.cpp
 * \brief Convert (parse) a string representation of time to a time tm structure
 */


#include <StdStream/StdStream.h>
#include <StdTest/StdTest.h>
//-------------------------------------------------------------------------------------------------
int main(int, char **)
{
	const std::string dateFormats[]
	{
		"%I:%M %p",
		"%I:%M",
		"%H:%M",
		"%H:%M:%S"
	};

	for (const auto &it_dateFormat : dateFormats) {
		struct tm dt {};
		char *pszRv = strptime("3:15 PM", it_dateFormat.c_str(), &dt);
		// STD_TEST(pszRv == nullptr);

		std::cout
			<< "rv: " << (pszRv == nullptr) << ", "
			<< it_dateFormat << " -> " << dt.tm_hour << ":" << dt.tm_min << std::endl;
	}

    return 0;
}
//-------------------------------------------------------------------------------------------------


#if OUTPUT

rv: 0, %I:%M %p -> 15:15
rv: 0, %I:%M    -> 3:15
rv: 0, %H:%M    -> 3:15
rv: 1, %H:%M:%S -> 3:15

#endif
