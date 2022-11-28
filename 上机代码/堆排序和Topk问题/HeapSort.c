#define _CRT_SECURE_NO_WARNINGS 1 

#include <stdio.h>
#include <stdlib.h>

typedef int HPDataType;

typedef struct Heap
{
	HPDataType* a;
	int size;
	int capacity;
}HP;

void Swap(int* p1, int* p2)
{
	int tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}

// 向下调整建大堆
void AdjustDown(int a[], int n, int parent)
{
	int child = 2 * parent + 1;
	
	while (child < n)
	{
		// 求最大孩子
		if (child + 1 < n && a[child + 1] > a[child])
		{
			child++;
		}

		// 调整
		if (a[child] > a[parent])
		{
			Swap(&a[child], &a[parent]);
			parent = child;
			child = 2 * parent + 1;
		}
		else
		{
			break;
		}
	}
}

void HeapSort(int arr[], int sz)
{
	// 建堆
	// 向下调整建堆
	// 排升序，建大堆
	for (int i = (sz - 1 - 1) / 2; i >= 0; i--)
	{
		AdjustDown(arr, sz, 0);
	}

	int end = sz - 1;
	
	while (end > 0)
	{
		Swap(&arr[0], &arr[end]);
		AdjustDown(arr, end, 0);
		end--;
	}
}

void TestHP1()
{
	int arr[] = { 9,8,7,6,5,4,3,2,1,0 };
	int sz = sizeof(arr) / sizeof(arr[0]);

	HeapSort(arr, sz);
	for (int i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

int main()
{
	TestHP1();
	return 0;
}