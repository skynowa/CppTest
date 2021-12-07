 /*
 * \file  CodeStyle.cpp
 * \brief
 */


#include <StdStream.h>
#include <StdTest.h>
#include <Stl.h>
//---------------------------------------------------------------------------
namespace open_mode
{

enum EType
{
    Read1 = 0,
    Read2 = 1,
    READ3 = 2,
    Max   = READ3 + 1
};

enum class /* struct */ Alpha
{
    a   = 0,
    b   = 1,
    c   = 2,
    max = c + 1
};

};
//---------------------------------------------------------------------------
class A
{
public:
    enum OpenMode
    {
        omRead         = 0,
        OpenMode_Read  = 1,
        OPEN_MODE_READ = 2
    };

    A() = default;
};
//---------------------------------------------------------------------------
void
foo1(open_mode::EType mode)
{
    std::cout << "mode: " << mode << std::endl;
}
//---------------------------------------------------------------------------
void
printAlpha(open_mode::Alpha mode)
{
    std::cout << "mode: " << static_cast<int>(mode) << std::endl;
}
//---------------------------------------------------------------------------
void
foo3(A::OpenMode mode)
{
    std::cout << "mode: " << mode << std::endl;
}
//---------------------------------------------------------------------------
int main(int, char **)
{
    {
        std::cout << open_mode::Read1 << std::endl;
        std::cout << open_mode::Read2 << std::endl;
        std::cout << open_mode::READ3 << std::endl;
        std::cout << open_mode::Max   << std::endl;
        std::cout << std::endl;
    }

    {
        A::OpenMode mode = A::OPEN_MODE_READ;

        std::cout << mode              << std::endl;
        std::cout << A::omRead         << std::endl;
        std::cout << A::OpenMode_Read  << std::endl;
        std::cout << A::OPEN_MODE_READ << std::endl;
        std::cout << std::endl;
    }

    return EXIT_SUCCESS;
}
//---------------------------------------------------------------------------


#if OUTPUT

0
1
2
3

2
0
1
2

#endif