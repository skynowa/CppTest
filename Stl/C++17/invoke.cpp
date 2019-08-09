/**
 * \file  main.cpp
 * \brief std::invoke

 Invoke a Callable object with parameters. Examples of Callable objects are std::function or std::bind where an object can be called similarly to a regular function.
 */


#include <StdStream.h>
#include <StdTest.h>
#include <Stl.h>

//-------------------------------------------------------------------------------------------------
int main(int, char **)
{
	template <typename Callable>
	class Proxy {
		Callable c;
	public:
		Proxy(Callable c): c(c) {}
		template <class... Args>
		decltype(auto) operator()(Args&&... args) {
			// ...
			return std::invoke(c, std::forward<Args>(args)...);
		}
	};
	auto add = [](int x, int y) {
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
