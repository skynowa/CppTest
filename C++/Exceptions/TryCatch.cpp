/**
 * \file  TryCatch.cpp
 * \brief
 */


#include <StdStream/StdStream.h>
#include <StdTest/StdTest.h>
#include <Stl.h>
//---------------------------------------------------------------------------
int main(int, char **)
{
	int iRv = - 666;

	try	{
		//{
			std::vector<int> veciVec;

			int value = veciVec.at(0);
			std::cout << STD_TRACE_VAR(value) << std::endl;
		//}

		iRv = 1;
	}
	catch (const std::exception &e) {
		iRv = - 2;
	}
	catch (...) {
		iRv = - 3;
	}

	std::cout << STD_TRACE_VAR(iRv) << std::endl;

    return EXIT_SUCCESS;
}
//--------------------------------------------------------------------------------------------------


#if OUTPUT

iRv: -2

#endif
