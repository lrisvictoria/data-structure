#include <stdio.h>
#define MaxQueueSize 8
typedef struct{
	int  queue[MaxQueueSize];
	int front;
	int rear;
	int count;	
}SeqQueue;
SeqQueue q;
//1
void QueueInitiate(SeqQueue *Q){
	Q->front=0;
	Q->rear=0;
	Q->count=0;
}
//2
int QueueAppend(SeqQueue *Q,int x){
	Q->queue[Q->rear]=x;
	Q->rear=(Q->rear+1)%MaxQueueSize;	
	Q->count++;
	return 1;
}
//3
int QueueDelete(SeqQueue *Q,int  *d){
	*d=Q->queue[Q->front];
	Q->front=(Q->front+1)%MaxQueueSize;
	Q->count--;
	return 1;
}
//4
int SeqQueueNotEmpty(SeqQueue Q){
	if(Q.count!=0){
		return 1;
	}else{
		return 0;
	}
}
