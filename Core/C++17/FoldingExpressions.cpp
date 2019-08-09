/**
 * \file  main.cpp
 * \brief Folding expressions

 * A fold expression performs a fold of a template parameter pack over a binary operator.
 *
 * - An expression of the form (... op e) or (e op ...), where op is a fold-operator and e is an
 *   unexpanded parameter pack, are called unary folds.
 * - An expression of the form (e1 op ... op e2), where op are fold-operators,
 *   is called a binary fold. Either e1 or e2 is an unexpanded parameter pack, but not both.
 */


#include <StdStream.h>
#include <StdTest.h>
#include <Stl.h>

//-------------------------------------------------------------------------------------------------
template<typename... Args>
bool logicalAnd(Args... args)
{
	// Binary folding.
	return (true && ... && args);
}
//-------------------------------------------------------------------------------------------------
template<typename... Args>
auto sum(Args... args)
{
	// Unary folding.
	return (... + args);
}
//-------------------------------------------------------------------------------------------------
int main(int, char **)
{
	{
		bool  b  = true;
		bool& b2 = b;

		logicalAnd(b, b2, true); // == true
	}

	{
		sum(1.0, 2.0f, 3); // == 6.0
	}

    // std::cout << TRACE_VAR("") << std::endl;

    return EXIT_SUCCESS;
}
//-------------------------------------------------------------------------------------------------


#if OUTPUT



#endif
