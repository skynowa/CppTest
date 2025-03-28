/**
 * \file  main.cpp
 * \brief Splicing for maps and sets
 *
 * \todo
 *
 * Moving nodes and merging containers without the overhead of expensive copies, moves, or heap
 * allocations/deallocations.
 */


#include <StdStream/StdStream.h>
#include <StdTest/StdTest.h>
#include <Stl.h>

//-------------------------------------------------------------------------------------------------
int main(int, char **)
{
	// Moving elements from one map to another:
	{
		std::map<int, std::string> src {{1, "one"}, {2, "two"}, {3, "buckle my shoe"}};
		std::map<int, std::string> dst {{3, "three"}};

		dst.insert(src.extract(src.find(1))); // Cheap remove and insert of { 1, "one" } from `src` to `dst`.
		dst.insert(src.extract(2)); 		  // Cheap remove and insert of { 2, "two" } from `src` to `dst`.
		// dst == { { 1, "one" }, { 2, "two" }, { 3, "three" } };
	}

	// Inserting an entire set:
	{
		std::set<int> src {1, 3, 5};
		std::set<int> dst {2, 4, 5};

		dst.merge(src);
		// src == { 5 }
		// dst == { 1, 2, 3, 4, 5 }
	}

	// Inserting elements which outlive the container:
	{
		auto elementFactory = []()
		{
			std::set<int> s;
			s.emplace(10);

			return s.extract(s.begin());
		};

		std::set<int> s2;
		s2.insert(elementFactory());
	}

	// Changing the key of a map element:
	{
		std::map<int, std::string> m {{1, "one"}, {2, "two"}, {3, "three"}};

		auto e = m.extract(2);
		e.key() = 4;
		m.insert(std::move(e));
		// m == { { 1, "one" }, { 3, "three" }, { 4, "two" } }
	}

    // std::cout << STD_TRACE_VAR("") << std::endl;

    return EXIT_SUCCESS;
}
//-------------------------------------------------------------------------------------------------


#if OUTPUT



#endif
