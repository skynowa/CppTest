/**
 * \file  CopyOnWrite.cpp
 * \brief Achieve lazy copy optimization. Like lazy initialization, do the work just when you need
 *        because of efficiency
 *
 * \see   https://shaharmike.com/cpp/std-string/
 *
 * To implement copy-on-write, a smart pointer to the real content is used to encapsulate
 * the object's value, and on each modification an object reference count is checked;
 * if the object is referenced more than once, a copy of the content is created before modification
 */


#include <StdStream/StdStream.h>
#include <StdTest/StdTest.h>
#include <Stl.h>
//--------------------------------------------------------------------------------------------------
template <class T>
class CowPtr
{
public:
	using ref_ptr_t = std::shared_ptr<T>;

	CowPtr(T *t) :
		_sp(t)
	{
	}

	CowPtr(const ref_ptr_t &refptr) :
		_sp(refptr)
	{
	}

	const T &
	operator * () const
	{
		return *_sp;
	}

	T &
	operator * ()
	{
		_detach();
		return *_sp;
	}

	const T *
	operator -> () const
	{
		return _sp.operator->();
	}

	T *
	operator -> ()
	{
		_detach();
		return _sp.operator->();
	}

private:
	ref_ptr_t _sp;

	void _detach()
	{
		T *tmp = _sp.get();

		if ( !( tmp == 0 || _sp.unique() ) ) {
			_sp = ref_ptr_t( new T( *tmp ) );
		}
	}
};
//--------------------------------------------------------------------------------------------------
int main(int, char **)
{
	CowPtr<std::string> s1(new std::string("Hello"));
	CowPtr<std::string> s2(s1);

	// Lazy-copy, shared state
	std::cout << STD_TRACE_VAR(*s1) << std::endl;
	std::cout << STD_TRACE_VAR(*s2) << std::endl;

	// Non-const access detaches s1 before modification
	(*s1)[4] = '!';

	std::cout << STD_TRACE_VAR(*s1) << std::endl;
	std::cout << STD_TRACE_VAR(*s2) << std::endl;

    return EXIT_SUCCESS;
}
//--------------------------------------------------------------------------------------------------


#if OUTPUT

*s1: Hello
*s2: Hello
*s1: Hell!
*s2: Hello

#endif
