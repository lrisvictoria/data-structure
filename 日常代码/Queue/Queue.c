#define _CRT_SECURE_NO_WARNINGS 1 

#include "Queue.h"

// 初始化
void QueueInit(Queue* pq)
{
	assert(pq);

	pq->head = NULL;
	pq->tail = NULL;
}

// 销毁
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

// 队尾插入
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

// 队头删除
void QueuePop(Queue* pq)
{
	assert(pq);
	assert(!QueueEmpty(pq));// 判断队列是否为空
	 
	QueueNode* next = pq->head->next;
	free(pq->head);
	pq->head = next;

	// 判断最后一个元素是否被删除
	// 将尾置空防止野指针
	if (pq->head == NULL)
	{
		pq->head = pq->tail = NULL;
	}
}

// 取队头数据
QDataType QueueFront(Queue* pq)
{
	assert(pq);
	assert(!QueueEmpty(pq));

	return pq->head->data;
}

// 取队尾数据
QDataType QueueBack(Queue* pq)
{
	assert(pq);
	assert(!QueueEmpty(pq));

	return pq->tail->data;
}

// 计算队列大小
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

// 判断队列是否为空
bool QueueEmpty(Queue* pq)
{
	assert(pq);
	
	// 头为空，说明队列无数据
	return pq->head == NULL;
}