/**
 * \file  SelectionVarInitializer.cpp
 * \brief Selection statements with initializer
 *
 * New versions of the if and switch statements which simplify common code patterns and help
 * users keep scopes tight.
 */


#include <StdStream/StdStream.h>
#include <StdTest/StdTest.h>
#include <Stl.h>
//-------------------------------------------------------------------------------------------------
class Gadget
{
public:
	int status() const
	{
		return 0;
	}

	void zip() const
	{
		STD_TRACE_FUNC;
	}

	std::string message() const
	{
		return "[msg]";
	}
};
//-------------------------------------------------------------------------------------------------
int main(int, char **)
{
	// if
	{
		std::mutex       mx;
		std::vector<int> v;
		const int        val {10};

		{
			std::lock_guard<std::mutex> lk(mx);

			if (v.empty()) {
				v.push_back(val);
			}
		}

		// vs.
		if (std::lock_guard<std::mutex> lk(mx); v.empty()) {
			v.push_back(val);
		}
	}

	// switch
	{
		Gadget gadget;

		switch (const auto s = gadget.status()) {
		case 1:
			gadget.zip();
			break;
		case 0:
			std::cout << STD_TRACE_VAR(s) << std::endl;
			break;
		}

		// vs.
		switch (const Gadget gadget; const auto s = gadget.status()) {
		case 1:
			gadget.zip();
			break;
		case 0:
			std::cout << STD_TRACE_VAR(s) << std::endl;
			break;
		}
	}

    return EXIT_SUCCESS;
}
//-------------------------------------------------------------------------------------------------


#if OUTPUT

s: 0
s: 0

#endif
