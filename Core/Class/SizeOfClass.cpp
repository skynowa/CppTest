/**
 * \file  SizeOfClass.cpp
 * \brief
 */


#include <StdStream.h>
#include <StdTest.h>
#include <Stl.h>
//--------------------------------------------------------------------------------------------------
struct SEmpty
{
};

class CEmpty
{
};

class CData
{
    void foo() {}
};

class CInterface
{
    virtual ~CInterface() {};

    virtual void foo() = 0;
};

class CVirtual
{
    virtual ~CVirtual() {};

    virtual void foo() {}
};

class CDerivedVirtual
{
    virtual ~CDerivedVirtual() {};

    virtual void foo() {}
};
//--------------------------------------------------------------------------------------------------
int main(int, char **)
{
    std::cout << "sizeof(void *):          " << sizeof(void *)          << std::endl;
    std::cout << "sizeof(SEmpty):          " << sizeof(SEmpty)          << std::endl;
    std::cout << "sizeof(CEmpty):          " << sizeof(CEmpty)          << std::endl;
    std::cout << "sizeof(CData):           " << sizeof(CData)           << std::endl;
    std::cout << "sizeof(CInterface):      " << sizeof(CInterface)      << std::endl;
    std::cout << "sizeof(CVirtual:         " << sizeof(CVirtual)        << std::endl;
    std::cout << "sizeof(CDerivedVirtual): " << sizeof(CDerivedVirtual) << std::endl;

    return EXIT_SUCCESS;
}
//--------------------------------------------------------------------------------------------------

#if OUTPUT

sizeof(void *):          8
sizeof(SEmpty):          1
sizeof(CEmpty):          1
sizeof(CData):           1
sizeof(CInterface):      8
sizeof(CVirtual:         8
sizeof(CDerivedVirtual): 8

#endif