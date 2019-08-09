/**
 * \file  main.cpp
 * \brief Selection statements with initializer
 *
 * New versions of the if and switch statements which simplify common code patterns and help
 * users keep scopes tight.
 */


#include <StdStream.h>
#include <StdTest.h>
#include <Stl.h>

//-------------------------------------------------------------------------------------------------
int main(int, char **)
{
	// if
	{
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
		Foo gadget(args);
		switch (auto s = gadget.status()) {
		case OK:
			gadget.zip();
			break;
		case Bad:
			throw BadFoo(s.message());
			break;
		}

		// vs.
		switch (Foo gadget(args); auto s = gadget.status()) {
		case OK:
			gadget.zip();
			break;
		case Bad:
			throw BadFoo(s.message());
			break;
		}
	}

    // std::cout << TRACE_VAR("") << std::endl;

    return EXIT_SUCCESS;
}
//-------------------------------------------------------------------------------------------------


#if OUTPUT



#endif
