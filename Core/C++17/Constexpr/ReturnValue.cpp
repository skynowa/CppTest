/**
 * \file  ReturnValue.cpp
 * \brief
 *
 * \see https://en.cppreference.com/w/cpp/language/constexpr
 *
 * - Т.е. constexpr - это не гарантия вычисления на этапе компиляции?
 *
 * Нет. Правильнее сказать, что оно может вычислиться на этапе компиляции, но не факт.
 * Как я и приводил пример в одном случае считалось на этапе компиляции, в другом - в рантайме.
 */


#include <StdStream/StdStream.h>
#include <StdTest/StdTest.h>
#include <Stl.h>
//--------------------------------------------------------------------------------------------------
constexpr std::size_t
// consteval std::size_t
factorial(const std::size_t n)
{
	if (n == 0) {
		return 1;
	}

	return ::factorial(n - 1) * n;
}
//--------------------------------------------------------------------------------------------------
int main(int, char **)
{
   /**
	* \note noexcept
	*
	* Because the noexcept operator always returns true for a constant expression,
	* it can be used to check if a particular invocation of a constexpr function
	* takes the constant expression branch:
	*/
	{
		constexpr bool bRv = noexcept( ::factorial(5) ); // true, f() is a constant expression
		// static_assert(bRv); - maybe fail

		std::cout << "noexcept: static_assert = " << bRv << std::endl;
	}

	// const
	{
		std::cout << "noexcept: " << noexcept( ::factorial(5) ) << std::endl;
	}

	// const
	{
		const std::size_t uiRv = ::factorial(5);
		static_assert(uiRv == 120);

		std::cout << STD_TRACE_VAR(uiRv) << std::endl;
	}

	// constexpr
	{
		constexpr std::size_t uiRv = ::factorial(5);
		static_assert(uiRv == 120);

		std::cout << STD_TRACE_VAR(uiRv) << std::endl;
	}

	return EXIT_SUCCESS;
}
//--------------------------------------------------------------------------------------------------


#if OUTPUT

noexcept: static_assert = 1
noexcept: 1
uiRv: 120
uiRv: 120

#endif
