#include<stdio.h>
#include<stdlib.h>
#include "ListStack.h"

int main()
{
	Stack stack;
	int iData;

	StackInit(&stack);

	for (int iCount = 0; iCount < 100; iCount++)
	{
		if (SPush(&stack, iCount) == FALSE)
		{
			printf("Fail to Push\n");
			return;
		}
	}

	while (!SIsEmpty(&stack))
	{
		if (SPop(&stack, &iData) == FALSE)
		{
			printf("Fail to Pop\n");
			return;
		}
		printf("%d ", iData);
	}

	return 0;
}