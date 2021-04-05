/**
 * \file
 * \brief
 *
 * \todo
 */


#ifndef header_h
#define header_h

#include <iostream>
#include <StdTest.h>

struct Test
{
    struct Init {
        Init()
        {
            STD_TRACE_FUNC
        }
        ~Init()
        {
            STD_TRACE_FUNC
        }
    };

    Test()
    {
        static const Init m_Obj;
    }
};
#endif //header_h
