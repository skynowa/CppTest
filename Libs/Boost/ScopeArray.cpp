#include <cstdlib>
#include <iostream>

#include "boost/scoped_array.hpp"

static int count = 0;
//-------------------------------------------------------------------------------------------------
class printer
{
	int m_id;

public:
	printer(void) : m_id(count++)  {
		std::cout << "Printer " << m_id  << " construct" << std::endl;
	}

	~printer(void) {
			std::cout << "Printer " << m_id  << " destroyed" << std::endl;
	}
};
//-------------------------------------------------------------------------------------------------
int main(void)
{

	{
		boost::scoped_array<printer> p2(new printer[5]);
	}

	return EXIT_SUCCESS;
}
//-------------------------------------------------------------------------------------------------
