#pragma once

#define TRUE		1
#define FALSE		0

typedef int			Data;

typedef struct Node 
{
	Data data;
	struct Node* next;
}Node;

typedef struct
{
	Node head;
}ListStack;

typedef ListStack	Stack;

void StackInit(Stack* pStack);
int SIsEmpty(Stack* pStack);

int SPush(Stack* pStack, Data pData);
int SPop(Stack* pStack, Data* pData);
int SPeek(Stack* pStack, Data* pData);