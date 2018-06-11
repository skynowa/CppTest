 /*
 * \file  Main.cpp
 * \brief 
 */


//---------------------------------------------------------------------------
#include <string>
#include <iostream>
#include <assert.h>
//---------------------------------------------------------------------------
struct SEmpty {

};

class CEmpty {

};

class CData {
    void foo() { ; }
};

class CInterface {
    virtual void foo() = 0;
};

class CVirtual {
    virtual void foo() { ; }
};

class CDerivedVirtual {
    virtual void foo() { ; }
};
//---------------------------------------------------------------------------
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
//---------------------------------------------------------------------------


#if OUTPUT
// NOTE:

sizeof(void *):          4
sizeof(CEmpty):          1
sizeof(SEmpty):          1  // for C equal 0, C++ equal 1
sizeof(CData):           1
sizeof(CInterface):      4
sizeof(CVirtual:         4
sizeof(CDerivedVirtual): 4


#endif