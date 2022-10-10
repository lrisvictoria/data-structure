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



}

int main()
{
	TestStack1();
	return 0;
}