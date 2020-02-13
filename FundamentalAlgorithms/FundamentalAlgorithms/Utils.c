#include "Utils.h"

VOID
SwapLongLong
(
	LONGLONG* lpFirstArg,
	LONGLONG* lpSecondArg
)
{
	LONGLONG llAuxiliary = *lpFirstArg;
	*lpFirstArg = *lpSecondArg;
	*lpSecondArg = llAuxiliary;
}