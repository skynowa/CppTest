/**
 * \file  main.cpp
 * \brief
 */


#include "../StdTest.h"

//-------------------------------------------------------------------------------------------------
template<class T>
void
print(const T &a_data, const std::string &a_title)
{
	std::cout
		<< a_title                    << "\n"
		<< STD_TRACE_VAR(a_data._int) << "\n"
		<< STD_TRACE_VAR(a_data._ptr) << "\n"
		<< "a_data._buff: "
			<< "{"
			<< a_data._buff[0] << ","
			<< a_data._buff[1] << ","
			<< a_data._buff[2] << ","
			<< a_data._buff[3]
			<< "}"             << "\n"
		<< "a_data._pBuff: "
			<< "{"
			<< a_data._pBuff[0] << ","
			<< a_data._pBuff[1] << ","
			<< a_data._pBuff[2] << ","
			<< a_data._pBuff[3]
			<< "}"              << "\n\n";
}

struct Data1
{
	signed int  _int;
	FILE       *_ptr;
	int         _buff[4];
	int        *_pBuff;

	Data1() :
		_pBuff(new int[4])
	{
	}
};

struct Data2
{
	signed int  _int {};
	FILE       *_ptr {};
	int         _buff[4] {};
	int        *_pBuff;

	Data2() :
		_pBuff(new int[4])
	{
	}
};

struct SubData3
{
	int i {};

	explicit SubData3(const int a_i) :
		i(a_i)
	{
		std::cout
			<< STD_TRACE_VAR(__FUNCTION__) << ", "<< STD_TRACE_VAR(i) << std::endl;
	}
};

struct Data3
{
	SubData3 subData3 {3};

	Data3() :
		subData3(5)
	{
	}
};
//-------------------------------------------------------------------------------------------------
int main(int argsNum, char **args)
{
	{
		Data1 data;
		print<Data1>(data, "()");
	}

	{
		Data1 data = {};
		print<Data1>(data, "= {}");
	}

	{
	#if 0
		// error: could not convert ‘{0}’ from ‘<brace-enclosed initializer list>’ to ‘Data1’

		Data1 data = {0};
		print<Data1>(data, "= {0}");
	#endif
	}

	{
		Data1 data {};
		print<Data1>(data, "{}");
	}

	{
	#if 0
		// error: no matching function for call to ‘Data1::Data1(<brace-enclosed initializer list>)’

		Data1 data {0};
		print<Data1>(data, "{0}");
	#endif
	}

#if 0
	// [Finished with exit code -11]

	{
		Data1 data; std::memset(&data, 0, sizeof(data));
		print<Data1>(data, "std::memset(0)");
	}

	{
		Data1 data; std::memset(&data, 1, sizeof(data));
		print<Data1>(data, "std::memset(1)");
	}
#endif

	{
		Data2 data;
		print<Data2>(data, "member {}");
	}

	{
		std::cout << "Twice construct" << std::endl;

		Data3 data;
	}

	return 0;
}
//-------------------------------------------------------------------------------------------------


#if OUTPUT

()
a_data._int: 2
a_data._ptr: 0x557d394d948d
a_data._buff: {0,0,0,0}
a_data._pBuff: {0,0,0,0}

= {}
a_data._int: 2
a_data._ptr: 0x557d394d948d
a_data._buff: {0,0,0,0}
a_data._pBuff: {0,0,0,0}

{}
a_data._int: 2
a_data._ptr: 0x557d394d948d
a_data._buff: {0,0,0,0}
a_data._pBuff: {0,0,0,0}

member {}
a_data._int: 0
a_data._ptr: 0
a_data._buff: {0,0,0,0}
a_data._pBuff: {0,0,0,0}

#endif
