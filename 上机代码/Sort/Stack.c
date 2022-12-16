#define _CRT_SECURE_NO_WARNINGS 1 

#include "Stack.h"

// top Ϊջ������һ��Ԫ��

//void StackInit(ST* ps)
//{
//	// �ṹ��һ����Ϊ��
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
//	// �������
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
//	// ����Ԫ��
//	// top Ϊջ������һ��Ԫ��
//	// �Ȳ����� ++ 
//	ps->a[ps->top++] = x;
//}
//
//void StackPop(ST* ps)
//{
//	assert(ps);
//
//	// ���ջ�գ�����ɾ��
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

// top Ϊջ�� ��ʶֵΪ -1

void StackInit(ST* ps)
{
	// �ṹ��һ����Ϊ��
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

	// �������
	// ��ʱ top һ��ʼΪ -1�����ܱ�ʾջ��Ԫ�ص���Ŀ
	// top + 1 ������ȷ��

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
	// ����Ԫ��
	// top Ϊջ��Ԫ��
	// �� ++ �ٲ���
	ps->a[++ps->top] = x;
}

void StackPop(ST* ps)
{
	assert(ps);

	// ���ջ�գ�����ɾ��
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