#define _CRT_SECURE_NO_WARNINGS 1 

#include "Sort.h"

void TestInsertSort()
{
	int arr[] = { 9,8,7,6,5,4,3,2,1 };
	int sz = sizeof(arr) / sizeof(arr[0]);

	InsertSort(arr, sz);

	PrintArray(arr, sz);
}

void TestShellSort()
{
	int arr[] = { 9,8,7,6,5,4,3,2,1 };
	int sz = sizeof(arr) / sizeof(arr[0]);

	ShellSort(arr, sz);

	PrintArray(arr, sz);
}

void TestOP()
{
	srand(time(0));
	const int N = 10000000;

	int* a1 = (int*)malloc(sizeof(int) * N);
	int* a2 = (int*)malloc(sizeof(int) * N);
	int* a3 = (int*)malloc(sizeof(int) * N);
	int* a4 = (int*)malloc(sizeof(int) * N);
	int* a5 = (int*)malloc(sizeof(int) * N);
	int* a6 = (int*)malloc(sizeof(int) * N);
	int* a7 = (int*)malloc(sizeof(int) * N);

	for (int i = 0; i < N; ++i)
	{
		a1[i] = rand();
		a2[i] = a1[i];
		a3[i] = a1[i];
		a4[i] = a1[i];
		a5[i] = a1[i];
		a6[i] = a1[i];
		a7[i] = a1[i];
	}

	// clock 获取程序运行到这块的时间
	// end1 - begin1 = 排序时间
	// 获取的是毫秒
	// 过小时计算不出来
	int begin1 = clock();
	//InsertSort(a1, N);
	int end1 = clock();

	int begin2 = clock();
	ShellSort(a2, N);
	int end2 = clock();

	int begin3 = clock();
	//SelectSort(a3, N);
	int end3 = clock();

	int begin4 = clock();
	HeapSort(a4, N);
	int end4 = clock();

	int begin5 = clock();
	QuickSortT(a5, 0, N - 1);
	int end5 = clock();

	int begin6 = clock();
	//BubbleSort(a6, N);
	int end6 = clock();

	int begin7 = clock();
	//MergeSort(a7, N);
	MergeSortNonR(a7, N);
	int end7 = clock();

	printf("InsertSort:%d\n", end1 - begin1);
	printf("ShellSort:%d\n", end2 - begin2);
	printf("SelectSort:%d\n", end3 - begin3);
	printf("HeapSort:%d\n", end4 - begin4);
	printf("QuickSort:%d\n", end5 - begin5);
	printf("BubbleSort:%d\n", end6 - begin6);
	printf("MergeSort:%d\n", end7 - begin7);

	free(a1);
	free(a2);
	free(a3);
	free(a4);
	free(a5);
	free(a6);
	free(a7);
}

void TestHeapSort()
{
	int arr[] = { 9,8,7,6,5,4,3,2,1 };
	int sz = sizeof(arr) / sizeof(arr[0]);

	HeapSort(arr, sz);

	PrintArray(arr, sz);
}

void TestSelectSort()
{
	int arr[] = { 9,8,7,6,5,4,3,2,1 };
	int sz = sizeof(arr) / sizeof(arr[0]);

	SelectSort(arr, sz);

	PrintArray(arr, sz);
}

void TestBubbleSort()
{
	int arr[] = { 9,8,7,6,5,4,3,2,1 };
	int sz = sizeof(arr) / sizeof(arr[0]);

	BubbleSort(arr, sz);

	PrintArray(arr, sz);

}

void TestQuickSort()
{
	int arr[] = { 6, 1, 2, 7, 9, 3, 4, 5, 10, 8 };
	int sz = sizeof(arr) / sizeof(arr[0]);

	QuickSort(arr, 0, sz - 1);
	//QuickSortT(arr, 0, sz - 1);

	PrintArray(arr, sz);
}

void TestMergeSort()
{
	int arr[] = { 6, 1, 2, 7, 9, 3, 4, 5, 10, 8 };
	int sz = sizeof(arr) / sizeof(arr[0]);

	MergeSort(arr, sz);

	PrintArray(arr, sz);
}

void TestMergeSortnonR()
{
	int arr[] = { 6, 1, 2, 7, 9, 3, 4, 5, 10, 8 };
	int sz = sizeof(arr) / sizeof(arr[0]);

	MergeSortNonR(arr, sz);

	PrintArray(arr, sz);
}

void TestCountSort()
{
	int arr[] = { 6, 1, 2, 7, 9, 3, 4, 5, 10, 8 };
	int sz = sizeof(arr) / sizeof(arr[0]);

	CountSort(arr, sz);

	PrintArray(arr, sz);
}

int main()
{
	//TestInsertSort();
	//TestShellSort();
	//TestHeapSort();
	//TestSelectSort();
	//TestBubbleSort();
	TestQuickSort();
	//TestMergeSort();
	//TestMergeSortnonR();
	//TestCountSort();

	//TestOP();


	return 0;
}