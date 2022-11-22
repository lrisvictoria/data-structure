#define _CRT_SECURE_NO_WARNINGS 1 

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
void Swap(int* p1, int* p2)
{
	int tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
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

void TestHeap3()
{
	int n, k;
	printf("������n��k:>");
	scanf("%d%d", &n, &k);
	srand((unsigned int)time(NULL));

	// д�ļ�
	FILE* in = fopen("data.txt", "w");
	if (in == NULL)
	{
		perror("fopen fail");
		return;
	}

	// д���������С������100000
	/*fprintf(in, "%d\n", 66666);
	fprintf(in, "%d\n", 77777);
	fprintf(in, "%d\n", 88888);
	fprintf(in, "%d\n", 99999);
	fprintf(in, "%d\n", 55555);*/
	for (int i = 0; i <= n - 5; i++)
	{
		fprintf(in, "%d\n", rand());
	}

	// �ֶ����������������ֵ��ֵ
	fprintf(in, "%d\n", 66666);
	fprintf(in, "%d\n", 77777);
	fprintf(in, "%d\n", 88888);
	fprintf(in, "%d\n", 99999);
	fprintf(in, "%d\n", 55555);

	fclose(in);
	in = NULL;

	// ���ļ�
	FILE* out = fopen("data.txt", "r");
	if (out == NULL)
	{
		perror("fopen fail");
		return;
	}
	// ��̬���ٿռ�
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
	// ȡk��������С��
	for (int i = (k - 1 - 1) / 2; i >= 0; i--)
	{
		AdjustDown2(minHeap, k, i);
	}

	// ��ʼ����
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
	fclose(out);
	out = NULL;
}

int main()
{
	TestHeap3();
}