#ifndef _INSERTION_SORT_H_
#define _INSERTION_SORT_H_

#include <Windows.h>

#include "Array.h"

VOID
InsertionSort
(
	_Inout_ LPARRAY lpArray,
	_Out_opt_ ULONGLONG* ullAssigments,
	_Out_opt_ ULONGLONG* ullComparisons
);

#endif // !_INSERTION_SORT_H_
