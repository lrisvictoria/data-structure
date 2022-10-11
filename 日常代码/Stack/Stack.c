#define _CRT_SECURE_NO_WARNINGS 1 

#include "Stack.h"

// 初始化
void StackInit(ST* ps)
{
	assert(ps);
	ps->a = NULL;
	ps->top = 0;// ps->top = -1;
	// top为0，代表指向栈顶的下一个元素
	// top为1，代表指向栈顶
	ps->capacity = 0;
}

// 销毁栈
void StackDestroy(ST* ps)
{
	assert(ps);
	free(ps->a);
	ps->a = NULL;
	ps->capacity = 0;
	ps->top = 0;
}

// 入栈
void StackPush(ST* ps, STDataType x)
{
	assert(ps);

	if (ps->top == ps->capacity)
	{
		int newcapacity = (ps->capacity == 0 ? 4 : ps->capacity * 2);

		STDataType* tmp = (STDataType*)realloc(ps->a, sizeof(STDataType) * newcapacity);
		if (tmp == NULL)
		{
			printf("realloc fail\n");
			exit(-1);
		}
		else
		{
			ps->a = tmp;
			ps->capacity = newcapacity;
		}
	}
	
	ps->a[ps->top] = x;
	ps->top++;
}

// 出栈
void StackPop(ST* ps)
{
	assert(ps);

	assert(!StackEmpty(ps));
	ps->top--;
}

// 取栈顶的数据
STDataType StackTop(ST* ps)
{
	assert(ps);
	assert(!StackEmpty(ps));
	
	return ps->a[ps->top - 1];
}

// 计算栈的大小
int StackSize(ST* ps)
{
	assert(ps);

	return ps->top;
}

// 判断栈中是否有元素
bool StackEmpty(ST* ps)
{
	assert(ps);

	return ps->top == 0;
	// 栈中无元素
	// 返回真，！StackEmpty为假
	// 栈中有元素
	// 返回假，! StackEmpty为真
}