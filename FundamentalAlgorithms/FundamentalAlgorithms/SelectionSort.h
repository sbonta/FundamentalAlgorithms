#ifndef _SELECTION_SORT_H_
#define _SELECTION_SORT_H_

#include <Windows.h>

#include "Array.h"

VOID
SelectionSort
(
	_Inout_ LPARRAY lpArray,
	_Out_opt_ ULONGLONG* ullAssigments,
	_Out_opt_ ULONGLONG* ullComparisons
);

#endif // !_SELECTION_SORT_H_
