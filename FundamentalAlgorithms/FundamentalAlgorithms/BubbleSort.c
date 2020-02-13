#include "BubbleSort.h"
#include "Utils.h"

VOID
BubbleSort
(
	_Inout_ LPARRAY lpArray,
	_Out_opt_ ULONGLONG* ullAssigments,
	_Out_opt_ ULONGLONG* ullComparisons
)
{
	BOOL isSorted = FALSE;

	if (NULL != ullAssigments)
	{
		*ullAssigments = 0;
	}
	if (NULL != ullComparisons)
	{
		*ullComparisons = 0;
	}

	isSorted = FALSE;
	for (DWORD i = 0; (i < lpArray->Size - 1) && (!isSorted); i++)
	{
		isSorted = TRUE;
		for (DWORD j = 0; j < lpArray->Size - i - 1; j++)
		{
			if (NULL != ullComparisons)
			{
				*ullComparisons = *ullComparisons + 1;
			}
			if (lpArray->Data[j] > lpArray->Data[j + 1])
			{
				if (NULL != ullAssigments)
				{
					*ullAssigments = *ullAssigments + 3;
				}
				SwapLongLong(&lpArray->Data[j], &lpArray->Data[j + 1]);
				isSorted = FALSE;
			}
		}
	}


}