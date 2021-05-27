/**
 * \file  Var.h
 * \brief
 */


#pragma once

#include <StdStream.h>
#include <StdTest.h>
#include <Stl.h>
//--------------------------------------------------------------------------------------------------
class Var
{
public:
	std::string value {};

	Var() :
		value{"aaa"}
	{
		STD_TRACE_FUNC;
	};

	~Var()
	{
		STD_TRACE_FUNC;
	};
};
//--------------------------------------------------------------------------------------------------
