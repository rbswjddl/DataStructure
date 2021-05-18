#include "ListStack.h"
#include<string.h>
#include<ctype.h>

int GetOpResult(char op, char op1, char op2)
{
	switch (op)
	{
	case '+': return op1 + op2;
	case '-': return op1 - op2;
	case '*': return op1 * op2;
	case '/': return op1 / op2;
	}
}

int EvalRPNExp(char exp[])
{
	Stack stack;
	int iLen = strlen(exp);
	int i, iToken, op1, op2;
	int iData;

	StackInit(&stack);

	for (i = 0; i < iLen; i++)
	{
		iToken = exp[i];
		
		if (isdigit(iToken))
		{
			SPush(&stack, iToken - '0');
		}
		else
		{
			SPop(&stack, &op2);
			SPop(&stack, &op1);
			SPush(&stack, GetOpResult(iToken, op1, op2));
		}
	}
	
	SPop(&stack, &iData);
	
	return iData;
}