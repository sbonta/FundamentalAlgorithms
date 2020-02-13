#ifndef _HEAP_SORT_H_
#define _HEAP_SORT_H_

#include <Windows.h>

#include "Array.h"

VOID
HeapSort
(
	_Inout_ LPARRAY lpArray,
	_Out_opt_ ULONGLONG* ullAssigments,
	_Out_opt_ ULONGLONG* ullComparisons
);

#endif // !_HEAP_SORT_H_
