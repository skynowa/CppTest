/**
 * \file  RefCounter.cpp
 * \brief How do I do simple reference counting
 *
 * \review
 *
 * https://isocpp.org/wiki/faq/freestore-mgmt#ref-count-simple
 */


#include <StdStream.h>
#include <StdTest.h>
#include <Stl.h>
//--------------------------------------------------------------------------------------------------
class FredPtr;

class Fred
{
public:
	Fred() :
		count_(0)
		/*...*/
	{
	}
		///< All ctors set count_ to "0"

	// ...

private:
	unsigned count_ {};
		///< count_ must be initialized to 0 by all constructors
		///< count_ is the number of FredPtr objects that point at this

	friend class FredPtr;
};
//--------------------------------------------------------------------------------------------------
class FredPtr
{
public:
	FredPtr(Fred* p) : _p(p)             { ++ _p->count_; }  // p must not be null
	FredPtr(const FredPtr& p) : _p(p._p) { ++ _p->count_; }
   ~FredPtr()                            { if (--_p->count_ == 0) delete _p; }

   /**
	* DO NOT CHANGE THE ORDER OF THESE STATEMENTS!
	* (This order properly handles self-assignment)
	* (This order also properly handles recursion, e.g., if a Fred contains FredPtrs)
	*/
	FredPtr &
	operator = (const FredPtr& p)
	{
		Fred* const old = _p;
		_p = p._p;

		++ _p->count_;

		if (-- old->count_ == 0) {
			delete old;
		}

		return *this;
	}

	Fred* operator -> () { return _p; }
	Fred& operator * ()  { return *_p; }

private:
	Fred *_p {};
		///< _p is never NULL
};
//--------------------------------------------------------------------------------------------------
int main(int, char **)
{


    // std::cout << TRACE_VAR("") << std::endl;

    return EXIT_SUCCESS;
}
//--------------------------------------------------------------------------------------------------


#if OUTPUT



#endif
