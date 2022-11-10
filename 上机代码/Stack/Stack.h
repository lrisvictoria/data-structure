#pragma once

#include <stdbool.h>
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

typedef int STDatatype;

typedef struct Stack
{
	STDatatype* a;
	int capacity;
	int top;   // 初始为0，表示栈顶位置下一个位置下标
}ST;

void StackInit(ST* ps);
void StackDestroy(ST* ps);
void StackPush(ST* ps, STDatatype x);
void StackPop(ST* ps);
STDatatype StackTop(ST* ps);

bool StackEmpty(ST* ps);
int StackSize(ST* ps);
