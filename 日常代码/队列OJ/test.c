#define _CRT_SECURE_NO_WARNINGS 1 

// 232. 用队列实现栈

//#include <stdio.h>
//#include <assert.h>
//#include <stdlib.h>
//#include <stdbool.h>
//
//typedef int QDataType;
//
//typedef struct QueueNode
//{
//	struct QueueNode* next;
//	QDataType data;
//}QueueNode;
//
//typedef struct Queue
//{
//	QueueNode* head;
//	QueueNode* tail;
//}Queue;
//
//void QueueInit(Queue* pq);
//void QueueDestroy(Queue* pq);
//void QueuePush(Queue* pq, QDataType x);
//void QueuePop(Queue* pq);
//QDataType QueueFront(Queue* pq);
//QDataType QueueBack(Queue* pq);
//int QueueSize(Queue* pq);
//bool QueueEmpty(Queue* pq);
//
//void QueueInit(Queue* pq)
//{
//	assert(pq);
//
//	pq->head = NULL;
//	pq->tail = NULL;
//}
//
//void QueueDestroy(Queue* pq)
//{
//	assert(pq);
//
//	QueueNode* cur = pq->head;
//	while (cur != NULL)
//	{
//		QueueNode* next = cur->next;
//		free(cur);
//		cur = next;
//	}
//	pq->head = pq->tail = NULL;
//}
//
//void QueuePush(Queue* pq, QDataType x)
//{
//	assert(pq);
//	QueueNode* newnode = (QueueNode*)malloc(sizeof(QueueNode));
//	newnode->data = x;
//	newnode->next = NULL;
//
//	if (pq->head == NULL)
//	{
//		pq->head = pq->tail = newnode;
//	}
//	else
//	{
//		pq->tail->next = newnode;
//		pq->tail = newnode;
//	}
//}
//
//void QueuePop(Queue* pq)
//{
//	assert(pq);
//	assert(!QueueEmpty(pq));
//
//	QueueNode* next = pq->head->next;
//	free(pq->head);
//	pq->head = next;
//
//	if (pq->head == NULL)
//	{
//		pq->tail = NULL;
//	}
//}
//
//QDataType QueueFront(Queue* pq)
//{
//	assert(pq);
//	assert(!QueueEmpty(pq));
//
//	return pq->head->data;
//}
//
//QDataType QueueBack(Queue* pq)
//{
//	assert(pq);
//	assert(!QueueEmpty(pq));
//
//	return pq->tail->data;
//}
//
//int QueueSize(Queue* pq)
//{
//	assert(pq);
//
//	int size = 0;
//	QueueNode* cur = pq->head;
//
//	while (cur)
//	{
//		size++;
//		cur = cur->next;
//	}
//
//	return size;
//}
//
//bool QueueEmpty(Queue* pq)
//{
//	assert(pq);
//
//	return pq->head == NULL;
//}
//
//typedef struct
//{
//	Queue q1;
//	Queue q2;
//} MyStack;
//
//MyStack* myStackCreate()
//{
//	MyStack* st = (MyStack*)malloc(sizeof(MyStack));
//	// 队列接口的函数的类型是Queue*
//	// st->p1 的类型是Queue，所以需要取地址
//	QueueInit(&st->q1);
//	QueueInit(&st->q2);
//
//	return st;
//}
//
//void myStackPush(MyStack* obj, int x)
//{
//	if (!QueueEmpty(&obj->q1))
//	{
//		QueuePush(&obj->q1, x);
//	}
//	else
//	{
//		QueuePush(&obj->q2, x);
//	}
//}
//
//int myStackPop(MyStack* obj)
//{
//	Queue* empty = &obj->q1;
//	Queue* noEmpty = &obj->q2;
//
//	if (!QueueEmpty(&obj->q1))
//	{
//		noEmpty = &obj->q1;
//		empty = &obj->q2;
//	}
//
//	while (QueueSize(noEmpty) > 1)
//	{
//		QueuePush(empty, QueueFront(noEmpty));
//		QueuePop(noEmpty);
//	}
//
//	int top = QueueFront(noEmpty);
//	QueuePop(noEmpty);
//
//	return top;
//}
//
//int myStackTop(MyStack* obj)
//{
//	if (!QueueEmpty(&obj->q1))
//	{
//		return QueueBack(&obj->q1);
//	}
//	else
//	{
//		return QueueBack(&obj->q2);
//	}
//}
//
//bool myStackEmpty(MyStack* obj)
//{
//	return QueueEmpty(&obj->q1) && QueueEmpty(&obj->q2);
//}
//
//void myStackFree(MyStack* obj)
//{
//	QueueDestroy(&obj->q1);
//	QueueDestroy(&obj->q2);
//
//	free(obj);
//}
//
///**
// * Your MyStack struct will be instantiated and called as such:
// * MyStack* obj = myStackCreate();
// * myStackPush(obj, x);
//
// * int param_2 = myStackPop(obj);
//
// * int param_3 = myStackTop(obj);
//
// * bool param_4 = myStackEmpty(obj);
//
// * myStackFree(obj);
//*/
//
//int main()
//{
//	MyStack* st = myStackCreate();
//
//	myStackPush(st, 1);
//	myStackPush(st, 1);
//	myStackPush(st, 1);
//	myStackPop(st);
//	myStackFree(st);
//
//	return 0;
//}

