/**
 * \file  main.cpp
 * \brief https://en.wikibooks.org/wiki/More_C%2B%2B_Idioms/Type_Safe_Enum
 */


#include <StdTest.h>
#include <Stl.h>

#if 0

//-------------------------------------------------------------------------------------------------
struct color_def
{
	static std::size_t _begin_;
	static std::size_t _end_;

	enum type { red, green, blue };
};
//-------------------------------------------------------------------------------------------------
template<typename def, typename inner = typename def::type>
class safe_enum :
	public def
{
public:
	static safe_enum *
	begin()
	{
		initialize();
		return array;
	}

	static safe_enum *
	end()
	{
		initialize();
		return array + (def::_end_ - def::_begin_);
	}

private:
	static std::size_t array[def::_end_ - def::_begin_];
	static bool init;

	// Works only if enumerations are contiguous.
	static void
	initialize()
	{
		// use double checked locking in case of multi-threading.
		if (init) {
			return;
		}

		unsigned int size = def::_end_ - def::_begin_;

		for (unsigned int i = 0, j = def::_begin_; i < size; ++ i, ++ j) {
			array[i] = static_cast<typename def::type>(j);
		}

		init = true;
	}
};

template<typename def, typename inner>
std::size_t safe_enum<def, inner>::array[def::_end_ - def::_begin_];

template <typename def, typename inner>
bool safe_enum<def, inner>::init = false;

//-------------------------------------------------------------------------------------------------
template<class Enum>
void f(Enum e)
{
	/// std::cout << e << std::endl;
}
#endif // 0

int main(int, char **)
{
	/// using color = safe_enum<color_def, unsigned char>;
	/// std::for_each(color::begin(), color::end(), &f<color>);

    return EXIT_SUCCESS;
}
//-------------------------------------------------------------------------------------------------

#if OUTPUT



#endif
