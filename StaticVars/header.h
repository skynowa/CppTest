#ifndef header_h
#define header_h
 
#include <XLib/xCommon.h>


struct Test
{
    struct Init {
        Init()
        {
			xSTD_COUT_FUNC_MSG(xT("\a")); 
        }
        ~Init()
        {
			xSTD_COUT_FUNC_MSG(xT("\a")); 
        }
    };
 
    Test()
    {
        static const Init m_Obj;
    }
};
#endif //header_h