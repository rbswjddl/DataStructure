#include<stdio.h>
#include "InfixToPostfix.h"
#include "PostCalculator.h"

int main()
{
	char exp[] = "1+2*4*(1-2)";

	ConvToRPNExp(exp);

	int result = EvalRPNExp(exp);
	printf("%d\n", result);
}