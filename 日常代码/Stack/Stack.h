#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

typedef int STDataType;

typedef struct Stack
{
	STDataType* a;
	int top;// 栈顶位置
	int capacity;// 容量
}ST;

// 初始化
void StackInit(ST* ps);

// 销毁栈
void StackDestroy(ST* ps);

// 入栈
void StackPush(ST* ps, STDataType x);

// 出栈
void StackPop(ST* ps);

// 取栈顶的数据
STDataType StackTop(ST* ps);

// 计算栈的大小
int StackSize(ST* ps);

// 判断栈中是否有元素
bool StackEmpty(ST* ps);