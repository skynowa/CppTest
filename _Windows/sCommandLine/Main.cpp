 /*
 * \file  Main.cpp
 * \brief 
 */


//---------------------------------------------------------------------------
#include <string>
#include <iostream>
#include <assert.h>
#include <stdio.h>
#include <windows.h>
#include <Winternl.h>
#include <memory>
//---------------------------------------------------------------------------
typedef NTSTATUS (NTAPI *_NtQueryInformationProcess) (
    HANDLE ProcessHandle,
    DWORD  ProcessInformationClass,
    PVOID  ProcessInformation,
    DWORD  ProcessInformationLength,
    PDWORD ReturnLength
);

PVOID 
_GetPebAddress(const HANDLE &ProcessHandle)
{
    PVOID   pvRv    = NULL;
    HMODULE hModule = ::GetModuleHandleA("ntdll.dll");
    assert(NULL != hModule);

    _NtQueryInformationProcess 
    NtQueryInformationProcess = (_NtQueryInformationProcess)::GetProcAddress(hModule, "NtQueryInformationProcess");
    assert(NULL != NtQueryInformationProcess);

    PROCESS_BASIC_INFORMATION pbi;

    PROCESSINFOCLASS picInfo86 = ProcessBasicInformation;
    PROCESSINFOCLASS picInfo64 = ProcessWow64Information;

    NTSTATUS nsRv = NtQueryInformationProcess(ProcessHandle, picInfo86, &pbi, sizeof(pbi), NULL);
    assert(NT_SUCCESS(nsRv));

    pvRv = pbi.PebBaseAddress;
    assert(NULL != pvRv);

    return pvRv;
}
//---------------------------------------------------------------------------
std::string
sCommandLine(
    const DWORD &a_ciPid
) 
{
    std::string sRv;
    BOOL        blRv = FALSE;
    HANDLE      processHandle;
    
    processHandle = ::OpenProcess(PROCESS_QUERY_INFORMATION | PROCESS_VM_READ, FALSE, a_ciPid);
    assert(NULL != processHandle);

    PVOID pebAddress               = _GetPebAddress(processHandle);
    PVOID rtlUserProcParamsAddress = NULL;

    // get the address of ProcessParameters
    blRv = ::ReadProcessMemory(processHandle, (PCHAR)pebAddress + 0x10,  &rtlUserProcParamsAddress, sizeof(PVOID), NULL);
    assert(FALSE != blRv);

    // read the usCommandLine UNICODE_STRING structure
    UNICODE_STRING usCommandLine = {0};

    blRv = ::ReadProcessMemory(processHandle, (PCHAR)rtlUserProcParamsAddress + 0x40, &usCommandLine, sizeof(usCommandLine), NULL);
    assert(FALSE != blRv);

    // allocate memory to hold the command line
    {
        WCHAR *pCommandLineContents = (WCHAR *)::malloc(usCommandLine.Length);

        // read the command line 
        blRv = ::ReadProcessMemory(processHandle, usCommandLine.Buffer, pCommandLineContents, usCommandLine.Length, NULL);
        assert(FALSE != blRv);

        // length specifier is in characters, but commandLine.Length is in bytes a WCHAR is 2 bytes
        //printf("%.*S\n", usCommandLine.Length / 2, pCommandLineContents);

        std::wstring wsRv; 
        
        wsRv.assign(pCommandLineContents, usCommandLine.Length / 2);
        sRv.assign(wsRv.begin(), wsRv.end());

        ::CloseHandle(processHandle);

        ::free(pCommandLineContents);
    }

    return sRv;
}
//---------------------------------------------------------------------------
int main(int iArgCount, char **paszArgs)
{
    DWORD dwPid  = 2088;

    std::string sCmd = sCommandLine(dwPid);
    std::cout << "sCmd: " << sCmd << std::endl;

    return EXIT_SUCCESS;
}
//---------------------------------------------------------------------------

#if OUTPUT

sCmd: "D:\Soft\Antivirus\AnVir\AnVir.exe" Minimized

#endif
