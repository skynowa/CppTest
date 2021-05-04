/**
 * \file  Adapter.cpp
 * \brief Convert one class so that it appears to be another class
 *
 * \todo
 */


#include <StdStream.h>
#include <StdTest.h>
#include <Stl.h>
//--------------------------------------------------------------------------------------------------
class RoundPeg
{
public:
	virtual ~RoundPeg() { }
	virtual void do_round() const=0;
};

class SquarePeg
{
public:
	virtual ~SquarePeg() { }
	virtual void do_square() const=0;
};

class RoundHole
{
public:
	void insert(const RoundPeg & peg) const
	{
		peg.do_round();
	}
};

class SquarePegAdapter : public RoundPeg
{
	SquarePeg & square_peg;
public:
	SquarePegAdapter(SquarePeg & peg) : square_peg(peg)
	{
	}
	void do_round() const
	{
		square_peg.do_square();
	}
};

class HelloWorld : public SquarePeg
{
public:
	void do_square() const
	{
		std::cout << "Hello world!" << std::endl;
	}
};

void hello_world(const RoundPeg & peg)
{
	RoundHole().insert(peg);
}
//--------------------------------------------------------------------------------------------------
int main()
{
	HelloWorld peg;
	hello_world(SquarePegAdapter(peg));
	return 0;
}
//--------------------------------------------------------------------------------------------------