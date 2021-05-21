#include "Heap.h"

void HeapInit(Heap* pHeap, PriorityComp pc)
{
	pHeap->numOfData = 0;
	pHeap->comp = pc;
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

		
		if (pHeap->comp(pHeap->heapArr[lIdx], pHeap->heapArr[rIdx]) < 0)
			return lIdx;
		else
			return rIdx;
		
		
	}
}

void HInsert(Heap* pHeap, HData data)
{
	HData heapData = data;
	int insertIdx;
	int parentIdx;

	insertIdx = pHeap->numOfData + 1;
	while (insertIdx != 1)
	{
		parentIdx = GetParentIdx(insertIdx);

		if (pHeap->comp(pHeap->heapArr[parentIdx], heapData) < 0)
			break;

		pHeap->heapArr[insertIdx] = pHeap->heapArr[parentIdx];
		insertIdx = parentIdx;
	}

	pHeap->heapArr[insertIdx] = heapData;
	pHeap->numOfData++;
}

HData HDelete(Heap* pHeap)
{
	HData retData = pHeap->heapArr[1];
	
	int childIdx = 1;
	int parentIdx = 1;
	HData tempData = pHeap->heapArr[pHeap->numOfData];

	while (childIdx = GetHiPriChildIdx(pHeap, parentIdx))
	{
		if (pHeap->comp(tempData, pHeap->heapArr[childIdx]) <= 0)
			break;

		pHeap->heapArr[parentIdx] = pHeap->heapArr[childIdx];
		parentIdx = childIdx;
	}

	pHeap->heapArr[parentIdx] = tempData;
	pHeap->numOfData--;
	return retData;
}