#define _CRT_SECURE_NO_WARNINGS 1 

#include "Queue.h"

// ��ʼ��
void QueueInit(Queue* pq)
{
	assert(pq);

	pq->head = NULL;
	pq->tail = NULL;
}

// ����
void QueueDestroy(Queue* pq)
{
	assert(pq);
	
	QueueNode* cur = pq->head;
	while (cur != NULL)
	{
		QueueNode* next = cur->next;
		free(cur);
		cur = next;
	}
	pq->head = pq->tail = NULL;
}

// ��β����
void QueuePush(Queue* pq, QDataType x)
{
	assert(pq);
	QueueNode* newnode = (QueueNode*)malloc(sizeof(QueueNode));
	if (newnode == NULL)
	{
		perror("QueuePush");
		exit(-1);
	}
	newnode->data = x;
	newnode->next = NULL;
	
	if (pq->head == NULL)
	{
		pq->head = pq->tail = newnode;
	}
	else
	{
		pq->tail->next = newnode;
		pq->tail = newnode;
	}
}

// ��ͷɾ��
void QueuePop(Queue* pq)
{
	assert(pq);
	assert(!QueueEmpty(pq));// �ж϶����Ƿ�Ϊ��
	 
	QueueNode* next = pq->head->next;
	free(pq->head);
	pq->head = next;

	// �ж����һ��Ԫ���Ƿ�ɾ��
	// ��β�ÿշ�ֹҰָ��
	if (pq->head == NULL)
	{
		pq->head = pq->tail = NULL;
	}
}

// ȡ��ͷ����
QDataType QueueFront(Queue* pq)
{
	assert(pq);
	assert(!QueueEmpty(pq));

	return pq->head->data;
}

// ȡ��β����
QDataType QueueBack(Queue* pq)
{
	assert(pq);
	assert(!QueueEmpty(pq));

	return pq->tail->data;
}

// ������д�С
int QueueSize(Queue* pq)
{
	assert(pq);

	int size = 0;
	QueueNode* cur = pq->head;

	while (cur)
	{
		size++;
		cur = cur->next;
	}
	
	return size;
}

// �ж϶����Ƿ�Ϊ��
bool QueueEmpty(Queue* pq)
{
	assert(pq);
	
	// ͷΪ�գ�˵������������
	return pq->head == NULL;
}