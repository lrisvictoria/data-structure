#pragma once
/*
* 队列由于需要两边出数据，所以使用顺序队列挪动数据时效率低
* 所以我们实现链式队列
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

// 初始化
void QueueInit(Queue* pq);

// 销毁
void QueueDestroy(Queue* pq);

// 队尾插入
void QueuePush(Queue* pq, QDataType x);

// 队头删除
void QueuePop(Queue* pq);

// 取队头数据
QDataType QueueFront(Queue* pq);

// 取队尾数据
QDataType QueueBack(Queue* pq);

// 计算队列大小
int QueueSize(Queue* pq);

// 判断队列是否为空
bool QueueEmpty(Queue* pq);
