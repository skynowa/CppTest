/**
 * \file  OsBit.cpp
 * \brief
 *
 * Module Name:	CppCheckOSBitness.cpp
 * Project:		CppCheckOSBitness
 * Copyright (c) Microsoft Corporation.
 *
 * The code sample demonstrates how to determine whether the operating system
 * of the current machine or any remote machine is a 64-bit operating system.
 *
 * This source is subject to the Microsoft Public License.
 * See http://www.microsoft.com/opensource/licenses.mspx#Ms-PL.
 * All other rights reserved.
 *
 * THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
 * EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
 */


//-------------------------------------------------------------------------------------------------
#pragma region Includes
#include <stdio.h>
#include <windows.h>
#pragma endregion

#pragma region Is64BitOperatingSystem (IsWow64Process)
//-------------------------------------------------------------------------------------------------
//
//   FUNCTION: DoesWin32MethodExist(PCWSTR, PCSTR)
//
//   PURPOSE: The function determins whether a method exists in the export
//   table of a certain module.
//
//   PARAMETERS:
//   * pszModuleName - the name of the module.
//   * pszMethodName - the name of the method.
//
//   RETURN VALUE: The function returns TRUE if the method specified by
//   methodName exists in the export table of the module specified by
//   moduleName.
//
BOOL DoesWin32MethodExist(PCWSTR pszModuleName, PCSTR pszMethodName)
{
    HMODULE hModule = GetModuleHandle(pszModuleName);
    if (hModule == NULL)
    {
        return FALSE;
    }
    return (GetProcAddress(hModule, pszMethodName) != NULL);
}
//-------------------------------------------------------------------------------------------------
//
//   FUNCTION: Is64BitOperatingSystem()
//
//   PURPOSE: The function determines whether the current operating system is
//   a 64-bit operating system.
//
//   RETURN VALUE: The function returns TRUE if the operating system is
//   64-bit; otherwise, it returns FALSE.
//
BOOL Is64BitOperatingSystem()
{
#if defined(_WIN64)
    return TRUE;   // 64-bit programs run only on Win64
#elif defined(_WIN32)
    // 32-bit programs run on both 32-bit and 64-bit Windows
    BOOL f64bitOS = FALSE;
    return ((DoesWin32MethodExist(L"kernel32.dll", "IsWow64Process") &&
        IsWow64Process(GetCurrentProcess(), &f64bitOS)) && f64bitOS);
#else
    return FALSE;  // 64-bit Windows does not support Win16
#endif
}
//-------------------------------------------------------------------------------------------------
#pragma endregion

#pragma region Is64BitOperatingSystem (WMI)

