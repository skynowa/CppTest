/**
 * \file  main.cpp
 * \brief
 *
 * \todo
 */


// CxHandle.cpp : Defines the entry point for the console application.
//

//---------------------------------------------------------------------------
#include "stdafx.h"
#include <iostream>
#include <windows.h>
//---------------------------------------------------------------------------
enum EHandleValue {
    hvNull,
    hvInvalid
};

template<EHandleValue hvTag>
HANDLE CxHandleFailValueGet();


template<>
HANDLE
CxHandleFailValueGet<hvNull>() {
    return NULL;
}

template<>
HANDLE
CxHandleFailValueGet<hvInvalid>() {
    return INVALID_HANDLE_VALUE;
}


template<EHandleValue hvTag>
class CxHandleT {
    public:
        HANDLE m_hHandle;

        CxHandleT()
            : m_hHandle( CxHandleFailValueGet<hvTag>() )
        {
            std::cout << __FUNCTION__ << std::endl;
        }

        ~CxHandleT()
        {
            std::cout << __FUNCTION__ << std::endl;
        }
};
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
int main(int argc, _TCHAR* argv[]) {
    {
	    CxHandleT<hvNull>    hHandle1;
	    CxHandleT<hvInvalid> hHandle2;
    }

    system("pause");

	return 0;
}
//---------------------------------------------------------------------------
