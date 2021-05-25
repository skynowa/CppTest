/**
 * \file  ForBreak.cpp
 * \brief
 */


#include <StdStream.h>
#include <StdTest.h>
#include <Stl.h>
//--------------------------------------------------------------------------------------------------
int main(int, char **)
{
	for (int i = 0; i < 10; ++ i) {
		{
			{
				if (i == 5) {
					break;
				}

				std::cout << "break_1" << std::endl;
			}

			std::cout << "break_2" << std::endl;
		}

		std::cout << "break_3" << std::endl << std::endl;
	}

	std::cout << "end" << std::endl;

    return EXIT_SUCCESS;
}
//--------------------------------------------------------------------------------------------------

#if OUTPUT

break_1
break_2
break_3

break_1
break_2
break_3

break_1
break_2
break_3

break_1
break_2
break_3

break_1
break_2
break_3

end

#endif
