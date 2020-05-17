/**
 * \file  main.cpp
 * \brief
 */


#include <StdStream.h>
#include <StdTest.h>
#include <any>

//-------------------------------------------------------------------------------------------------
void
format()
{
	std::cout << "[format0]: " << "[n/a]" << std::endl;
}
//-------------------------------------------------------------------------------------------------
void
format(int i)
{
	std::cout << "[format1]: " << TRACE_VAR(i) << std::endl;
}
//-------------------------------------------------------------------------------------------------
void
format(int i, const char *c)
{
	std::cout << "[format2]: " << TRACE_VAR2(i, c) << std::endl;
}
//-------------------------------------------------------------------------------------------------
void
format(int i, double d, char ch)
{
	std::cout << "[format3]: " << TRACE_VAR3(i, d, ch) << std::endl;
}
//-------------------------------------------------------------------------------------------------


//-------------------------------------------------------------------------------------------------
template<typename ...ArgsT>
void
formatStr14(const char *fmt, const ArgsT &...args)
{
	constexpr std::size_t argsSize = sizeof...(ArgsT);

	std::cout << __FUNCTION__ << ": " << TRACE_VAR2(fmt, argsSize) << ": ";

	// Unpack the arguments for further treatment
    format(args...);
}
//-------------------------------------------------------------------------------------------------
template<typename ...ArgsT>
void
formatStr17(const char *fmt, const ArgsT &...args)
{
	(void)fmt;

#if 0
	std::stringstream ss;
    ((ss << args << ", "), ...);

	std::cout << __FUNCTION__ << ": "  << fmt << ", " << ss.str();
#elif 0
	(std::cout << fmt << ", " << ... << args) << std::endl;
#else
	const std::vector<std::any> &a = {args ...};

	for (const auto &it : a) {
		if ( !it.has_value() ) {
			std::cout << "no value\n";
			continue;
		}

		try {
			if (it.type() == typeid(std::string)) std::cout << std::any_cast<std::string>(it);
			if (it.type() == typeid(int))         std::cout << std::any_cast<int>(it);
			if (it.type() == typeid(double))      std::cout << std::any_cast<double>(it);
			if (it.type() == typeid(char))        std::cout << std::any_cast<char>(it);
		}
		catch (const std::bad_any_cast& e) {
			std::cout << "what: " << e.what() << '\n';
		}

		std::cout << ", ";
	}
#endif

	std::cout << std::endl;
}
//-------------------------------------------------------------------------------------------------
template <class T, class ...ArgsT>
void
formatStr17_v2(
	const char  *fmt,
	const T     &arg1,
	const ArgsT &...args
)
{
    std::cout << fmt << ": " << arg1 << ", ";

    if constexpr (sizeof...(args) > 0) {
        // this line will only be instantiated if there are further
        // arguments. if args... is empty, there will be no call to print_all(os)
        formatStr17_v2(fmt, args...);
    } else {
		std::cout << "*" << std::endl;
	}
}
//-------------------------------------------------------------------------------------------------
std::string _specifier()
{
	return "{}";
}
//-------------------------------------------------------------------------------------------------
template<typename... T>
std::string
formatStr17_v3(
	const std::string &fmt,
	T                 &&...args
)
{
	std::string sRv;

	auto func = [] (
		const std::string &fmt,
		const size_t       index,
		auto               arg,
		std::size_t       &posPrev,	///< [out]
		std::string       *out_rv
	) -> void
	{
		(void)index;

		const std::size_t pos = fmt.find(_specifier(), posPrev);
		if (pos == std::string::npos) {
			return;
		}

		*out_rv += fmt.substr(posPrev, pos - posPrev);

		static std::stringstream ss;
		{
			static const std::string emptyString;
			ss.str( emptyString );
			ss.clear();

			ss << arg;
		}

		*out_rv += ss.str();

		posPrev = pos + _specifier().size();

		// std::cout << TRACE_VAR4(fmt, index, posPrev, arg) << "\n";
	};

	std::size_t index   {};
	std::size_t posPrev {};

    ( func(fmt, index ++, std::forward<T>(args), posPrev, &sRv), ...);

	return sRv;
}
//-------------------------------------------------------------------------------------------------
int main(int, char **)
{
#if 0
	formatStr14("fmt0");
	formatStr14("fmt1", 100);
	formatStr14("fmt2", 200, "bbb");
	formatStr14("fmt3", 300, 400.25, 'a');
#else
	// formatStr17("fmt0");
	// formatStr17("fmt1", 100);
	// formatStr17("fmt2", 200, "bbb");
	// formatStr17("fmt3", 300, 400.25, 'a');

	// formatStr17_v2("fmt0");
	// formatStr17_v2("fmt1", 100);
	// formatStr17_v2("fmt2", 200, "bbb");

	// formatStr17_v2("fmt3", 300, 400.25, 'a');

	std::string sRv = formatStr17_v3("_{}_{}_{}_{}_{}_", "str", 4, 5, 6, "a");
	STD_TEST(sRv == "_str_4_5_6_a");
#endif

    return 0;
}
//-------------------------------------------------------------------------------------------------


#if OUTPUT

formatStr14: fmt: fmt0, argsSize: 0: [format0]: [n/a]
formatStr14: fmt: fmt1, argsSize: 1: [format1]: i: 100
formatStr14: fmt: fmt2, argsSize: 2: [format2]: i: 200, c: bbb
formatStr14: fmt: fmt3, argsSize: 3: [format3]: i: 300, d: 300, ch: a

formatStr17:
formatStr17: fmt1, 100,
formatStr17: fmt2, 200, fmt2, bbb,
formatStr17: fmt3, 300, fmt3, 300, fmt3, a,

fmt3: 300, fmt3: 400.25, fmt3: a, *

#endif
