#pragma once

#define HEAP_LEN	100
#define TRUE		1
#define FALSE		0

typedef char HData;
typedef int Priority;

typedef struct
{
	Priority pr;
	HData data;
}HeapElem;

typedef struct Heap
{
	int numOfData;
	HeapElem heapArr[HEAP_LEN];
}Heap;

void HeapInit(Heap* pHeap);
int HIsEmpty(Heap* pHeap);

void HInsert(Heap* pHeap, HData data, Priority pr);
HData HDelete(Heap* pHeap);
