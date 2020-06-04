#include <stdint.h>
#include <stdlib.h>
#include <Windows.h>
#include <sddl.h>

#include <iostream>
#include <iomanip>
#include <memory>

#pragma comment(lib,"advapi32.lib")
//-------------------------------------------------------------------------------------------------
struct HeapDeleter
{
    using pointer = LPVOID;

    void operator ( )(LPVOID p)
    {
        ::HeapFree(::GetProcessHeap(), 0, p);
    }
};
using heap_unique_ptr = std::unique_ptr<LPVOID, HeapDeleter>;
//-------------------------------------------------------------------------------------------------
struct HandleDeleter
{
	using pointer = HANDLE;

    void operator () (HANDLE p)
    {
        ::CloseHandle(p);
    }
};
using handle_unique_ptr = std::unique_ptr<HANDLE, HandleDeleter>;
//-------------------------------------------------------------------------------------------------
using uid_t = uint32_t;
//-------------------------------------------------------------------------------------------------
BOOL
GetUserSID(
	HANDLE  token,
	PSID   *sid
)
{
    if (token == nullptr ||
		token == INVALID_HANDLE_VALUE ||
		sid   == nullptr)
    {
        SetLastError(ERROR_INVALID_PARAMETER);
        return FALSE;
    }

    DWORD tokenInformationLength {};
    ::GetTokenInformation(token, TokenUser, nullptr, 0, &tokenInformationLength);
    if (GetLastError() != ERROR_INSUFFICIENT_BUFFER) {
        return FALSE;
    }

    heap_unique_ptr data( ::HeapAlloc(::GetProcessHeap(), HEAP_ZERO_MEMORY, tokenInformationLength) );
    if (data.get() == nullptr) {
        return FALSE;
    }

    BOOL getTokenInfo = ::GetTokenInformation(token, TokenUser, data.get(), tokenInformationLength,
		&tokenInformationLength);
    if (! getTokenInfo) {
        return FALSE;
    }

    PTOKEN_USER pTokenUser = (PTOKEN_USER)data.get();
    DWORD       sidLength  = ::GetLengthSid(pTokenUser->User.Sid);

    heap_unique_ptr sidPtr( ::HeapAlloc(GetProcessHeap(), HEAP_ZERO_MEMORY, sidLength) );

    PSID sidL = (PSID)(sidPtr.get());
    if (sidL == nullptr) {
        return FALSE;
    }

    BOOL copySid = ::CopySid(sidLength, sidL, pTokenUser->User.Sid);
    if (!copySid) {
        return FALSE;
    }

    if ( !IsValidSid(sidL) ) {
        return FALSE;
    }

	// [out]
    *sid = sidL;

    sidPtr.release();

    return TRUE;
}
//-------------------------------------------------------------------------------------------------
uid_t GetUID(HANDLE token)
{
    PSID sid {};
    BOOL getSID = GetUserSID(token, &sid);
    if (!getSID || !sid) {
        return -1;
    }

    heap_unique_ptr sidPtr((LPVOID)(sid));

	LPWSTR stringSid {};
    BOOL convertSid = ::ConvertSidToStringSidW(sid, &stringSid);
    if (!convertSid) {
        return -1;
    }

    uid_t ret = -1;
    LPCWSTR p = ::wcsrchr(stringSid, L'-');
    if (p && ::iswdigit(p[1])) {
        ++ p;
        ret = ::_wtoi(p);
    }

    ::LocalFree(stringSid);

    return ret;
}
//-------------------------------------------------------------------------------------------------
uid_t getuid()
{
    HANDLE process = ::GetCurrentProcess();
    handle_unique_ptr processPtr(process);

    HANDLE token {};
    BOOL openToken = ::OpenProcessToken(process, TOKEN_READ|TOKEN_QUERY_SOURCE, &token);
    if (!openToken) {
        return -1;
    }

    handle_unique_ptr tokenPtr(token);

    return GetUID(token);
}
//-------------------------------------------------------------------------------------------------
uid_t geteuid()
{
    HANDLE process = ::GetCurrentProcess();
    HANDLE thread  = ::GetCurrentThread();

    HANDLE token {};
    BOOL openToken = ::OpenThreadToken(thread, TOKEN_READ|TOKEN_QUERY_SOURCE, FALSE, &token);
    if (!openToken &&
		::GetLastError() == ERROR_NO_TOKEN)
	{
        openToken = ::OpenThreadToken(thread, TOKEN_READ|TOKEN_QUERY_SOURCE, TRUE, &token);
        if (!openToken &&
			::GetLastError() == ERROR_NO_TOKEN)
		{
            openToken = ::OpenProcessToken(process, TOKEN_READ|TOKEN_QUERY_SOURCE, &token);
        }
    }

    if (!openToken) {
        return -1;
    }

    handle_unique_ptr tokenPtr(token);

    return GetUID(token);
}
//-------------------------------------------------------------------------------------------------
int main()
{
    uid_t uid  = getuid();
    uid_t euid = geteuid();

    std::cout
        << "uid: "  << std::setbase(10) << uid  << std::endl
        << "euid: " << std::setbase(10) << euid << std::endl
        << std::endl;

    return EXIT_SUCCESS;
}
//-------------------------------------------------------------------------------------------------
