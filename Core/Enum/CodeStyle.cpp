 /*
 * \file  CodeStyle.cpp
 * \brief
 */


#include <StdStream.h>
#include <StdTest.h>
#include <Stl.h>
//---------------------------------------------------------------------------
namespace NOpenMode
{

enum EType
{
    Read1 = 0,
    Read2 = 1,
    READ3 = 2
};

};
//---------------------------------------------------------------------------
class AClass
{
public:
    enum EOpenMode {
        omRead         = 0,
        OpenMode_Read  = 1,
        OPEN_MODE_READ = 2
    };

    AClass()
    {
    }
};
//---------------------------------------------------------------------------
void
foo1(NOpenMode::EType mode)
{
    std::cout << "mode: " << mode << std::endl;
}
//---------------------------------------------------------------------------
void
foo2(AClass::EOpenMode mode)
{
    std::cout << "mode: " << mode << std::endl;
}
//---------------------------------------------------------------------------
int main(int, char **)
{
    {
        std::cout << NOpenMode::Read1 << std::endl;
        std::cout << NOpenMode::Read2 << std::endl;
        std::cout << NOpenMode::READ3 << std::endl;
        std::cout << std::endl;
    }

    {
        AClass::EOpenMode mode = AClass::OPEN_MODE_READ;

        std::cout << mode                   << std::endl;
        std::cout << AClass::omRead         << std::endl;
        std::cout << AClass::OpenMode_Read  << std::endl;
        std::cout << AClass::OPEN_MODE_READ << std::endl;
        std::cout << std::endl;
    }

    return EXIT_SUCCESS;
}
//---------------------------------------------------------------------------


#if OUTPUT

0
1
2

2
0
1
2


#endif