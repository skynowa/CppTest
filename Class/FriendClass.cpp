 /*
 * \file  Main.cpp
 * \brief friend class
 */


//---------------------------------------------------------------------------
#include <string>
#include <iostream>
#include <assert.h>
//--------------------------------------------------------------------------------
class CFile {
    private:
        friend class CTest_CFile;
     
        static bool _isExists() { 
            std::cout << __FUNCTION__ << std::endl;
            return false;
        }
};
//--------------------------------------------------------------------------------
class CTest_CFile {
    public:
        bool test() { 
            return CFile::_isExists(); 
        } 
};
//---------------------------------------------------------------------------
int main(int iArgCount, char **paszArgs)
{
    CTest_CFile t;

    t.test();

    return EXIT_SUCCESS;
}
//---------------------------------------------------------------------------


#if OUTPUT

CFile::_is_exists

#endif