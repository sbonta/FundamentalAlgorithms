#include "HeapSort.h"
#include "Utils.h"

VOID
Heapify
(
	LPARRAY lpArray,
	DWORD dwIndex,
	_Inout_opt_ ULONGLONG* ullAssigments,
	_Inout_opt_ ULONGLONG* ullComparisons
)
{
	DWORD dwLargest = dwIndex;
	DWORD dwLeft = dwIndex * 2 + 1;
	DWORD dwRight = dwIndex * 2 + 2;

	if (dwLeft < lpArray->Size)
	{
		if (NULL != ullComparisons)
		{
			*ullComparisons = *ullComparisons + 1;
		}
		if (lpArray->Data[dwLeft] > lpArray->Data[dwLargest])
		{
			dwLargest = dwLeft;
		}
	}
	if (dwRight < lpArray->Size)
	{
		if (NULL != ullComparisons)
		{
			*ullComparisons = *ullComparisons + 1;
		}
		if (lpArray->Data[dwRight] > lpArray->Data[dwLargest])
		{
			dwLargest = dwRight;
		}
	}

	if (dwLargest != dwIndex)
	{
		if (NULL != ullAssigments)
		{
			*ullAssigments = *ullAssigments + 3;
		}
		SwapLongLong(&lpArray->Data[dwLargest], &lpArray->Data[dwIndex]);
		Heapify(lpArray, dwLargest, ullAssigments, ullComparisons);
	}
}

VOID
HeapSort
(
	_Inout_ LPARRAY lpArray,
	_Out_opt_ ULONGLONG* ullAssigments,
	_Out_opt_ ULONGLONG* ullComparisons
)
{
	DWORD dwSize = 0;
	if (NULL != ullAssigments)
	{
		*ullAssigments = 0;
	}
	if (NULL != ullComparisons)
	{
		*ullComparisons = 0;
	}

	for (LONGLONG i = lpArray->Size / 2 - 1; i >= 0; i--)
	{
		Heapify(lpArray, (DWORD)i, ullAssigments, ullComparisons);
	}
	dwSize = lpArray->Size;
	for (LONGLONG i = dwSize - 1; i >= 0; i--)
	{
		SwapLongLong(&lpArray->Data[0], &lpArray->Data[i]);
		lpArray->Size = lpArray->Size - 1;
		Heapify(lpArray, 0, ullAssigments, ullComparisons);
	}
	lpArray->Size = dwSize;
}