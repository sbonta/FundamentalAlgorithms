#ifndef _STATISTICS_H_
#define _STATISTICS_H_

#include <Windows.h>

#include "Array.h"

#define NUMBER_OF_THREADS 32

typedef struct _PARAMETER
{
	_In_ VOID(*SortFunction)(LPARRAY lpArray, ULONGLONG* ullAssigments, ULONGLONG* ullComparisons);
	LPARRAY Array;
	ULONGLONG* ullAssigments;
	ULONGLONG* ullComparisons;
}PARAMETER,
*LPPARAMETER;

VOID
GetSortingStatistics
(
	_In_ VOID(*SortFunction)(LPARRAY lpArray, ULONGLONG* ullAssigments, ULONGLONG* ullComparisons),
	_In_ DWORD dwStartCase,
	_In_ DWORD dwEndCase,
	_In_ DWORD dwStep,
	_In_ LPCWSTR lpOutputFileName
);

#endif // !_STATISTICS_H_
