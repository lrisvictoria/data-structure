#define _CRT_SECURE_NO_WARNINGS 1 

#include "Stack.h"

// ��ʼ��
void StackInit(ST* ps)
{
	assert(ps);
	ps->a = NULL;
	ps->top = 0;// ps->top = -1;
	// topΪ0������
	ps->capacity = 0;
}

// ����ջ
void StackDestroy(ST* ps);

// ��ջ
void StackPush(ST* ps, STDataType x);

// ��ջ
void StackPop(ST* ps);

// ȡջ��������
STDataType StackTop(ST* ps);

// ����ջ�Ĵ�С
int StackSize(ST* ps);

// �ж�ջ���Ƿ���Ԫ��
bool StackEmpty(ST* ps);