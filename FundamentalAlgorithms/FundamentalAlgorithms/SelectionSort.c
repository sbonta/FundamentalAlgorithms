#include "SelectionSort.h"
#include "Utils.h"

VOID
SelectionSort
(
	_Inout_ LPARRAY lpArray,
	_Out_opt_ ULONGLONG* ullAssigments,
	_Out_opt_ ULONGLONG* ullComparisons
)
{
	DWORD minIndex = 0;

	if (NULL != ullAssigments)
	{
		*ullAssigments = 0;
	}
	if (NULL != ullComparisons)
	{
		*ullComparisons = 0;
	}

	for (DWORD i = 0; i < lpArray->Size - 1; i++)
	{
		minIndex = i;

		for (DWORD j = i + 1; j < lpArray->Size; j++)
		{
			if(NULL != ullComparisons)
			{
				*ullComparisons = *ullComparisons + 1;
			}
			if (lpArray->Data[j] < lpArray->Data[minIndex])
			{
				minIndex = j;
			}
		}

		if (minIndex != i)
		{
			if (NULL != ullAssigments)
			{
				*ullAssigments = *ullAssigments + 3;
			}
			SwapLongLong(&lpArray->Data[i], &lpArray->Data[minIndex]);
		}
	}

}