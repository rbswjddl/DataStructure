#pragma once

#define HEAP_LEN	100
#define TRUE		1
#define FALSE		0

typedef char HData;
typedef int Priority;
typedef int PriorityComp(HData d1, HData d2);

typedef struct Heap
{
	PriorityComp* comp;
	int numOfData;
	HData heapArr[HEAP_LEN];
}Heap;

void HeapInit(Heap* pHeap, PriorityComp pc);
int HIsEmpty(Heap* pHeap);

void HInsert(Heap* pHeap, HData data);
HData HDelete(Heap* pHeap);
