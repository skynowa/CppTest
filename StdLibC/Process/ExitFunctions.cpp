/**
 * \file
 * \brief
 *
 * \todo
 */


#include <StdStream.h>
#include <StdTest.h>
#include <Stl.h>

//-------------------------------------------------------------------------------------------------
void onExit()
{
   STD_TRACE_FUNC;
}
//-------------------------------------------------------------------------------------------------
void onQuickExit()
{
   STD_TRACE_FUNC;
}
//-------------------------------------------------------------------------------------------------
int main(int, char **)
{
	constexpr int exitCode {10};

	std::atexit(onExit);
	std::at_quick_exit(onQuickExit);

	std::cout << "------------------------------" << std::endl;

	{
		std::cout << "::exit(exitCode)" << std::endl;
		std::exit(exitCode);
	}

	{
		std::cout << "std::_Exit(exitCode)" << std::endl;
		std::_Exit(exitCode);
	}

	{
		std::cout << "::_exit(exitCode)" << std::endl;
		::_exit(exitCode);
	}

	{
		std::cout << "std::quick_exit(exitCode)" << std::endl;
		std::quick_exit(exitCode);
	}

	{
		std::cout << "std::abort()" << std::endl;
		std::abort();
	}

	{
		std::cout << "std::terminate()" << std::endl;
		std::terminate();
	}

	STD_TRACE_FUNC;

    return EXIT_SUCCESS;
}
//-------------------------------------------------------------------------------------------------


#if OUTPUT

------------------------------
::exit(exitCode)
	::: onExit :::
------------------------------
::_Exit(exitCode)
------------------------------
::_exit(exitCode)
------------------------------
std::quick_exit(exitCode)
	::: onQuickExit :::
------------------------------
std::abort()
Aborted (core dumped)
------------------------------
std::terminate()
terminate called without an active exception
Aborted (core dumped)
------------------------------

#endif
