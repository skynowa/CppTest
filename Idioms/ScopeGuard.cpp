/**
 * \file  ScopeGuard.cpp
 * \brief To ensure that resources are always released in face of an exception but not while returning normally
 *        To provide basic exception safety guarantee
 *
 * Resource Acquisition is Initialization (RAII) idiom allows us to acquire resources
 * in the constructor and release them in the destructor when scope ends successfully or
 * due to an exception. It will always release resources. This is not very flexible.
 * Sometime we don't want to release resources if no exception is thrown but we do want to release
 * them if an exception is thrown.
 */


#include <StdStream.h>
#include <StdTest.h>
#include <Stl.h>
//--------------------------------------------------------------------------------------------------
class ScopeGuard
{
public:
	ScopeGuard () :
		engaged_(true)
	{
		// Acquire resources here
	}

	~ScopeGuard ()
	{
		if (engaged_) {
			// Release resources here
		}
	}

	void release ()
	{
		engaged_ = false;
		// Resources will no longer be released
	}

private:
	bool engaged_ {};
};
//--------------------------------------------------------------------------------------------------
int main(int, char **)
{
	ScopeGuard guard;

	// ...... Something may throw here. If it does we release resources.

	// Resources will not be released in normal execution.
	guard.release ();

    return EXIT_SUCCESS;
}
//--------------------------------------------------------------------------------------------------


#if OUTPUT



#endif
