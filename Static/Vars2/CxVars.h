#ifndef header_h
#define header_h

#include "CVar.h"
//---------------------------------------------------------------------------
class CxVars {
	public:
		static const CVar m_Var;

	private:
		CxVars() {};
		~CxVars() {};
};
//---------------------------------------------------------------------------
#include "CxVars.inl"

#endif //header_h
