 /*
 * \file  Main.cpp
 * \brief 
 */


//---------------------------------------------------------------------------
#include <string>
#include <iostream>
#include <assert.h>
//---------------------------------------------------------------------------
int main(int iArgCount, char **paszArgs)
{
    {
        const int a0 = 0;

        std::cout << " static_cast<bool>(" << a0 << ") = " <<  static_cast<bool>(a0)  << std::endl;
        std::cout << "!static_cast<bool>(" << a0 << ") = " << !static_cast<bool>(a0)  << std::endl;
        std::cout << std::endl;
    }
    
    {
        const int b10 = 10;

        std::cout << " static_cast<bool>(" << b10 << ") = " <<  static_cast<bool>(b10) << std::endl;
        std::cout << "!static_cast<bool>(" << b10 << ") = " << !static_cast<bool>(b10) << std::endl;
        std::cout << std::endl;
    }
    
    {
        const int c_20 = -20;

        std::cout << " static_cast<bool>(" << c_20 << ") = " <<  static_cast<bool>(c_20) << std::endl;
        std::cout << "!static_cast<bool>(" << c_20 << ") = " << !static_cast<bool>(c_20) << std::endl;
        std::cout << std::endl;
    }

    return EXIT_SUCCESS;
}
//---------------------------------------------------------------------------


#if OUTPUT

 static_cast<bool>(0) = 0
!static_cast<bool>(0) = 1

 static_cast<bool>(10) = 1
!static_cast<bool>(10) = 0

 static_cast<bool>(-20) = 1
!static_cast<bool>(-20) = 0



#endif
