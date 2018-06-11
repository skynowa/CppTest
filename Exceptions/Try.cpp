#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
//---------------------------------------------------------------------------
int main(int, char **)
{
	int ResT = - 666;

	try	{
		//{
			std::vector<int> veciVec;
			int iRes = veciVec.at(0);
		//}
		ResT = 1;
	}
	catch (std::exception e) {
		ResT = - 1;
	}
	catch (...) {
		ResT = - 1;
	}

	return 0;
}
//---------------------------------------------------------------------------
