#define _CRT_SECURE_NO_WARNINGS 1

#include "Queue.h"

void QueueInit(Queue* pq)
{
	assert(pq);

	pq->head = pq->tail = NULL;
	pq->sz = 0;
}

void QueueDestroy(Queue* pq)
{
	assert(pq);
	
	QNode* cur = pq->head;

	while (cur)
	{
		QNode* next = cur->next;
		free(cur);
		cur = cur->next;
	}

	pq->head = pq->tail = NULL;
	pq->sz = 0;
}

// 尾插
void QueuePush(Queue* pq, QDataType x)
{
	assert(pq);

	QNode* newnode = (QNode*)malloc(sizeof(QNode));
	if (newnode == NULL)
	{
		perror("malloc fail");
		exit(-1);
	}
	else
	{
		newnode->data = x;
		newnode->next = NULL;
	}

	// 尾插
	if (pq->tail == NULL)
	{
		pq->head = pq->tail = newnode;
	}
	else
	{
		pq->tail->next = newnode;
		pq->tail = pq->tail->next;
	}

	pq->sz++;
}

void QueuePop(Queue* pq)
{
	assert(pq);

	assert(!QueueEmpty(pq));
	// 一个节点时删除的特殊情况
	// 需要将头尾都变为空
	if (pq->head->next == NULL)
	{
		free(pq->head);
		pq->head = pq->tail = NULL;
	}
	else
	{
		QNode* newhead = pq->head->next;
		free(pq->head);
		pq->head = newhead;
	}
	
	pq->sz--;
}

QDataType QueueFront(Queue* pq)
{
	assert(pq);
	assert(!QueueEmpty(pq));

	return pq->head->data;
}

QDataType QueueBack(Queue* pq)
{
	assert(pq);
	assert(!QueueEmpty(pq));

	return pq->tail->data;
}

bool QueueEmpty(Queue* pq)
{
	assert(pq);

	return pq->head == NULL && pq->tail == NULL;
}

int QueueSize(Queue* pq)
{
	assert(pq);

	/*QNode* cur = pq->head;
	int size = 0;
	while (cur)
	{
		cur = cur->next;
		++size;
	}
	return size;*/

	return pq->sz;
}