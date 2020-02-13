#include <Windows.h>
#include <stdio.h>

#include "Statistics.h"
#include "BubbleSort.h"
#include "SelectionSort.h"
#include "InsertionSort.h"
#include "HeapSort.h"

#define START_CASE 100
#define END_CASE 10000
#define STEP 100

VOID
SimpleTestCase()
{
	LPARRAY lpArray = CreateAscendingArray(10);
	if (NULL == lpArray)
	{
		printf("Running tests failed.");
		return;
	}

	ShuffleArray(lpArray);
	printf("Current array : \n");
	PrintArray(lpArray);
	printf("\nBubbleSort : \n");
	BubbleSort(lpArray, NULL, NULL);
	PrintArray(lpArray);
	printf("\n");

	ShuffleArray(lpArray);
	printf("Current array : \n");
	PrintArray(lpArray);
	printf("\nSelectionSort : \n");
	SelectionSort(lpArray, NULL, NULL);
	PrintArray(lpArray);
	printf("\n");

	ShuffleArray(lpArray);
	printf("Current array : \n");
	PrintArray(lpArray);
	printf("\nInsertionSort : \n");
	InsertionSort(lpArray, NULL, NULL);
	PrintArray(lpArray);
	printf("\n");

	ShuffleArray(lpArray);
	printf("Current array : \n");
	PrintArray(lpArray);
	printf("\nHeapSort : \n");
	HeapSort(lpArray, NULL, NULL);
	PrintArray(lpArray);
	printf("\n");
}


VOID
GetStatistics()
{
	GetSortingStatistics
	(
		BubbleSort,
		START_CASE,
		END_CASE,
		STEP,
		L"BubbleSort.out"
	);

	GetSortingStatistics
	(
		SelectionSort,
		START_CASE,
		END_CASE,
		STEP,
		L"SelectionSort.out"
	);

	GetSortingStatistics
	(
		InsertionSort,
		START_CASE,
		END_CASE,
		STEP,
		L"InsertionSort.out"
	);

	GetSortingStatistics
	(
		HeapSort,
		START_CASE,
		END_CASE,
		STEP,
		L"HeapSort.out"
	);
}

INT
main
(
	_In_opt_ LPCSTR* lpArgv,
	_In_ DWORD dwArgc
)
{
	UNREFERENCED_PARAMETER(lpArgv);
	UNREFERENCED_PARAMETER(dwArgc);

	SimpleTestCase();
	GetStatistics();

	return 0;
}