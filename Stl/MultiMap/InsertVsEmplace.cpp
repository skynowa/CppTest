/**
 * \file  InsertVsEmplace.cpp
 * \brief Inserts element(s) into the container
 *
 * Insert  - Inserts element(s) into the container, copies/ moves existing objects into the container
 * Emplace - Inserts a new element into the container constructed in-place with the given args
 */


#include <StdStream/StdStream.h>
#include <StdTest/StdTest.h>
#include <Idioms/RuleOf5.h>
//--------------------------------------------------------------------------------------------------
int main(int, char **)
{
	std::cout << "::::: Ctor :::::" << std::endl;

	RuleOf5 value;

	std::multimap<int, RuleOf5> mm;

	// pair's converting move ctor
	{
		std::cout << "\n::::: Insert :::::" << std::endl;
		mm.insert( {1, value} );
	}

	// pair's template ctor
	{
		std::cout << "\n::::: Emplace :::::" << std::endl;
		mm.emplace(2, value);
	}

	// pair's piecewise ctor
	{
		std::cout << "\n::::: std::piecewise_construct :::::" << std::endl;

		mm.emplace(std::piecewise_construct,
			std::forward_as_tuple(3),
			std::forward_as_tuple(value));
	}

	std::cout << "\n::::: Dtor :::::" << std::endl;

	return EXIT_SUCCESS;
}
//--------------------------------------------------------------------------------------------------


#if OUTPUT

::::: Ctor :::::
	::: RuleOf5 :::

::::: Insert :::::
	::: RuleOf5 :::
	::: RuleOf5 :::
	::: ~RuleOf5 :::

::::: Emplace :::::
	::: RuleOf5 :::

::::: std::piecewise_construct :::::
	::: RuleOf5 :::

::::: Dtor :::::
	::: ~RuleOf5 :::
	::: ~RuleOf5 :::
	::: ~RuleOf5 :::
	::: ~RuleOf5 :::

#endif
