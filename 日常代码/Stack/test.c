#define _CRT_SECURE_NO_WARNINGS 1 

#include "Stack.h"

void TestStack1()
{
	ST st;
	StackInit(&st);
	StackPush(&st, 1);
	StackPush(&st, 2);
	StackPush(&st, 3);
	StackPush(&st, 4);
	StackPush(&st, 5);

	StackPop(&st);
	StackPop(&st);
	StackPop(&st);
	StackPop(&st);
	StackPop(&st);
	//StackPop(&st);

}

void TestStack2()
{
	ST st;
	StackInit(&st);
	StackPush(&st, 1);
	StackPush(&st, 2);
	
	printf("%d ", StackTop(&st));// ³öÕ»2
	StackPop(&st);

	printf("%d ", StackTop(&st));// ³öÕ»1
	StackPop(&st);

	StackPush(&st, 3);
	StackPush(&st, 4);
	StackPush(&st, 5);

	while (!StackEmpty(&st))
	{
		printf("%d ", StackTop(&st));
		StackPop(&st);
	}

}
int main()
{
	//TestStack1();
	TestStack2();
	return 0;
}