/**
 * \file  VirtualFriendFunction.cpp
 * \brief Simulate a virtual friend function
 *
 * \todo
 */


#include <StdStream.h>
#include <StdTest.h>
#include <Stl.h>
//--------------------------------------------------------------------------------------------------
class IBase
{
public:
	virtual ~IBase() {}

	friend std::ostream &
	operator << (std::ostream &os, const IBase &b);

protected:
	virtual void print(std::ostream &os) const
	{
		os << _value;
	}


private:
	std::string _value {"IBase"};
};
//--------------------------------------------------------------------------------------------------
// make sure to put this function into the header file
inline std::ostream&
operator << (std::ostream &os, const IBase &b)
{
	// delegate the work to a polymorphic member function
	b.print(os);

	return os;
}
//--------------------------------------------------------------------------------------------------
class Derived :
	public IBase
{
protected:
	void print(std::ostream &os) const override
	{
		os << _value;
	}

private:
	std::string _value {"Derived"};
};
//--------------------------------------------------------------------------------------------------
int main(int, char **)
{
	Derived d;
    std::cout << TRACE_VAR(d) << std::endl;

	IBase *base = &d;
	std::cout << TRACE_VAR(*base) << std::endl;

    return EXIT_SUCCESS;
}
//--------------------------------------------------------------------------------------------------


#if OUTPUT

d:     Derived
*base: Derived

#endif
