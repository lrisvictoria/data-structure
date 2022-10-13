#pragma once
/*
* ����������Ҫ���߳����ݣ�����ʹ��˳�����Ų������ʱЧ�ʵ�
* ��������ʵ����ʽ����
*/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

typedef int QDataType;

typedef struct QueueNode
{
	struct QueueNode* next;
	QDataType data;
}QueueNode;

typedef struct Queue
{
	QueueNode* head;
	QueueNode* tail;
}Queue;

// ��ʼ��
void QueueInit(Queue* pq);

// ����
void QueueDestroy(Queue* pq);

// ��β����
void QueuePush(Queue* pq, QDataType x);

// ��ͷɾ��
void QueuePop(Queue* pq);

// ȡ��ͷ����
QDataType QueueFront(Queue* pq);

// ȡ��β����
QDataType QueueBack(Queue* pq);

// ������д�С
int QueueSize(Queue* pq);

// �ж϶����Ƿ�Ϊ��
bool QueueEmpty(Queue* pq);
