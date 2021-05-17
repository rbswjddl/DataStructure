#include "ListStack.h"
#include<stdio.h>

void StackInit(Stack* pStack)
{
	pStack->head.next = NULL;
}
int SIsEmpty(Stack* pStack)
{
	if (pStack->head.next == NULL)
		return TRUE;

	return FALSE;
}

int SPush(Stack* pStack, Data data)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	
	newNode->next = pStack->head.next;
	pStack->head.next = newNode;
	return TRUE;
}

int SPop(Stack* pStack, Data* pData)
{
	if (SIsEmpty(pStack))
		return FALSE;

	Node* deleteNode = pStack->head.next;
	pStack->head.next = deleteNode->next;

	*pData = deleteNode->data;
	free(deleteNode);

	return TRUE;
}

int SPeek(Stack* pStack, Data* pData)
{
	if (SIsEmpty(pStack))
		return FALSE;

	*pData = pStack->head.next->data;
	return TRUE;
}