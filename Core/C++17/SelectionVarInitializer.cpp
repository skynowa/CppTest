/**
 * \file  main.cpp
 * \brief Selection statements with initializer
 *
 * \todo
 *
 * New versions of the if and switch statements which simplify common code patterns and help
 * users keep scopes tight.
 */


#include <StdStream.h>
#include <StdTest.h>
#include <Stl.h>

//-------------------------------------------------------------------------------------------------
class Gadget
{
public:
	int status()
	{
		return 0;
	}

	void zip()
	{
	}

	std::string message()
	{
		return "[msg]";
	}
};
//-------------------------------------------------------------------------------------------------
int main(int, char **)
{
	// if
	{
		std::mutex  mx;
		std::vector<int> v;
		const int   val {10};

		{
			std::lock_guard<std::mutex> lk(mx);
			if (v.empty()) v.push_back(val);
		}

		// vs.
		if (std::lock_guard<std::mutex> lk(mx); v.empty()) {
			v.push_back(val);
		}
	}

	// switch
	{
		Gadget gadget;


		switch (auto s = gadget.status()) {
		case 1:
			gadget.zip();
			break;
		case 0:
			std::cout << TRACE_VAR(s) << std::endl;
			break;
		}

		// vs.
		switch (Gadget gadget; auto s = gadget.status()) {
		case 1:
			gadget.zip();
			break;
		case 0:
			std::cout << TRACE_VAR(s) << std::endl;
			break;
		}
	}

    // std::cout << TRACE_VAR("") << std::endl;

    return EXIT_SUCCESS;
}
//-------------------------------------------------------------------------------------------------


#if OUTPUT



#endif
