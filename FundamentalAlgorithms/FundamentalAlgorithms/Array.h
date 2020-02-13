#ifndef _ARRAY_H_
#define _ARRAY_H_

#include <Windows.h>

typedef struct _ARRAY
{
	LONGLONG* Data;
	DWORD Size;
}ARRAY,
*LPARRAY;

_Must_inspect_result_
LPARRAY
CreateAscendingArray
(
	_In_ DWORD dwSize
);

_Must_inspect_result_
LPARRAY
CreateDescendingArray
(
	_In_ DWORD dwSize
);

_Must_inspect_result_
LPARRAY
CreateCustomArray
(
	_In_ LONGLONG* lpData,
	_In_ DWORD dwSize
);

VOID
ShuffleArray
(
	_Inout_ LPARRAY lpArray
);

VOID
DestroyArray
(
	_In_ LPARRAY lpArray
);

VOID
PrintArray
(
	_In_ LPARRAY lpArray
);

#endif // !_ARRAY_H_
