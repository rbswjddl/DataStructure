#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include "ListStack.h"

int GetOpPrec(char op)
{
	switch (op)
	{
	case '(': return 1;
	case '+': case '-': return 3;
	case '*': case '/': return 5;
	}

	return -1;
}

int WhoOpPrec(char op1, char op2)
{
	int iOpPrec1 = GetOpPrec(op1);
	int iOpPrec2 = GetOpPrec(op2);

	return iOpPrec1 - iOpPrec2;
}

void ConvToRPNExp(char exp[])
{
	Stack stack;
	int iStrLen = strlen(exp);
	char* pTempStr = (char*)malloc(iStrLen + 1);

	int iTempIdx = 0;
	int iToken, iData;

	StackInit(&stack);

	for (int idx = 0; idx < iStrLen; idx++)
	{
		iToken = exp[idx];

		if (isdigit(iToken))
		{
			pTempStr[iTempIdx++] = iToken;
		}
		else
		{
			switch (iToken)
			{
			case '(':
				SPush(&stack, iToken);
				break;
			case ')':
				while (1)
				{
					SPop(&stack, &iData);
					if (iData == '(') break;

					pTempStr[iTempIdx++] = iData;
				}
				break;
			case '+': case '-':
			case '*': case '/':
				while (!SIsEmpty(&stack))
				{
					SPeek(&stack, &iData);
					if (WhoOpPrec(iData, iToken) < 0) break;

					SPop(&stack, &iData);
					pTempStr[iTempIdx++] = iData;
				}
				SPush(&stack, iToken);
			}
		}
	}

	while (!SIsEmpty(&stack))
	{
		SPop(&stack, &iData);
		pTempStr[iTempIdx++] = iData;
	}

	pTempStr[iTempIdx++] = NULL;
	memcpy(exp, pTempStr, iTempIdx);
	free(pTempStr);
}