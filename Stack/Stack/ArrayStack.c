//#include "ArrayStack.h"
//
//void StackInit(Stack* pStack)
//{
//	pStack->top = -1;
//}
//
//int SIsEmpty(Stack* pStack)
//{
//	if (pStack->top == -1)
//		return TRUE;
//	
//	return FALSE;
//}
//
//int SPush(Stack* pStack, Data data)
//{
//	if (pStack->top + 1 >= STACK_LEN)
//		return FALSE;
//
//	pStack->top++;
//	pStack->stack[pStack->top] = data;
//
//	return TRUE;
//}
//
//int SPop(Stack* pStack, Data* pData)
//{
//	if (SIsEmpty(pStack))
//		return FALSE;
//
//	*pData = pStack->stack[pStack->top];
//	pStack->top--;
//	return TRUE;
//}
//
//int SPeek(Stack* pStack, Data* pData)
//{
//	if (pStack->top == -1)
//		return FALSE;
//
//	*pData = pStack->stack[pStack->top];
//	return TRUE;
//}