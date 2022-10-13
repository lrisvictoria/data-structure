#include <graphics.h>

#define DataType int 
#define MaxQueueSize 8
/*
typedef struct 
{
	DataType queue[MaxQueueSize];
	int front;
	int rear;
	int count;
}SeqQueue;

SeqQueue q;

// 1. 初始化
void QueueInit(SeqQueue* q)
{
	q->front = 0;
	q->rear = 0;
	q->count = 0;
}

// 2. 输入队列
int QueueAppend(SeqQueue* q, DataType x)
{
	q->queue[q->rear] = x;
	q->rear = (q->rear + 1) % MaxQueueSize;
	q->count++;
	return 1;
}

// 3. 删除队列元素
int QueueDelete(SeqQueue* q, DataType* d)
{
	*d = q->queue[q->front];
	q->front = (q->front + 1) % MaxQueueSize;
	q->count--;
	return 1;
}

int main()
{
	initgraph(800, 600);
	setcolor(BLUE);
	setbkcolor(WHITE);
	setbkmode(TRANSPARENT);
	setrendermode(RENDER_MANUAL);
	
	QueueInit(&q);
	
	QueueAppend(&q, 11);	
	QueueAppend(&q, 13);
	QueueAppend(&q, 7);
	
	DataType d;
	QueueDelete(&q, &d);
	QueueDelete(&q, &d);
	
	QueueAppend(&q, 5);
	
	getch();
	
	return 0;
}

*/

#include <iostream>
#include <windows.h>
using namespace std;

int main()
{
	cout << "hello world" << endl;
	system("pause");
	return 0;
}
