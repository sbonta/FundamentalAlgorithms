#include <stdio.h>

#include "Statistics.h"


VOID
CallerFunction
(
	LPVOID lpData
)
{
	LPPARAMETER lpParameter = (LPPARAMETER)lpData;
	lpParameter->SortFunction
	(
		lpParameter->Array,
		lpParameter->ullAssigments,
		lpParameter->ullComparisons
	);
}

VOID
GetSortingStatistics
(
	_In_ VOID(*SortFunction)(LPARRAY lpArray, ULONGLONG* ullAssigments, ULONGLONG* ullComparisons),
	_In_ DWORD dwStartCase,
	_In_ DWORD dwEndCase,
	_In_ DWORD dwStep,
	_In_ LPCWSTR lpOutputFileName
)
{
	HANDLE hTreads[NUMBER_OF_THREADS] = { INVALID_HANDLE_VALUE };
	ULONGLONG ullAssigments[NUMBER_OF_THREADS] = { 0 };
	ULONGLONG ullComparisons[NUMBER_OF_THREADS] = { 0 };
	PARAMETER parameters[NUMBER_OF_THREADS] = { 0 };
	LPARRAY lpArrays[NUMBER_OF_THREADS] = { 0 };
	FILE* outputFile = NULL;
	DWORD dwNumberOfRunningThreads = 0;

	_wfopen_s(&outputFile, lpOutputFileName, L"w");
	if (NULL == outputFile)
	{
		printf("Error opening output file");
		return;
	}

	for (DWORD i = dwStartCase; i <= dwEndCase;)
	{
		printf("%u\n", i);
		dwNumberOfRunningThreads = 0;

		for (DWORD j = 0; j < NUMBER_OF_THREADS; j++)
		{
			hTreads[j] = INVALID_HANDLE_VALUE;
			ullAssigments[j] = 0;
			ullComparisons[j] = 0;
			lpArrays[j] = NULL;
		}

		for (DWORD j = 0; (j < NUMBER_OF_THREADS) && (i <= dwEndCase); j++)
		{
			lpArrays[j] = CreateAscendingArray(i);
			if (NULL == lpArrays[j])
			{
				printf("Get Statistics Function Failed, memory allocation failure");
				return;
			}
			ShuffleArray(lpArrays[j]);
			parameters[j].SortFunction = SortFunction;
			parameters[j].Array = lpArrays[j];
			parameters[j].ullAssigments = &ullAssigments[j];
			parameters[j].ullComparisons = &ullComparisons[j];

			i = i + dwStep;
			dwNumberOfRunningThreads = dwNumberOfRunningThreads + 1;
		}

		for (DWORD j = 0; j < dwNumberOfRunningThreads; j++)
		{
			hTreads[j] = CreateThread
			(
				NULL,
				0,
				(LPTHREAD_START_ROUTINE)CallerFunction,
				&parameters[j],
				0,
				NULL
			);
		}

		WaitForMultipleObjects
		(
			dwNumberOfRunningThreads,
			hTreads,
			TRUE,
			INFINITE
		);

		for (DWORD j = 0; j < dwNumberOfRunningThreads; j++)
		{
			fprintf_s
			(
				outputFile,
				"Case : %u, Assigments : %llu, Comparisons : %llu\n",
				i - (dwNumberOfRunningThreads - j) * dwStep,
				ullAssigments[j],
				ullComparisons[j]
			);

			DestroyArray(lpArrays[j]);
		}
	}

	fclose(outputFile);
}