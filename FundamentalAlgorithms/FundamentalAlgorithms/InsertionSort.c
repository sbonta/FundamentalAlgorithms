#include "InsertionSort.h"

VOID
InsertionSort
(
	_Inout_ LPARRAY lpArray,
	_Out_opt_ ULONGLONG* ullAssigments,
	_Out_opt_ ULONGLONG* ullComparisons
)
{
	LONGLONG llKey = 0;
	LONGLONG dwPosition = 0;
	if (NULL != ullAssigments)
	{
		*ullAssigments = 0;
	}
	if (NULL != ullComparisons)
	{
		*ullComparisons = 0;
	}

	for (DWORD i = 1; i < lpArray->Size; i++)
	{
		if (NULL != ullAssigments)
		{
			*ullAssigments = *ullAssigments + 1;
		}
		llKey = lpArray->Data[i];
		dwPosition = i - 1;
		
		while ((dwPosition >= 0) && (lpArray->Data[dwPosition] > llKey))
		{
			if (NULL != ullComparisons)
			{
				*ullComparisons = *ullComparisons + 1;
			}
			if (NULL != ullAssigments)
			{
				*ullAssigments = *ullAssigments + 1;
			}
			lpArray->Data[dwPosition + 1] = lpArray->Data[dwPosition];
			dwPosition = dwPosition - 1;
		}

		if (NULL != ullAssigments)
		{
			*ullAssigments = *ullAssigments + 1;
		}
		lpArray->Data[dwPosition + 1] = llKey;
	}
}