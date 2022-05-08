/**
 * \file  main.cpp
 * \brief std::invoke
 *
 * \todo
 *
 * Invoke a Callable object with parameters. Examples of Callable objects are std::function or
 * std::bind where an object can be called similarly to a regular function.
 */


#include <StdStream/StdStream.h>
#include <StdTest/StdTest.h>
#include <Stl.h>

//-------------------------------------------------------------------------------------------------
template <typename Callable>
class Proxy
{
public:
	Proxy(Callable c): c(c)
	{
	}

	template <class... Args>
	decltype(auto) operator()(Args&&... args)
	{
		// ...
		return std::invoke(c, std::forward<Args>(args)...);
	}

private:
	Callable c;
};
//-------------------------------------------------------------------------------------------------
int main(int, char **)
{
	auto add = [](int x, int y)
	{
		return x + y;
	};

	Proxy<decltype(add)> p {add};
	p(1, 2); // == 3

    // std::cout << TRACE_VAR("") << std::endl;

    return EXIT_SUCCESS;
}
//-------------------------------------------------------------------------------------------------


#if OUTPUT



#endif
