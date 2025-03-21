/**
 * \file  Adapter.cpp
 * \brief Convert one class so that it appears to be another class
 *
 * \todo
 */


#include <StdStream/StdStream.h>
#include <StdTest/StdTest.h>
#include <Stl.h>
//--------------------------------------------------------------------------------------------------
class IRoundPeg
{
public:
	virtual ~IRoundPeg() = default;

	virtual void do_round() const = 0;
};
//--------------------------------------------------------------------------------------------------
class ISquarePeg
{
public:
	virtual ~ISquarePeg() = default;

	virtual void do_square() const = 0;
};
//--------------------------------------------------------------------------------------------------
class SquarePegAdapter :
	public IRoundPeg
{
public:
	SquarePegAdapter(ISquarePeg &a_peg) :
		_square_peg(a_peg)
	{
	}

	void do_round() const override
	{
		_square_peg.do_square();
	}

private:
	ISquarePeg &_square_peg;
};
//--------------------------------------------------------------------------------------------------
class HelloWorld :
	public ISquarePeg
{
public:
	void do_square() const override
	{
		std::cout << "Hello world!" << std::endl;
	}
};
//-------------------------------------------------------------------------------------------------


//--------------------------------------------------------------------------------------------------
class RoundHole
{
public:
	void insert(const IRoundPeg &a_peg) const
	{
		a_peg.do_round();
	}
};
//--------------------------------------------------------------------------------------------------
int main()
{
	HelloWorld peg;

	RoundHole hole;
	hole.insert( SquarePegAdapter(peg) );

	return 0;
}
//--------------------------------------------------------------------------------------------------

#if OUTPUT

Hello world!

#endif
