#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

typedef int STDataType;

typedef struct Stack
{
	STDataType* a;
	int top;// ջ��λ��
	int capacity;// ����
}ST;

// ��ʼ��
void StackInit(ST* ps);

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