#define _CRT_SECURE_NO_WARNINGS 1 

#include "Stack.h"

// ��ʼ��
void StackInit(ST* ps)
{
	assert(ps);
	ps->a = NULL;
	ps->top = 0;// ps->top = -1;
	// topΪ0������ָ��ջ������һ��Ԫ��
	// topΪ1������ָ��ջ��
	ps->capacity = 0;
}

// ����ջ
void StackDestroy(ST* ps)
{
	assert(ps);
	free(ps->a);
	ps->a = NULL;
	ps->capacity = 0;
	ps->top = 0;
}

// ��ջ
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

// ��ջ
void StackPop(ST* ps)
{
	assert(ps);

	assert(!StackEmpty(ps));
	ps->top--;
}

// ȡջ��������
STDataType StackTop(ST* ps)
{
	assert(ps);
	assert(!StackEmpty(ps));
	
	return ps->a[ps->top - 1];
}

// ����ջ�Ĵ�С
int StackSize(ST* ps)
{
	assert(ps);

	return ps->top;
}

// �ж�ջ���Ƿ���Ԫ��
bool StackEmpty(ST* ps)
{
	assert(ps);

	return ps->top == 0;
	// ջ����Ԫ��
	// �����棬��StackEmptyΪ��
	// ջ����Ԫ��
	// ���ؼ٣�! StackEmptyΪ��
}