/**
 * \file  Strptime.cpp
 * \brief
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
		char *pszRv = strptime("3 pm", it_dateFormat.c_str(), &dt);
		STD_TEST(pszRv == nullptr);

		std::cout
			<< it_dateFormat << " -> " << dt.tm_hour << ":" << dt.tm_min << std::endl;
	}

    return 0;
}
//-------------------------------------------------------------------------------------------------


#if OUTPUT

%I:%M %p -> 3:0
%I:%M    -> 3:0
%H:%M    -> 3:0
%H:%M:%S -> 3:0

#endif