// 用栈实现队列

#define _CRT_SECURE_NO_WARNINGS 1 

// 请你仅使用两个栈实现先入先出队列。队列应当支持一般队列支持的所有操作（push、pop、peek、empty）：

typedef int STDataType;

typedef struct Stack
{
	STDataType* a;
	int top;
	int capacity;
}ST;

void StackInit(ST* ps);
void StackDestroy(ST* ps);
void StackPush(ST* ps, STDataType x);
void StackPop(ST* ps);
STDataType StackTop(ST* ps);
int StackSize(ST* ps);
bool StackEmpty(ST* ps);

void StackInit(ST* ps)
{
	assert(ps);
	ps->a = NULL;
	ps->top = 0;
	ps->capacity = 0;
}

void StackDestroy(ST* ps)
{
	assert(ps);
	free(ps->a);
	ps->a = NULL;
	ps->capacity = 0;
	ps->top = 0;
}

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

void StackPop(ST* ps)
{
	assert(ps);
	assert(!StackEmpty(ps));
	ps->top--;
}

STDataType StackTop(ST* ps)
{
	assert(ps);
	assert(!StackEmpty(ps));
	return ps->a[ps->top - 1];
}

int StackSize(ST* ps)
{
	assert(ps);
	return ps->top;
}

bool StackEmpty(ST* ps)
{
	assert(ps);
	return ps->top == 0;
}

typedef struct
{
	ST PushST;
	ST PopST;
} MyQueue;

MyQueue* myQueueCreate()
{
	MyQueue* q = (MyQueue*)malloc(sizeof(MyQueue));
	StackInit(&q->PushST);
	StackInit(&q->PopST);

	return q;
}

void myQueuePush(MyQueue* obj, int x)
{
	StackPush(&obj->PushST, x);
}

int myQueuePop(MyQueue* obj)
{
	// 如果PopST中没有数据，将PushST的数据导过去
	// popST中的数据就符合先进先出的顺序了
	if (StackEmpty(&obj->PopST))
	{
		while (!StackEmpty(&obj->PushST))
		{
			StackPush(&obj->PopST, StackTop(&obj->PushST));
			StackPop(&obj->PushST);
		}
	}

	// 有数据则直接从PopST中出数据
	int front = StackTop(&obj->PopST);
	StackPop(&obj->PopST);
	return front;
}

int myQueuePeek(MyQueue* obj)
{
	if (StackEmpty(&obj->PopST))
	{
		while (!StackEmpty(&obj->PushST))
		{
			StackPush(&obj->PopST, StackTop(&obj->PushST));
			StackPop(&obj->PushST);
		}
	}

	return StackTop(&obj->PopST);
}

bool myQueueEmpty(MyQueue* obj)
{
	return StackEmpty(&obj->PushST) && StackEmpty(&obj->PopST);
}

void myQueueFree(MyQueue* obj)
{
	StackDestroy(&obj->PushST);
	StackDestroy(&obj->PopST);

	free(obj);
}

/**
 * Your MyQueue struct will be instantiated and called as such:
 * MyQueue* obj = myQueueCreate();
 * myQueuePush(obj, x);

 * int param_2 = myQueuePop(obj);

 * int param_3 = myQueuePeek(obj);

 * bool param_4 = myQueueEmpty(obj);

 * myQueueFree(obj);
*/