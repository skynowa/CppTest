/**
 * \file  MultimapCI.cpp
 * \brief
 */


#include <StdStream/StdStream.h>
#include <StdTest/StdTest.h>
#include <Stl.h>
//-------------------------------------------------------------------------------------------------
struct CmpCI
{
	bool operator() (
		const std::string &key1,
		const std::string &key2
	) const
	{
		return ::strcasecmp(key1.c_str(), key2.c_str()) > 0;
	}
};

using string_mmap_t = std::multimap<std::string, std::string, ::CmpCI>;
//-------------------------------------------------------------------------------------------------
int main()
{
	bool bRv {};

	const std::string targetC = "C";
	const std::string targetD = "D";

	const string_mmap_t values
	{
		{"a",     "0"},
		{"b",     "1"},
		{"c",     "2"},
		{targetC, "2"}
	};

	for (const auto &it : values) {
		std::cout << it.first << " :: " << it.second << std::endl;
	}

	std::cout << std::endl << std::endl;

	// Total Elements in the range 'c'
	{
		auto result = values.equal_range(targetC);

		int count = std::distance(result.first, result.second);
		std::cout << "Total values for key '" << targetC << "' are : " << count << std::endl;

		bRv = (values.find(targetC) != values.end());
		std::cout << TRACE_VAR2(targetC, bRv) << std::endl << std::endl;
	}

	// Total Elements in the range 'd'
	{
		auto result = values.equal_range(targetD);

		int count = std::distance(result.first, result.second);
		std::cout << "Total values for key '" << targetD << "' are : " << count << std::endl;

		bRv = (values.find(targetD) != values.end());
		std::cout << TRACE_VAR2(targetD, bRv) << std::endl << std::endl;
	}

	for (const auto &it : values) {
		std::cout << it.first << " :: " << it.second << std::endl;
	}

	return 0;
}
//-------------------------------------------------------------------------------------------------


#if OUTPUT

c :: 2
C :: 2
b :: 1
a :: 0
 ********************************************************
Total values for key 'C' are : 2
targetC: C, bRv: 1

Total values for key 'D' are : 0
targetD: D, bRv: 0

c :: 2
C :: 2
b :: 1
a :: 0

#endif
