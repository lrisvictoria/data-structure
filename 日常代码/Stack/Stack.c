#define _CRT_SECURE_NO_WARNINGS 1 

#include "Stack.h"

// 初始化
void StackInit(ST* ps)
{
	assert(ps);
	ps->a = NULL;
	ps->top = 0;// ps->top = -1;
	// top为0，代表
	ps->capacity = 0;
}

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