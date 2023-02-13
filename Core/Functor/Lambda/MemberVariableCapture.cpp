/**
 * \file  MemberVariableCapture.cpp
 * \brief
 */


#include <StdStream/StdStream.h>
#include <StdTest/StdTest.h>
#include <Stl.h>
//--------------------------------------------------------------------------------------------------
class OddCounter
{
public:
	int getCount()
	{
		return mCounter;
	}

	void update(std::vector<int> & vec)
	{
		// Traverse the vector and increment mCounter if element is odd
		// this is captured by value inside lambda
		std::for_each(vec.begin(), vec.end(),
			[this](int element)
			{
				if (element % 2) {
					// Accessing member variable from outer scope
					++ mCounter;
				}
			});
	}

private:
	// tracks the count of odd numbers encountered
	int mCounter {};
};
//--------------------------------------------------------------------------------------------------
int main(int, char **)
{
	std::vector<int> vec = {12,3,2,1,8,9,0,2,3,9,7};

	OddCounter counterObj;

	// Passing the vector to OddCounter object
	counterObj.update(vec);

	int count = counterObj.getCount();

	std::cout << "Counter = " << count << std::endl;

    return EXIT_SUCCESS;
}
//--------------------------------------------------------------------------------------------------


#if OUTPUT

Counter = 6

#endif
