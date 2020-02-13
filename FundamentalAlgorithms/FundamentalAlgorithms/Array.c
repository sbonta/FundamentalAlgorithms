#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "Array.h"
#include "Utils.h"

_Must_inspect_result_
LPARRAY
CreateAscendingArray
(
	_In_ DWORD dwSize
)
{
	BOOL bStatus = TRUE;
	LPARRAY lpArray = NULL;

	if (0 == dwSize)
	{
		bStatus = FALSE;
		goto Cleanup;
	}

	lpArray = (LPARRAY)calloc(1, sizeof(ARRAY));
	if (NULL == lpArray)
	{
		bStatus = FALSE;
		goto Cleanup;
	}
	lpArray->Data = (LONGLONG*)calloc(dwSize, sizeof(LONGLONG));
	if (NULL == lpArray->Data)
	{
		bStatus = FALSE;
		goto Cleanup;
	}

	for (DWORD i = 0; i < dwSize; i++)
	{
		lpArray->Data[i] = i;
	}
	lpArray->Size = dwSize;

Cleanup:

	if (!bStatus)
	{
		if (NULL != lpArray)
		{
			if (NULL != lpArray->Data)
			{
				free(lpArray->Data);
			}
			free(lpArray);
		}
		lpArray = NULL;
	}
	return lpArray;
}

_Must_inspect_result_
LPARRAY
CreateDescendingArray
(
	_In_ DWORD dwSize
)
{
	BOOL bStatus = TRUE;
	LPARRAY lpArray = NULL;

	if (0 == dwSize)
	{
		bStatus = FALSE;
		goto Cleanup;
	}

	lpArray = (LPARRAY)calloc(1, sizeof(ARRAY));
	if (NULL == lpArray)
	{
		bStatus = FALSE;
		goto Cleanup;
	}
	lpArray->Data = (LONGLONG*)calloc(dwSize, sizeof(LONGLONG));
	if (NULL == lpArray->Data)
	{
		bStatus = FALSE;
		goto Cleanup;
	}

	for (DWORD i = 0; i < dwSize; i++)
	{
		lpArray->Data[i] = dwSize - i - 1;
	}
	lpArray->Size = dwSize;

Cleanup:

	if (!bStatus)
	{
		if (NULL != lpArray)
		{
			if (NULL != lpArray->Data)
			{
				free(lpArray->Data);
			}
			free(lpArray);
		}
		lpArray = NULL;
	}
	return lpArray;
}

_Must_inspect_result_
LPARRAY
CreateCustomArray
(
	_In_ LONGLONG* lpData,
	_In_ DWORD dwSize
)
{
	LPARRAY lpArray = (LPARRAY)calloc(1, sizeof(ARRAY));
	if (NULL == lpArray)
	{
		return NULL;
	}

	lpArray->Data = lpData;
	lpArray->Size = dwSize;

	return lpArray;
}

VOID
ShuffleArray
(
	_Inout_ LPARRAY lpArray
)
{
	for (DWORD i = lpArray->Size - 1; i > 0; i--)
	{
		DWORD j = rand() % (i + 1);
		SwapLongLong(&lpArray->Data[i], &lpArray->Data[j]);
	}
}

VOID
DestroyArray
(
	_In_ LPARRAY lpArray
)
{
	if (NULL != lpArray)
	{
		if (NULL != lpArray->Data)
		{
			free(lpArray->Data);
		}
		free(lpArray);
	}
}

VOID
PrintArray
(
	_In_ LPARRAY lpArray
)
{
	for (DWORD i = 0; i < lpArray->Size; i++)
	{
		printf("%llu ", lpArray->Data[i]);
	}
}