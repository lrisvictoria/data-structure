#include <graphics.h>
#include <stdio.h>
#define DataType int
#define MaxQueueSize 8
typedef struct{
	DataType queue[MaxQueueSize];
	int front;
	int rear;
	int count;	
}SeqQueue;

SeqQueue q;

//1
void QueueInitiate(SeqQueue *Q)
{
	Q->front=0;
	Q->rear=0;
	Q->count=0;
}

//2
int QueueAppend(SeqQueue *Q,DataType x)
{
	Q->queue[Q->rear]=x;
	Q->rear=(Q->rear+1)%MaxQueueSize;	
	Q->count++;
	return 1;
}

//3

DataType deletecount=0;

int QueueDelete(SeqQueue *Q,DataType *d)
{
	*d=Q->queue[Q->front];
	Q->front=(Q->front+1)%MaxQueueSize;
	Q->count--;
	//输出表
	deletecount++;//计数加一
		xyprintf(10,172.5,"输出"); 
		for(int i=0;i<=MaxQueueSize;i++)
		{
				rectangle(50,150,450,200);
				line(50+50*i,150,50+50*i,200);
				xyprintf(72.5+50*deletecount,172.5,"%d",Q->queue[Q->front-1]);
		}
		Q->queue[Q->front-1]=0;//出列置零
	return 1;
	
}
void Show()
{
	//循环队列内容
	rectangle(50,50,450,100);
	for(int i=1;i<=MaxQueueSize-1;i++)
	{
			line(50+50*i,50,50+50*i,100);
			
	}
	for(int i=0;i<MaxQueueSize;i++)
	{
		xyprintf(72.5+50*i,72.5,"%d",q.queue[i]);
		xyprintf(72.5+50*(q.rear),122.5,"↑rear");
		xyprintf(72.5+50*(q.front),22.5,"↓front");
	}
	xyprintf(10,10,"count=%d",q.count);
	
	getch();
	cleardevice();
	
}
int main()
{
	initgraph(800,600);
	setcolor(BLUE);
	setbkcolor(WHITE);
	setbkmode(TRANSPARENT);
	setrendermode(RENDER_MANUAL);
	QueueInitiate(&q);
	QueueAppend(&q, 11);
	Show();
	QueueAppend(&q, 13);
	Show();
	QueueAppend(&q, 7);
	Show();
	DataType d;
	QueueDelete(&q, &d);
	Show();
	QueueDelete(&q, &d);
	Show();
	QueueDelete(&q, &d);
	Show();
}
