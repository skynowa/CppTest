/**
 * \file  LiskovSubstitution_LSP.cpp
 * \brief Subclasses should be substitutable for their base classes
 *
 * Demonstrates using derived objects through a base abstraction without special cases.
 */


#include <StdStream/StdStream.h>
#include <StdTest/StdTest.h>
#include <Stl.h>
//--------------------------------------------------------------------------------------------------
class Bird
{
public:
	virtual ~Bird() = default;

	virtual std::string move() const = 0;
};
//--------------------------------------------------------------------------------------------------
class Sparrow :
	public Bird
{
public:
	std::string move() const override
	{
		return "Sparrow flies";
	}
};
//--------------------------------------------------------------------------------------------------
class Penguin :
	public Bird
{
public:
	std::string move() const override
	{
		return "Penguin swims";
	}
};
//--------------------------------------------------------------------------------------------------
void printMove(const Bird &a_bird)
{
	std::cout << a_bird.move() << std::endl;
}
//--------------------------------------------------------------------------------------------------
int main(int, char **)
{
	const Sparrow sparrow;
	const Penguin penguin;

	printMove(sparrow);
	printMove(penguin);

    return EXIT_SUCCESS;
}
//--------------------------------------------------------------------------------------------------


#if OUTPUT

Sparrow flies
Penguin swims

#endif
