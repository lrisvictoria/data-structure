#define _CRT_SECURE_NO_WARNINGS 1 

#include "Heap.h"

void AdjustDown(HPDataType* a, int n, int parent);
// �ѵĹ���

// 1. ���ù���
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

// 2. �����㷨
void HeapCreate(HP* php, HPDataType* a, int n)
{
	assert(php);

	// �ֽ����
	// ���Ҷ�ҪΪ��
	// �����һ����Ϊ��׼��ʼ������׼�������ĸ���

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

// ��ʼ�� �����ռ�
void HeapInit(HP* php)
{
	assert(php);

	php->a = NULL;
	php->size = php->capacity = 0;
}

// ����
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

// ���ϵ���
void AdjustUp(HPDataType* a, int child)
{
	assert(a);

	// �㸸��
	int parent = (child - 1) / 2;

	// Ĭ��С��
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

// ������������һ���� O(logN)
void HeapPush(HP* php, HPDataType x)
{
	assert(php);

	// �������
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

	// ����Ԫ��
	php->a[php->size++] = x;

	// ���ϵ���
	AdjustUp(php->a, php->size - 1);
}

// ���µ���
void AdjustDown(HPDataType* a, int n, int parent)
{
	// ������С����
	int minchild = 2 * parent + 1;

	while (minchild < n)
	{
		// ����С����
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

// ɾ���Ѷ������ݣ����ұ�����������һ���� O(logN)
void HeapPop(HP* php)
{
	assert(php);
	assert(php->size > 0);

	// �����Ѷ������һ���ڵ��ֵ
	Swap(&php->a[0], &php->a[php->size - 1]);
	// βɾ
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
// �ѵ��п�
bool HeapEmpty(HP* php)
{
	assert(php);

	return php->size == 0;
}