#include <wbemidl.h>
#pragma comment(lib, "wbemuuid.lib")
#include <strsafe.h>
#include <comdef.h>
#include <wincred.h>
//-------------------------------------------------------------------------------------------------
//
//   FUNCTION: Is64BitOperatingSystem(LPCWSTR, LPCWSTR, LPCWSTR)
//
//   PURPOSE: The function determines whether the operating system of the
//   current machine of any remote machine is a 64-bit operating system
//   through Windows Management Instrumentation (WMI).
//
//   PARAMETERS:
//   * pszMachineName - the full computer name or IP address of the target
//     machine. "." or NULL means the local machine.
//   * pszUserName - the user name you need for a connection. A null value
//     indicates the current security context. If the user name is from a
//     domain other than the current domain, the string should contain the
//     domain name and user name, separated by a backslash: string 'username'
//     = "DomainName\\UserName".
//   * pszPassword - the password for the specified user.
//
//   RETURN VALUE: The function returns true if the operating system is
//   64-bit; otherwise, it returns false.
//
//   EXCEPTION: If this function fails, it throws a C++ exception which
//   contains the HRESULT of the failure. For example,
//   WBEM_E_LOCAL_CREDENTIALS (0x80041064) is thrown when user credentials
//   (pszUserName, pszPassword) are specified for local connections.
//   COR_E_UNAUTHORIZEDACCESS (0x80070005) is thrown because of incorrect
//   user name or password.
//   RPC_S_SERVER_UNAVAILABLE (0x800706BA) is usually caused by the firewall
//   on the target machine that blocks the WMI connection or some network
//   problem.
//
//   EXAMPLE CALL:
//     try
//     {
//         f64bitOS = Is64BitOperatingSystem(L".", NULL, NULL);
//         wprintf(L"The current operating system %s 64-bit.\n",
//             f64bitOS ? L"is" : L"is not");
//     }
//     catch (HRESULT hr)
//     {
//         wprintf(L"Is64BitOperatingSystem failed with HRESULT 0x%08lx\n", hr);
//     }
//
BOOL Is64BitOperatingSystem(LPCWSTR pszMachineName, LPCWSTR pszUserName,
                            LPCWSTR pszPassword)
{
    BOOL f64bitOS = FALSE;
    HRESULT hr = S_OK;
    IWbemLocator *pLoc = NULL;
    IWbemServices *pSvc = NULL;
    IEnumWbemClassObject *pEnumerator = NULL;

    // Initialize COM parameters with a call to CoInitializeEx.
    hr = CoInitializeEx(0, COINIT_MULTITHREADED);
    if (FAILED(hr))
    {
        throw hr;
    }

    // Initialize COM process security by calling CoInitializeSecurity.
    hr = CoInitializeSecurity(
        NULL,
        -1,                             // COM authentication
        NULL,                           // Authentication services
        NULL,                           // Reserved
        RPC_C_AUTHN_LEVEL_DEFAULT,      // Default authentication
        RPC_C_IMP_LEVEL_IDENTIFY,       // Default Impersonation
        NULL,                           // Authentication info
        EOAC_NONE,                      // Additional capabilities
        NULL                            // Reserved
        );
    if (FAILED(hr))
    {
        goto Cleanup;
    }

    // Obtain the initial locator to WMI by calling CoCreateInstance.
    hr = CoCreateInstance(CLSID_WbemLocator, 0, CLSCTX_INPROC_SERVER,
        IID_IWbemLocator, (LPVOID *) &pLoc);
    if (FAILED(hr))
    {
        goto Cleanup;
    }

    // Connect to WMI through the IWbemLocator::ConnectServer method.
    // User credentials cannot be used for local connections.

    if (pszMachineName == NULL)
    {
        pszMachineName = L".";
    }

    wchar_t szPath[200];
    hr = StringCchPrintf(szPath, ARRAYSIZE(szPath), L"\\\\%s\\root\\cimv2",
        pszMachineName);
    if (FAILED(hr))
    {
        goto Cleanup;
    }

    hr = pLoc->ConnectServer(
        _bstr_t(szPath),                // Path of the WMI namespace
        _bstr_t(pszUserName),           // User name
        _bstr_t(pszPassword),           // User password
        NULL,                           // Locale
        NULL,                           // Security flags
        NULL,                           // Authority
        NULL,                           // Context object
        &pSvc                           // IWbemServices proxy
        );
    if (FAILED(hr))
    {
        goto Cleanup;
    }

    // If you plan to connect to the remote with a different user name and
    // password than the one you are currently using, build a COAUTHIDENTITY
    // struct that can be used for setting security on proxy.
    COAUTHIDENTITY *userAcct =  NULL;
    COAUTHIDENTITY authIdent;
    wchar_t szDomain[CREDUI_MAX_USERNAME_LENGTH + 1];
    wchar_t szUser[CREDUI_MAX_USERNAME_LENGTH + 1];

    if (pszUserName != NULL)
    {
        ZeroMemory(&authIdent, sizeof(authIdent));

        LPCWSTR slash = wcschr(pszUserName, L'\\');
        if (slash == NULL)
        {
            // No domain info is available in the user name.
            // Leave authIdent's Domain and DomainLength fields blank.

            authIdent.User = (USHORT *)pszUserName;
            authIdent.UserLength = wcslen(pszUserName);
        }
        else
        {
            StringCchCopy(szUser, CREDUI_MAX_USERNAME_LENGTH + 1, slash + 1);
            authIdent.User = (USHORT *)szUser;
            authIdent.UserLength = wcslen(szUser);

            StringCchCopyN(szDomain, CREDUI_MAX_USERNAME_LENGTH + 1,
                pszUserName, slash - pszUserName);
            authIdent.Domain = (USHORT *)szDomain;
            authIdent.DomainLength = slash - pszUserName;
        }

        authIdent.Password = (USHORT *)pszPassword;
        authIdent.PasswordLength = wcslen(pszPassword);

        authIdent.Flags = SEC_WINNT_AUTH_IDENTITY_UNICODE;
        userAcct = &authIdent;
    }

    // Set security levels on the WMI connection.
    hr = CoSetProxyBlanket(
        pSvc,                           // Indicates the proxy to set
        RPC_C_AUTHN_DEFAULT,            // RPC_C_AUTHN_xxx
        RPC_C_AUTHZ_DEFAULT,            // RPC_C_AUTHZ_xxx
        COLE_DEFAULT_PRINCIPAL,         // Server principal name
        RPC_C_AUTHN_LEVEL_PKT_PRIVACY,  // RPC_C_AUTHN_LEVEL_xxx
        RPC_C_IMP_LEVEL_IMPERSONATE,    // RPC_C_IMP_LEVEL_xxx
        userAcct,                       // Client identity
        EOAC_NONE                       // Proxy capabilities
        );
    if (FAILED(hr))
    {
        goto Cleanup;
    }

    // Use the IWbemServices pointer to make requests of WMI. Query
    // Win32_Processor.AddressWidth which dicates the current operating mode
    // of the processor (on a 32-bit OS, it would be 32; on a 64-bit OS, it
    // would be 64).
    // Note: Win32_Processor.DataWidth indicates the capability of the
    // processor. On a 64-bit processor, it is 64.
    // Note: Win32_OperatingSystem.OSArchitecture tells the bitness of OS
    // too. On a 32-bit OS, it would be "32-bit". However, it is only
    // available on Windows Vista and newer OS.
    hr = pSvc->ExecQuery(bstr_t(L"WQL"),
        bstr_t(L"SELECT AddressWidth FROM Win32_Processor"),
        WBEM_FLAG_FORWARD_ONLY | WBEM_FLAG_RETURN_IMMEDIATELY,
        NULL, &pEnumerator);
    if (FAILED(hr))
    {
        goto Cleanup;
    }

    // Secure the enumerator proxy.
    hr = CoSetProxyBlanket(
        pEnumerator,                    // Indicates the proxy to set
        RPC_C_AUTHN_DEFAULT,            // RPC_C_AUTHN_xxx
        RPC_C_AUTHZ_DEFAULT,            // RPC_C_AUTHZ_xxx
        COLE_DEFAULT_PRINCIPAL,         // Server principal name
        RPC_C_AUTHN_LEVEL_PKT_PRIVACY,  // RPC_C_AUTHN_LEVEL_xxx
        RPC_C_IMP_LEVEL_IMPERSONATE,    // RPC_C_IMP_LEVEL_xxx
        userAcct,                       // Client identity
        EOAC_NONE                       // Proxy capabilities
        );
    if (FAILED(hr))
    {
        goto Cleanup;
    }

    // Get the data from the above query.
    IWbemClassObject *pclsObj = NULL;
    ULONG uReturn = 0;

    while (pEnumerator)
    {
        // Get one object.
        HRESULT hrTmp = pEnumerator->Next(WBEM_INFINITE, 1, &pclsObj, &uReturn);

        if (0 == uReturn)
        {
            break;
        }

        VARIANT vtProp;

        // Get the value of the AddressWidth property.
        hrTmp = pclsObj->Get(L"AddressWidth", 0, &vtProp, 0, 0);
        if (SUCCEEDED(hrTmp))
        {
            if (vtProp.intVal == 64)
            {
                f64bitOS = TRUE;
            }

            VariantClear(&vtProp);
        }

        pclsObj->Release();
        pclsObj = NULL;
    }

Cleanup:
    // Centralized cleanup for all allocated resources.
    if (pLoc)
    {
        pLoc->Release();
        pLoc = NULL;
    }
    if (pSvc)
    {
        pSvc->Release();
        pSvc = NULL;
    }
    if (pEnumerator)
    {
        pEnumerator->Release();
        pEnumerator = NULL;
    }

    CoUninitialize();

    // Throw the error if something failed in the function.
    if (FAILED(hr))
    {
        throw hr;
    }

    return f64bitOS;
}
//-------------------------------------------------------------------------------------------------
#pragma endregion
//-------------------------------------------------------------------------------------------------
int wmain(int argc, wchar_t* argv[])
{
    // Solution 1. Is64BitOperatingSystem (IsWow64Process)
    // Determine whether the current operating system is a 64 bit operating
    // system.
    BOOL f64bitOS = Is64BitOperatingSystem();
    wprintf(L"1. The current operating system %s 64-bit.\n", f64bitOS ? L"is" : L"is not");

    // Solution 2. Is64BitOperatingSystem (WMI)
    // Determine whether the current operating system is a 64 bit operating
    // system through WMI. Note: The first solution of using IsWow64Process
    // is the preferred way to detect OS bitness of the current system
    // because it is much easier and faster. The WMI solution is useful when
    // you want to find this information on a remote system.
    try
    {
        // If you want to get the OS bitness information of a remote system,
        // configure the system for remote connections of WMI
        // (http://msdn.microsoft.com/en-us/library/aa389290.aspx), and
        // replace the parameters (L".", NULL, NULL) with the remote computer
        // name and credentials for the connection.
        f64bitOS = Is64BitOperatingSystem(L".", NULL, NULL);
        wprintf(L"2. The current operating system %s 64-bit.\n", f64bitOS ? L"is" : L"is not");
    }
    catch (HRESULT hr)
    {
        wprintf(L"Is64BitOperatingSystem failed with HRESULT 0x%08lx\n", hr);
    }

	return 0;
}
//-------------------------------------------------------------------------------------------------
