/**
 * \file  header.h
 * \brief
 */


#pragma once

#include <StdStream/StdStream.h>
#include <StdTest/StdTest.h>
#include <Stl.h>
//--------------------------------------------------------------------------------------------------
struct Test
{
    struct Init
    {
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
        static const Init _init;
    }
};
//--------------------------------------------------------------------------------------------------
