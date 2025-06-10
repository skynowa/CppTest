/**
 * \file  RefVsMove.cpp
 * \brief Overload functions - by referencre (value) / by std::move
 */


#include <StdStream/StdStream.h>
#include <StdTest/StdTest.h>
#include <Stl.h>
//--------------------------------------------------------------------------------------------------
#if 1

void
increment(
	const std::string                                                &a_key,
	std::initializer_list<std::pair<const std::string, std::string>>  a_tags
)
{
	STD_UNUSED(a_key);
	STD_UNUSED(a_tags);

	STD_TRACE_FUNC_PRETTY;
}

#endif
//--------------------------------------------------------------------------------------------------
void
increment(
	const std::string                        &a_key,
	const std::map<std::string, std::string> &a_tags
)
{
	STD_UNUSED(a_key);
	STD_UNUSED(a_tags);

	STD_TRACE_FUNC_PRETTY;
}
//--------------------------------------------------------------------------------------------------
void
increment(
	const std::string                   &a_key,
	std::map<std::string, std::string> &&a_tags
)
{
	STD_UNUSED(a_key);
	STD_UNUSED(a_tags);

	STD_TRACE_FUNC_PRETTY;
}
//--------------------------------------------------------------------------------------------------
int main(int, char **)
{
	const std::string key {"key_test"};

	// By (const) ref (value)
	{
		const std::map<std::string, std::string> tags
		{
			{"variant",    "var"},
			{"avail_type", "3"},
			{"avail",      "aaa"}
		};

		::increment(key, tags);
	}

	// By (const) ref (value)
	{
		const std::map<std::string, std::string> tags
		{
			{"variant",    "var"},
			{"avail_type", "3"},
			{"avail",      "aaa"}
		};

		::increment(key, std::move(tags));
	}

	// By std::move
	{
		std::map<std::string, std::string> tags
		{
			{"variant",    "var"},
			{"avail_type", "3"},
			{"avail",      "aaa"}
		};

		::increment(key, std::move(tags));
	}

	// By std::move (if no std::initializer_list overload)
	{
		::increment(key, {
			{"variant",    "var"},
			{"avail_type", "3"},
			{"avail",      "aaa"}
		});
	}

    return EXIT_SUCCESS;
}
//--------------------------------------------------------------------------------------------------


#if OUTPUT

::: void increment(const string&, const std::map<std::__cxx11::basic_string<char>, std::__cxx11::basic_string<char> >&) :::
::: void increment(const string&, const std::map<std::__cxx11::basic_string<char>, std::__cxx11::basic_string<char> >&) :::
::: void increment(const string&, std::map<std::__cxx11::basic_string<char>, std::__cxx11::basic_string<char> >&&) :::
::: void increment(const string&, std::initializer_list<std::pair<const std::__cxx11::basic_string<char>, std::__cxx11::basic_string<char> > >) :::

#endif
