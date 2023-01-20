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
 *
 * \review
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
#if 0
	CowPtr<String> s1 = "Hello";

	// Non-const detachment does nothing here
	char &c = s1->operator[](4);

	// Lazy-copy, shared state
	CowPtr<String> s2(s1);
	c = '!'; // Uh-oh
#endif

    return EXIT_SUCCESS;
}
//--------------------------------------------------------------------------------------------------


#if OUTPUT



#endif
