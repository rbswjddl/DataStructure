#include "Heap.h"

void HeapInit(Heap* pHeap)
{
	pHeap->numOfData = 0;
}

int HIsEmpty(Heap* pHeap)
{
	if (pHeap->numOfData == 0)
		return TRUE;
	else
		return FALSE;
}

int GetParentIdx(int idx)
{
	return idx / 2;
}

int GetLChildIdx(int idx)
{
	return idx * 2;
}

int GetRChildIdx(int idx)
{
	return idx * 2 + 1;
}

int GetHiPriChildIdx(Heap* pHeap, int idx)
{
	if (idx > pHeap->numOfData)
		return -1;

	if (pHeap->numOfData < GetLChildIdx(idx))
		return 0;
	else if (pHeap->numOfData == GetLChildIdx(idx))
		return GetLChildIdx(idx);
	else
	{
		int lIdx = GetLChildIdx(idx);
		int rIdx = GetRChildIdx(idx);

		if (pHeap->heapArr[lIdx].pr > pHeap->heapArr[rIdx].pr)
			return rIdx;
		else
			return lIdx;
	}
}

void HInsert(Heap* pHeap, HData data, Priority pr)
{
	HeapElem heapData = { pr, data };
	int insertIdx;
	int parentIdx;

	insertIdx = pHeap->numOfData + 1;
	while (insertIdx != 1)
	{
		parentIdx = GetParentIdx(insertIdx);

		if (pHeap->heapArr[parentIdx].pr < pr)
			break;

		pHeap->heapArr[insertIdx] = pHeap->heapArr[parentIdx];
		insertIdx = parentIdx;
	}

	pHeap->heapArr[insertIdx] = heapData;
	pHeap->numOfData++;
}

HData HDelete(Heap* pHeap)
{
	HData retData = pHeap->heapArr[1].data;
	
	int childIdx = 1;
	int parentIdx = 1;
	HeapElem tempData = pHeap->heapArr[pHeap->numOfData];

	while (childIdx = GetHiPriChildIdx(pHeap, parentIdx))
	{
		if (tempData.pr <= pHeap->heapArr[childIdx].pr)
			break;

		pHeap->heapArr[parentIdx] = pHeap->heapArr[childIdx];
		parentIdx = childIdx;
	}

	pHeap->heapArr[parentIdx] = tempData;
	pHeap->numOfData--;
	return retData;
}