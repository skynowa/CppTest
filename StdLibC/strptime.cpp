/**
 * \file  strptime.cpp
 * \brief
 */


#include "../StdTest.h"

//-------------------------------------------------------------------------------------------------
int main(int argsNum, char **args)
{
	const std::string dateFormats[]
	{
		"%I:%M %p",
		"%I:%M",
		"%H:%M",
		"%H:%M:%S"
	};

	for (auto &itDateFormat : dateFormats) {
		struct tm dt;
		char *pszRv = strptime("3 pm", itDateFormat.c_str(), &dt);
		if (pszRv == nullptr) {
			std::cout << "pszRv: nullptr" << std::endl;
			continue;
		}

		std::cout
			<< itDateFormat << " -> " << dt.tm_hour << ":" << dt.tm_min << "\n"
			<< (bool)(pszRv)        << "\n"
			<< STD_TRACE_PTR(pszRv) << "\n" << std::endl;
	}

    return 0;
}
//-------------------------------------------------------------------------------------------------


#if OUTPUT

%I:%M %p -> 15:13
1
pszRv: {, 0}

%I:%M -> 3:13
1
pszRv: { pm, 32}

%H:%M -> 3:13
1
pszRv: { pm, 32}

%H:%M:%S -> 3:13
0
pszRv: {[Finished in 0.5s]

#endif
