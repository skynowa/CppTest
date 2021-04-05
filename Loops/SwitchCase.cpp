/**
 * \file  SwitchCase.cpp.cpp
 * \brief modern switch, case
 *
 * \todo
 */


#include <iostream>
#include <string>


//---------------------------------------------------------------------------
int
main() {
    int iRes = 0;
	switch (iRes) {
    	case 0 ... 3: {
				std::cout << "0 ... 3" << std::endl;
            }
    		break;

    	case 4 ... 5: {
				std::cout << "3 ... 4" << std::endl;
            }
    		break;

    	case 6: {
				std::cout << "5" << std::endl;
            }
    		break;

    	default:
    		break;
    }

   return 0;
}
//---------------------------------------------------------------------------
