/**
 * \file  BracedInitList.cpp
 * \brief New rules for auto deduction from braced-init-list
 *
 * Changes to auto deduction when used with the uniform initialization syntax.
 * Previously, auto x {3}; deduces a std::initializer_list<int>, which now deduces to int.
 */


#include <StdStream.h>
#include <StdTest.h>
#include <Stl.h>
//-------------------------------------------------------------------------------------------------
int main(int, char **)
{
	// error: not a single element
	{
		/// auto x1 {1, 2, 3};
	}

	// decltype(x2) is std::initializer_list<int>
	{
		auto x2 = {1, 2, 3};
		std::cout << TRACE_VAR(x2.size()) << std::endl;
	}

	// decltype(x3) is int
	{
		auto x3 {3};
		std::cout << TRACE_VAR(x3) << std::endl;
	}

	// decltype(x4) is double
	{
		auto x4 {3.0};
		std::cout << TRACE_VAR(x4) << std::endl;
	}

	{
		std::cout << std::endl;

		struct SourceInfoData
		{
			std::string filePath;
			std::size_t lineNum;
			std::string funcName;
			std::size_t counter;

			// expression
			std::string exprVar1;
			int         exprValue1 {-1};
			std::string exprVar2;
			int         exprValue2 {-2};
			std::string exprOp {"="};

			void print()
			{
				std::cout << TRACE_VAR4(filePath, lineNum, funcName, counter) << std::endl;
				std::cout << TRACE_VAR5(exprVar1, exprValue1, exprVar2, exprValue2, exprOp) << std::endl;
				std::cout << std::endl;
			}
		};

		{
			SourceInfoData data {"file1", 111, "func1", 111000};
			data.print();
		}

		{
			SourceInfoData data = {"file1", 111, "func1", 111000};
			data.print();
		}
	}

    return EXIT_SUCCESS;
}
//-------------------------------------------------------------------------------------------------


#if OUTPUT

x2.size(): 3
x3: 3
x4: 3

filePath: file1, lineNum: 111, funcName: func1, counter: 111000
exprVar1: , exprValue1: -1, exprVar2: , exprValue2: -2, exprOp: =

filePath: file1, lineNum: 111, funcName: func1, counter: 111000
exprVar1: , exprValue1: -1, exprVar2: , exprValue2: -2, exprOp: =


#endif
