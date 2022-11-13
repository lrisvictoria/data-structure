#define _CRT_SECURE_NO_WARNINGS 1 

#include "Queue.h"

void TestQueue1()
{
	// 创建一个结构体
	Queue q;

	QueueInit(&q);
	QueuePush(&q, 1);
	QueuePush(&q, 2);
	QueuePush(&q, 3);
	QueuePush(&q, 4);

	/*QueuePop(&q);
	QueuePop(&q);
	QueuePop(&q);
	QueuePop(&q);
	QueuePop(&q);*/

	while (!QueueEmpty(&q))
	{
		printf("%d ", QueueFront(&q));
		QueuePop(&q);
	}
	printf("\n");

	printf("%d\n", QueueSize(&q));
	printf("%d\n", QueueEmpty(&q)); // 空
}

int main()
{
	TestQueue1();

	return 0;
}