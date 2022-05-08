/**
 * \file  NonCopyableMixin.cpp
 * \brief To prevent objects of a class from being copy-constructed or assigned to each other
 */


#include <StdStream/StdStream.h>
#include <StdTest/StdTest.h>
#include <Stl.h>
//--------------------------------------------------------------------------------------------------
class NonCopyable
{
public:
	NonCopyable (const NonCopyable &) = delete;
	NonCopyable & operator = (const NonCopyable &) = delete;

protected:
	NonCopyable () = default;
	~NonCopyable () = default;
		///< Protected non-virtual destructor
};
//-------------------------------------------------------------------------------------------------
class CantCopy :
	private NonCopyable
{
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
