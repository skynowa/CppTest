#ifndef header_h
#define header_h
 
#include <XLib/xCommon.h>
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
#endif //header_h