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

int main()
{
	//TestInsertSort();
	TestShellSort();

	return 0;
}