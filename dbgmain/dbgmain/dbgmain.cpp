// dbgmain.cpp : 定义 DLL 应用程序的导出函数。
//

#include "stdafx.h"

DECLARE_API(read)
{
	/*
	ULONG cb;
	ULONG64 Address;
	ULONG Buffer[4];

	Address = GetExpression(args);

	// Read and display first 4 dwords at Address
	if (ReadMemory(Address, &Buffer, sizeof(Buffer), &cb) && cb == sizeof(Buffer)) {
		dprintf("%1641x: %081x %081x %081x %081x\n\n", Address,
			Buffer[0], Buffer[1], Buffer[2], Buffer[3]);
	}
	*/
	dprintf("read read read read read read \n");
}

//	A built-in help for the extension dll
DECLARE_API(help)
{
	dprintf("Help for extension dll simple.dll\n"
		"	read <addr>		- It reads and dumps 4 dwords at <addr>\n"
		"	help			- Shows this help\n"
	);
}


	
