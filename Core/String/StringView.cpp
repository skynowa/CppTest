/**
 * \file  StringView.cpp
 * \brief StringView + Enum
 */


#include <StdStream/StdStream.h>
#include <StdTest/StdTest.h>
#include <Stl.h>
//-------------------------------------------------------------------------------------------------
class StringView
{
public:
	using const_iterator = const char *;

	template<std::size_t N>
	constexpr
	StringView(const char(&a)[N]) noexcept :
		_ptr {a},
		_size{N - 1}
	{}

	constexpr
	StringView(const char *p, const std::size_t N) noexcept :
		_ptr {p},
		_size{N}
	{}

	constexpr const char *
	data() const noexcept
	{
		return _ptr;
	}

	constexpr std::size_t
	size() const noexcept
	{
		return _size;
	}

	constexpr const_iterator
	begin() const noexcept
	{
		return _ptr;
	}

	constexpr const_iterator
	end() const noexcept
	{
		return _ptr + _size;
	}

	constexpr char
	operator[](const std::size_t n) const
	{
		return (n < _size) ? _ptr[n] : throw std::out_of_range("StringView");
	}

private:
	const char * const _ptr {};
	const std::size_t  _size {};
};
//-------------------------------------------------------------------------------------------------
inline std::ostream &
operator << (std::ostream& os, const StringView &s)
{
	return os.write(s.data(), s.size());
}
//-------------------------------------------------------------------------------------------------
/// \brief Get the name of a type
template <class T>
StringView typeName()
{
#if defined(__GNUC__) || defined(__clang__)
	// StringView typeName() [with T = main(int, char**)::Color]
	StringView p = __PRETTY_FUNCTION__;

	return StringView(p.data() + 51, p.size() - 51 - 1);
#elif defined(_MSC_VER)
	StringView p = __FUNCSIG__;

	return StringView(p.data() + 37, p.size() - 37 - 7);
#endif
}
//-------------------------------------------------------------------------------------------------
namespace details
{

template <class Enum>
struct EnumWrapper
{
	template <Enum enumT>
	static StringView name()
	{
	#if defined(__GNUC__)
		// static StringView details::EnumWrapper<Enum>::name() [with Enum enumT = (Color)2; Enum = Color]

		StringView p        = __PRETTY_FUNCTION__;
		StringView enumType = typeName<Enum>();

		// std::cout << STD_TRACE_VAR(p) << std::endl;

		return StringView(p.data() + 86 + enumType.size(), p.size() - 86 - enumType.size() - 1 - 14);
	#elif defined(__clang__)
		// static static_string details::EnumWrapper<Color>::name() [Enum = Color, enu = Color::Blue]

		StringView p        = __PRETTY_FUNCTION__;
		StringView enumType = typeName<Enum>();

		return StringView(p.data() + 73 + enumType.size(), p.size() - 73 - enumType.size() - 1);
	#elif defined(_MSC_VER)
		StringView p        = __FUNCSIG__;
		StringView enumType = typeName<Enum>();

		return StringView(p.data() + 57 + enumType.size(), p.size() - 57 - enumType.size() - 7);
	#endif
	}
};

} // details
//-------------------------------------------------------------------------------------------------
/// \brief Get the name of an enum value
template <typename Enum, Enum enumT>
StringView enumName()
{
	return details::EnumWrapper<Enum>::template name<enumT>();
}
//-------------------------------------------------------------------------------------------------
enum class Color : short
{
	Blue   = 0,
	Yellow = 1,
	Red    = 2
};
//--------------------------------------------------------------------------------------------------
int main(int, char **)
{
	/// std::cout << ">" << ::typeName<Color>() << "<"  << std::endl;
	std::cout << ">" << ::enumName<Color, Color::Red>() << "<"  << std::endl;

    return EXIT_SUCCESS;
}
//--------------------------------------------------------------------------------------------------


#if OUTPUT

>(Color)2<

#endif
