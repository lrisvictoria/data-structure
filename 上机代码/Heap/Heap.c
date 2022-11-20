#define _CRT_SECURE_NO_WARNINGS 1 

#include "Heap.h"

void AdjustDown(HPDataType* a, int n, int parent);
// 堆的构建

// 1. 复用构建
//void HeapCreate(HP* php, HPDataType* a, int n)
//{
//	assert(php);
//
//	HeapInit(&php);
//	for (int i = 0; i < n; i++)
//	{
//		HeapPush(&php, a[i]);
//	}
//}

// 2. 建堆算法
void HeapCreate(HP* php, HPDataType* a, int n)
{
	assert(php);

	// 分解调堆
	// 左右都要为堆
	// 从最后一个点为基准开始调，对准的是它的父亲

	php->a = (HPDataType*)malloc(sizeof(HPDataType) * n);
	if (php->a == NULL)
	{
		perror("malloc fail");
		exit(-1);
	}
	memcpy(php->a, a, sizeof(HPDataType) * n);

	for (int i = (n - 1 - 1) / 2; i >= 0; i--)
	{
		AdjustDown(a, n, i);
	}
}

void HeapPrint(HP* php)
{
	assert(php);

	for (int i = 0; i < php->size; i++)
	{
		printf("%d ", php->a[i]);
	}
	printf("\n");
}

// 初始化 不开空间
void HeapInit(HP* php)
{
	assert(php);

	php->a = NULL;
	php->size = php->capacity = 0;
}

// 销毁
void HeapDestroy(HP* php)
{
	assert(php);

	free(php->a);
	php->a = NULL;

	php->size = php->capacity = 0;
}

void Swap(HPDataType* p1, HPDataType* p2)
{
	assert(p1 && p2);

	HPDataType tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}

// 向上调整
void AdjustUp(HPDataType* a, int child)
{
	assert(a);

	// 算父亲
	int parent = (child - 1) / 2;

	// 默认小堆
	while (child > 0)
	{
		if (a[child] < a[parent])
		{
			Swap(&a[child], &a[parent]);
			child = parent;
			parent = (child - 1) / 2;
		}
		else
		{
			break;
		}
	}
	
}

// 保持他继续是一个堆 O(logN)
void HeapPush(HP* php, HPDataType x)
{
	assert(php);

	// 检查容量
	if (php->size == php->capacity)
	{
		int newcapacity = php->capacity == 0 ? 4 : php->capacity * 2;
		HPDataType* tmp = (HPDataType*)realloc(php->a, sizeof(HPDataType) * newcapacity);
		if (tmp == NULL)
		{
			perror("realloc fail");
			exit(-1);
		}
		php->a = tmp;
		php->capacity = newcapacity;
	}

	// 插入元素
	php->a[php->size++] = x;

	// 向上调整
	AdjustUp(php->a, php->size - 1);
}

// 向下调整
void AdjustDown(HPDataType* a, int n, int parent)
{
	// 假设最小孩子
	int minchild = 2 * parent + 1;

	while (minchild < n)
	{
		// 找最小孩子
		if (minchild + 1 < n && a[minchild + 1] < a[minchild])
		{
			minchild++;
		}
		if (a[parent] > a[minchild])
		{
			Swap(&a[parent], &a[minchild]);
			parent = minchild;
			minchild = 2 * parent + 1;
		}
		else
		{
			break;
		}
	}
}

// 删除堆顶的数据，并且保持他继续是一个堆 O(logN)
void HeapPop(HP* php)
{
	assert(php);
	assert(php->size > 0);

	// 交换堆顶和最后一个节点的值
	Swap(&php->a[0], &php->a[php->size - 1]);
	// 尾删
	php->size--;

	AdjustDown(php->a, php->size, 0);
}

HPDataType HeapTop(HP* php)
{
	assert(php);
	assert(php->size > 0);

	return php->a[0];
}

int HeapSize(HP* php)
{
	assert(php);

	return php->size;
}
// 堆的判空
bool HeapEmpty(HP* php)
{
	assert(php);

	return php->size == 0;
}