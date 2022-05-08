/**
 * \file  VirtualFunction1.cpp
 * \brief
 */


#include <StdStream/StdStream.h>
#include <StdTest/StdTest.h>
#include <Stl.h>
//--------------------------------------------------------------------------------------------------
class X
{
public:
	virtual ~X() = default;

	virtual char getType()
	{
		return 'X';
	}
};
//---------------------------------------------------------------------------
class Y :
	public X
{
public:
	char getType()
	{
		return 'Y';
	}
};
//---------------------------------------------------------------------------
int main(int, char **)
{
	X *x = new X();
	X *y = new Y();

	std::cout << x->getType() << "    " << y->getType() << "\n";

	delete x;
	delete y;

    return EXIT_SUCCESS;
}
//--------------------------------------------------------------------------------------------------


#if OUTPUT

X    Y

#endif
