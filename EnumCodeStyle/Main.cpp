 /*
 * \file  Main.cpp
 * \brief 
 */


//---------------------------------------------------------------------------
#include <string>
#include <iostream>
#include <assert.h>
//---------------------------------------------------------------------------
namespace NOpenMode {
    enum EType {
        Read1,
        Read2,
        READ3
    };
};
//---------------------------------------------------------------------------
class AClass {
    public:
        enum EOpenMode {
            omRead,
            OpenMode_Read,
            OPEN_MODE_READ
        };

        AClass() {}
};
//---------------------------------------------------------------------------
void 
foo1(NOpenMode::EType mode) {
    std::cout << "mode: " << mode << std::endl;
}
//---------------------------------------------------------------------------
void 
foo2(AClass::EOpenMode mode) {
    std::cout << "mode: " << mode << std::endl;
}
//---------------------------------------------------------------------------
int main(int iArgCount, char **paszArgs)
{
    {
        std::cout << NOpenMode::Read1 << std::endl;
        std::cout << NOpenMode::Read2 << std::endl;
        std::cout << NOpenMode::READ3 << std::endl;
    }

    {
        AClass::EOpenMode mode = AClass::OPEN_MODE_READ;

        std::cout << mode                   << std::endl;
        std::cout << AClass::omRead         << std::endl;
        std::cout << AClass::OpenMode_Read  << std::endl;
        std::cout << AClass::OPEN_MODE_READ << std::endl;
    }

    return EXIT_SUCCESS;
}
//---------------------------------------------------------------------------


#if OUTPUT


#endif