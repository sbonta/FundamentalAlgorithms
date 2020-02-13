#ifndef _BUBBLE_SORT_H_
#define _BUBBLE_SORT_H_

#include <Windows.h>

#include "Array.h"

VOID
BubbleSort
(
	_Inout_ LPARRAY lpArray,
	_Out_opt_ ULONGLONG* ullAssigments,
	_Out_opt_ ULONGLONG* ullComparisons
);

#endif // !_BUBBLE_SORT_H_
