/**
 * \file  Printf.cpp
 * \brief
 */


#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <assert.h>
//---------------------------------------------------------------------------
void
logAppend(const char *pcszFilePath, const char *pcszText)
{
	assert(NULL != pcszFilePath);
	assert(NULL != pcszText);

	setlocale(LC_ALL, "");

	FILE *pFile = fopen(pcszFilePath, "a");
	assert(NULL != pFile);

	fprintf(pFile, "%s", pcszText);

	fclose(pFile);
	pFile = NULL;
}
//---------------------------------------------------------------------------
int main(int, char **)
{
	::logAppend("./Test.log", "msg\n");

	return 0;
}
//---------------------------------------------------------------------------
