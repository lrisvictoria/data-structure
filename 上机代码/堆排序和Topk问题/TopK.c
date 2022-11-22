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

	// 建小堆
	while (child < sz)
	{
		if (child + 1 < sz && a[child + 1] < a[child])
		{
			child++;
		}
		// 判断孩子是否小于父亲
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
	printf("请输入n和k:>");
	scanf("%d%d", &n, &k);
	srand((unsigned int)time(NULL));

	// 写文件
	FILE* in = fopen("data.txt", "w");
	if (in == NULL)
	{
		perror("fopen fail");
		return;
	}

	// 写随机数，大小不超过100000
	/*fprintf(in, "%d\n", 66666);
	fprintf(in, "%d\n", 77777);
	fprintf(in, "%d\n", 88888);
	fprintf(in, "%d\n", 99999);
	fprintf(in, "%d\n", 55555);*/
	for (int i = 0; i <= n - 5; i++)
	{
		fprintf(in, "%d\n", rand());
	}

	// 手动输入大于随机数最大值的值
	fprintf(in, "%d\n", 66666);
	fprintf(in, "%d\n", 77777);
	fprintf(in, "%d\n", 88888);
	fprintf(in, "%d\n", 99999);
	fprintf(in, "%d\n", 55555);

	fclose(in);
	in = NULL;

	// 读文件
	FILE* out = fopen("data.txt", "r");
	if (out == NULL)
	{
		perror("fopen fail");
		return;
	}
	// 动态开辟空间
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
	// 取k个数，建小堆
	for (int i = (k - 1 - 1) / 2; i >= 0; i--)
	{
		AdjustDown2(minHeap, k, i);
	}

	// 开始调整
	while (fscanf(out, "%d", &val) != EOF)
	{
		if (val > minHeap[0])
		{
			minHeap[0] = val;
			AdjustDown2(minHeap, k, 0);
		}
	}

	// 打印minHeap 就是 topK
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