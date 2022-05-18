/**
 * \file  FoldExpressions.cpp
 * \brief Fold expressions
 *
 * \todo
 *
 * A fold expression performs a fold of a template parameter pack over a binary operator.
 *
 * - An expression of the form (... op e) or (e op ...), where op is a fold-operator and e is an
 *   unexpanded parameter pack, are called unary folds.
 * - An expression of the form (e1 op ... op e2), where op are fold-operators,
 *   is called a binary fold. Either e1 or e2 is an unexpanded parameter pack, but not both.
 */


#include <StdStream/StdStream.h>
#include <StdTest/StdTest.h>
#include <Stl.h>

//-------------------------------------------------------------------------------------------------
template<typename... ArgsT>
bool
logicalAnd(ArgsT... args)
{
	// Binary folding
	return (true && ... && args);
}
//-------------------------------------------------------------------------------------------------
template<typename... ArgsT>
auto
sum(ArgsT... args)
{
	// Unary folding
	return (args + ... + 100.1);
}
//-------------------------------------------------------------------------------------------------
int main(int, char **)
{
	{
		bool  b  {true};
		bool &b2 {b};

		auto aRv = logicalAnd(b, b2, true); // == true
		std::cout << STD_TRACE_VAR(aRv) << std::endl;
	}

	{
		auto aRv = sum(1.0, 2.0f, 3); // == 6.0
		std::cout << STD_TRACE_VAR(aRv) << std::endl;
	}

    return EXIT_SUCCESS;
}
//-------------------------------------------------------------------------------------------------


#if OUTPUT

aRv: 1     (true)
aRv: 106.1 (6+100.1)

#endif
