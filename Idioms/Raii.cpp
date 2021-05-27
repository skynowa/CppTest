/**
 * \file  Raii.cpp
 * \brief RAII - Resource Acquisition Is Initialization
 *
 * To guarantee release of resource(s) at the end of a scope
 * To provide basic exception safety guarantee
 */


#include <StdStream.h>
#include <StdTest.h>
#include <Stl.h>
//--------------------------------------------------------------------------------------------------
template<class T>
class AutoDelete
{
public:
	AutoDelete (const AutoDelete &) = delete;
	AutoDelete & operator = (const AutoDelete &) = delete;

	explicit AutoDelete(T *p) :
		_ptr(p)
	{
		STD_TRACE_FUNC;
	}

	~AutoDelete() throw()
	{
		STD_TRACE_FUNC;

		delete _ptr;
	}

private:
	T *_ptr {};
};
//--------------------------------------------------------------------------------------------------
int main(int, char **)
{
	int *p = new int;

	// Memory will not leak
	AutoDelete<int> auto_x(p);

	// Although, above assignment "p = 0" is not necessary
	// as we would not have a dangling pointer in this example.
	// It is a good programming practice.
	p = nullptr;

	if (true) {
		if (true) {
			return EXIT_SUCCESS;
		}
	}

	// No need to call delete here.
	// Destructor of safe_del will delete memory

    return EXIT_SUCCESS;
}
//--------------------------------------------------------------------------------------------------


#if OUTPUT

	::: AutoDelete :::
	::: ~AutoDelete :::

#endif
