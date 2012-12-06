 /*
 * \file  Main.cpp
 * \brief 
 */


//---------------------------------------------------------------------------
#include <string>
#include <iostream>
#include <assert.h>
//---------------------------------------------------------------------------
class AClass {
    public:
        enum EOpenMode {
            omRead,
            OpenMode_Read,
            OPEN_MODE_READ,
        };

        AClass() {}
};
//---------------------------------------------------------------------------
int main(int iArgCount, char **paszArgs)
{
    AClass a;

    std::cout << a.omRead         << std::endl;
    std::cout << a.OpenMode_Read  << std::endl;
    std::cout << a.OPEN_MODE_READ << std::endl;

    return EXIT_SUCCESS;
}
//---------------------------------------------------------------------------


#if OUTPUT


#endif