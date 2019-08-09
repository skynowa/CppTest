/**
 * \file  main.cpp
 * \brief constexpr lambda
 *
 * Compile-time lambdas using constexpr.
 */


#include <StdStream.h>
#include <StdTest.h>
#include <Stl.h>

//-------------------------------------------------------------------------------------------------
int main(int, char **)
{
	{
		auto identity = [](int n) constexpr
		{
			return n;
		};

		static_assert(identity(123) == 123);
	}

	{
		constexpr auto add = [](int x, int y)
		{
			auto L = [=] { return x; };
			auto R = [=] { return y; };

			return [=] { return L() + R(); };
		};

		static_assert(add(1, 2)() == 3);
	}

	{
		struct S
		{
			constexpr int addOne(int n)
			{
				return [n] { return n + 1; }();
			};
		};

		static_assert(S().addOne(1) == 2);
	}

    // std::cout << TRACE_VAR("") << std::endl;

    return EXIT_SUCCESS;
}
//-------------------------------------------------------------------------------------------------


#if OUTPUT



#endif
