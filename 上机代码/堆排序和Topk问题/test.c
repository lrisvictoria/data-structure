#define _CRT_SECURE_NO_WARNINGS 1 

#include <stdio.h>
#include <time.h>
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

// ���µ���
void AdjustDown1(int* a, int sz, int parent)
{
	int child = 2 * parent + 1;

	// �����
	while (child < sz)
	{
		if (child + 1 < sz && a[child + 1] > a[child])
		{
			child++;
		}
		
		// �жϺ����Ƿ���ڸ���
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

void AdjustDown2(int* a, int sz, int parent)
{
	int child = 2 * parent + 1;

	// ��С��
	while (child < sz)
	{
		if (child + 1 < sz && a[child + 1] < a[child])
		{
			child++;
		}

		// �жϺ����Ƿ�С�ڸ���
		if (a[child] < a[parent])
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

// ������
void HeapSort(int* a, int sz)
{
	// ����
	for (int i = (sz - 1 - 1) / 2; i >= 0; i--)
	{
		AdjustDown1(a, sz, i);
	}

	// �˿̶��Ѿ�������
	// �������Ѿ����˴�ѣ���ô��ʱ��������µ���

	int end = sz - 1;
	while (end > 0)
	{
		Swap(&a[0], &a[end]);
		AdjustDown1(a, end, 0);
		end--;
	}
}

void TestHeap1()
{
	int array[] = { 27, 15, 19, 18, 28, 34, 65, 49, 25, 37 };
	HeapSort(array, sizeof(array) / sizeof(int));

	for (int i = 0; i < sizeof(array) / sizeof(int); ++i)
	{
		printf("%d ", array[i]);
	}
	printf("\n");
}

void TestHeap2()
{
	int minHeap[5];
	FILE* out = fopen("data.txt", "r");
	if (out == NULL)
	{
		perror("fopen fail");
		return;
	}

	for (int i = 0; i < 5; i++)
	{
		fscanf(out, "%d", &minHeap[i]);
	}

	int val = 0;
	// ȡ�������������С��
	for (int i = (5 - 1 - 1) / 2; i >= 0; i--)
	{
		AdjustDown2(minHeap, 5, 0);
	}

	// ��ʼ�Ƚ�
	while (fscanf(out, "%d", &val) != EOF)
	{
		if (val > minHeap[0])
		{
			minHeap[0] = val;
			AdjustDown2(minHeap, 5, 0);
		}
	}

	// ��ӡminHeap ���� topK
	for (int i = 0; i < 5; i++)
	{
		printf("%d ", minHeap[i]);
	}

	printf("\n");
	fclose(out);
	out = NULL;
}

// ��չ
void TestHeap3()
{
	int n, k;
	printf("������n��k:>");
	scanf("%d%d", &n, &k);
	srand((unsigned int)time(NULL));

	FILE* in = fopen("data.txt", "w");
	if (in == NULL)
	{
		perror("fopen fail");
		return;
	}

	for (int i = 0; i < n; i++)
	{
		fprintf(in, "%d\n", rand() % 1000000);
	}

	FILE* out = fopen("data.txt", "r");
	if (out == NULL)
	{
		perror("fopen fail");
		return;
	}
	int* minHeap = (int*)malloc(sizeof(int) * k);
	if (minHeap == NULL)
	{
		perror("malloc fail");
		return;
	}

	for (int i = 0; i < k; i++)
	{
		fscanf(out, "%d", &minHeap[i]);
	}

	int val = 0;
	// ȡ�������������С��
	for (int i = (k - 1 - 1) / 2; i >= 0; i--)
	{
		AdjustDown2(minHeap, k, 0);
	}

	// ��ʼ�Ƚ�
	while (fscanf(out, "%d", &val) != EOF)
	{
		if (val > minHeap[0])
		{
			minHeap[0] = val;
			AdjustDown2(minHeap, k, 0);
		}
	}

	// ��ӡminHeap ���� topK
	for (int i = 0; i < k; i++)
	{
		printf("%d ", minHeap[i]);
	}

	printf("\n");
	fclose(in);
	in = NULL;
}

int main()
{
	//TestHeap1();
	//TestHeap2();
	TestHeap3();

}