// dllmain.cpp : 定义 DLL 应用程序的入口点。
#include "stdafx.h"

EXT_API_VERSION ApiVersion = { 1,1,EXT_API_VERSION_NUMBER, 0 };

// 三个dll的全局变量, 用在 windbgextensiondllinit函数里。
WINDBG_EXTENSION_APIS64 ExtensionApis;
USHORT SavedMajorVersion;
USHORT SavedMinorVersion;

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}

// windbgextensiondllinit 函数，当调试程序加载扩展dll时，首先调用该函数
// 并传递三个参数
VOID WinDbgExtensionDllInit(PWINDBG_EXTENSION_APIS64 lpExtensionApis,
	USHORT MajorVersion,
	USHORT MinorVersion)
{
	ExtensionApis = *lpExtensionApis;	
	MajorVersion = SavedMajorVersion;	// 主要版本号
	MinorVersion = SavedMinorVersion;	// 次要版本号

	return;
}

// 用来返回版本号
LPEXT_API_VERSION ExtensionApiVersion(VOID)
{
	// exxtensionapiversion should return EXT_API_VERSION_NUMBER64 in order for APIS
	// to recognize 64 bit addresses. KDEXT_64BIT also has to be defined before including
	// wdbgexts.h to get 64 bit headers for WINDBG_EXTENSION_APIS
	return &ApiVersion; 
}

// the debugger calls this routine every time you use an extension command
VOID CheckVersion(VOID)
{
	dprintf("hello fuck you, hereis check version\n");
	return;
}



