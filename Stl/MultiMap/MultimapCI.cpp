/**
 * \file  MultimapCI.cpp
 * \brief
 */


#include <StdTest.h>
#include <Stl.h>

using namespace std;
//-------------------------------------------------------------------------------------------------
struct CmpCI
{
	bool operator()(const string& key1,const string& key2) const
	{
			return strcasecmp(key1.c_str(), key2.c_str()) > 0;
	}
};

using string_mmap_t = multimap<string, string, ::CmpCI>;
//-------------------------------------------------------------------------------------------------
int main()
{
	bool bRv {};

	const string targetC = "C";
	const string targetD = "D";

	string_mmap_t values
	{
		{"a",     "0"},
		{"b",     "1"},
		{"c",     "2"},
		{targetC, "2"}
	};

	for (auto &it : values) {
		cout << it.first << " :: " << it.second << endl;
	}

	cout << " ******************************************************** " << endl;

	// Total Elements in the range 'c'
	{
		auto result = values.equal_range(targetC);

		int count = std::distance(result.first, result.second);
		std::cout << "Total values for key '" << targetC << "' are : " << count << std::endl;

		bRv = (values.find(targetC) != values.end());
		cout << STD_TRACE_VAR2(targetC, bRv) << endl << endl;
	}

	// Total Elements in the range 'd'
	{
		auto result = values.equal_range(targetD);

		int count = std::distance(result.first, result.second);
		std::cout << "Total values for key '" << targetD << "' are : " << count << std::endl;

		bRv = (values.find(targetD) != values.end());
		cout << STD_TRACE_VAR2(targetD, bRv) << endl << endl;
	}

	for (auto &it : values) {
		cout << it.first << " :: " << it.second << endl;
	}

	return 0;
}
//-------------------------------------------------------------------------------------------------


#if OUTPUT



#endif
