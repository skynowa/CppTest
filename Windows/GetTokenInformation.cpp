/**
 * \file  GetTokenInformation.cpp
 * \brief
 */


#include "stdafx.h"
#include <Windows.h>
#include <Iads.h>
#include <AdsHlp.h>
//-------------------------------------------------------------------------------------------------
int main(int argc, _TCHAR* argv[])
{
    DWORD i, dwSize;
    HANDLE hToken;
    PTOKEN_GROUPS pGroupInfo;
    PTOKEN_USER pUserInfo = NULL;
    HRESULT hr;

    hr = CoInitialize(NULL);
    if (SUCCEEDED(hr))
    {
        // Open a handle to the access token for the calling process.
        if (OpenProcessToken (GetCurrentProcess(), TOKEN_QUERY, &hToken))
        {
            dwSize = 0;
            GetTokenInformation (hToken, TokenUser, NULL, dwSize, &dwSize);
            if (pUserInfo = (PTOKEN_USER) GlobalAlloc (GPTR, dwSize))
            {
                // Call GetTokenInformation again to get the group information.
                if (!GetTokenInformation (hToken, TokenUser, pUserInfo, dwSize, &dwSize))
                {
                    GlobalFree (pUserInfo);
                    pUserInfo = NULL;
                }
            }

            dwSize = 0;
            GetTokenInformation (hToken, TokenGroups, NULL, dwSize, &dwSize);
            if (pGroupInfo = (PTOKEN_GROUPS) GlobalAlloc (GPTR, dwSize))
            {
                if (GetTokenInformation (hToken, TokenGroups, pGroupInfo, dwSize, &dwSize))
                {
                    static WCHAR szName[1024], szDomain[1024];

                    for (i=0; i < pGroupInfo->GroupCount; i++)
                    {
                        if (pGroupInfo->Groups[i].Attributes & SE_GROUP_ENABLED)
                        {
                            BOOL bEqual = FALSE;
                            if (EqualDomainSid (pUserInfo->User.Sid, pGroupInfo->Groups[i].Sid, &bEqual))
                            {
                                if (bEqual)
                                {
                                    DWORD   dwName, dwDomain;
                                    SID_NAME_USE SidNameUse;
                                    dwName = 1024;
                                    dwDomain = 1024;
                                    if (LookupAccountSid (NULL, pGroupInfo->Groups[i].Sid, szName, &dwName, szDomain, &dwDomain, &SidNameUse))
                                        wprintf(L"%s\n",szName);
                                }
                            }
                        }
                    }
                }
                GlobalFree (pGroupInfo);
            }

            if (pUserInfo != NULL)
                GlobalFree (pUserInfo);

            // Close the access token handle
            CloseHandle (hToken);
        }
    }

    CoUninitialize();

    return 0;
}
//-------------------------------------------------------------------------------------------------
