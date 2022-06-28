 /*
 * \file  CodeStyle.cpp
 * \brief
 */


#include <StdStream/StdStream.h>
#include <StdTest/StdTest.h>
#include <Stl.h>
//-------------------------------------------------------------------------------------------------
namespace open_mode
{

enum Type
{
    Read1 = 0,
    Read2 = 1,
    READ3 = 2,
    Max   = READ3 + 1
};

}
//-------------------------------------------------------------------------------------------------
enum class /* struct */ OpenMode
{
    a   = 0,
    b   = 1,
    c   = 2,
    max = c + 1
};
//-------------------------------------------------------------------------------------------------
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
//-------------------------------------------------------------------------------------------------
template<typename T>
void
printEnum(T mode)
{
    std::cout << "mode: " << static_cast<int>(mode) << std::endl;
}
//-------------------------------------------------------------------------------------------------
int main(int, char **)
{
    {
        std::cout << "[enum Type]" << std::endl;

        ::printEnum(open_mode::Read1);
        ::printEnum(open_mode::Read2);
        ::printEnum(open_mode::READ3);
        ::printEnum(open_mode::Max);

        std::cout << std::endl;
    }

    {
        std::cout << "[enum class Alpha]" << std::endl;

        ::printEnum(OpenMode::a);
        ::printEnum(OpenMode::b);
        ::printEnum(OpenMode::c);
        ::printEnum(OpenMode::max);

        std::cout << std::endl;
    }

    {
        std::cout << "[class A]" << std::endl;

        A::OpenMode mode = A::OPEN_MODE_READ;

        ::printEnum(mode);
        ::printEnum(A::omRead);
        ::printEnum(A::OpenMode_Read);
        ::printEnum(A::OPEN_MODE_READ);

        std::cout << std::endl;
    }

    return EXIT_SUCCESS;
}
//-------------------------------------------------------------------------------------------------


#if OUTPUT

[enum Type]
mode: 0
mode: 1
mode: 2
mode: 3

[enum class Alpha]
mode: 0
mode: 1
mode: 2
mode: 3

[class A]
mode: 2
mode: 0
mode: 1
mode: 2

#endif