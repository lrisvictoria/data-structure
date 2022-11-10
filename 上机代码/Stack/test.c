#define _CRT_SECURE_NO_WARNINGS 1 

#include "Stack.h"

void TestST1()
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


	printf("%d\n", StackTop(&st));

}

int main()
{
	TestST1();
}