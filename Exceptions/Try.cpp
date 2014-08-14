#include <windows.h>
#include <tchar.h>
#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
//---------------------------------------------------------------------------
INT _tmain(INT argc, TCHAR* argv[]) {
	INT ResT = - 666; 
	try	{				
		//{			
			std::vector<int> veciVec;
			INT iRes = veciVec.at(0);
		//}	
		ResT = 1;	
	}	
	catch (std::exception e) {	
		ResT = - 1;		
	}	
	catch (...) {	
		ResT = - 1;	
	}	


	system("pause");
	return 0;
}
//---------------------------------------------------------------------------
