#define _CRT_SECURE_NO_WARNINGS 1 

#include "Stack.h"

// top 为栈顶的下一个元素

//void StackInit(ST* ps)
//{
//	// 结构体一定不为空
//	assert(ps);
//
//	ps->a = (STDatatype*)malloc(sizeof(STDatatype) * 4);
//	if (ps->a == NULL)
//	{
//		perror("malloc fail");
//		exit(-1);
//	}
//	ps->capacity = 4;
//	ps->top = 0;
//}
//
//void StackDestroy(ST* ps)
//{
//	assert(ps);
//
//	free(ps->a);
//	ps->a = NULL;
//	ps->capacity = ps->top = 0;
//}
//
//void StackPush(ST* ps, STDatatype x)
//{
//	assert(ps);
//	
//	// 检查容量
//	if (ps->top == ps->capacity)
//	{
//		STDatatype* tmp = (STDatatype*)realloc(ps->a, sizeof(STDatatype) * ps->capacity * 2);
//		if (tmp == NULL)
//		{
//			perror("realloc fail");
//			exit(-1);
//		}
//		ps->a = tmp;
//		ps->capacity *= 2;
//	}
//	// 插入元素
//	// top 为栈顶的下一个元素
//	// 先插入再 ++ 
//	ps->a[ps->top++] = x;
//}
//
//void StackPop(ST* ps)
//{
//	assert(ps);
//
//	// 如果栈空，则不能删除
//	assert(!StackEmpty(ps));
//	ps->top--;
//}
//
//STDatatype StackTop(ST* ps)
//{
//	assert(ps);
//
//	assert(!StackEmpty(ps));
//
//	return ps->a[ps->top - 1];
//}
//
//bool StackEmpty(ST* ps)
//{
//	assert(ps);
//
//	return ps->top == 0;
//}
//
//int StackSize(ST* ps)
//{
//	assert(ps);
//
//	return ps->top;
//}

// top 为栈顶 初识值为 -1

void StackInit(ST* ps)
{
	// 结构体一定不为空
	assert(ps);

	ps->a = (STDatatype*)malloc(sizeof(STDatatype) * 4);
	if (ps->a == NULL)
	{
		perror("malloc fail");
		exit(-1);
	}
	ps->capacity = 4;
	ps->top = -1;
}

void StackDestroy(ST* ps)
{
	assert(ps);

	free(ps->a);
	ps->a = NULL;
	ps->capacity = ps->top = 0;
}

void StackPush(ST* ps, STDatatype x)
{
	assert(ps);

	// 检查容量
	// 此时 top 一开始为 -1，不能表示栈中元素的数目
	// top + 1 才是正确的

	if (ps->top + 1 == ps->capacity)
	{
		STDatatype* tmp = (STDatatype*)realloc(ps->a, sizeof(STDatatype) * ps->capacity * 2);
		if (tmp == NULL)
		{
			perror("realloc fail");
			exit(-1);
		}
		ps->a = tmp;
		ps->capacity *= 2;
	}
	// 插入元素
	// top 为栈顶元素
	// 先 ++ 再插入
	ps->a[++ps->top] = x;
}

void StackPop(ST* ps)
{
	assert(ps);

	// 如果栈空，则不能删除
	assert(!StackEmpty(ps));
	ps->top--;
}

STDatatype StackTop(ST* ps)
{
	assert(ps);

	assert(!StackEmpty(ps));

	return ps->a[ps->top];
}

bool StackEmpty(ST* ps)
{
	assert(ps);

	return ps->top == -1;
}

int StackSize(ST* ps)
{
	assert(ps);

	return ps->top + 1;
}