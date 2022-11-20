#define _CRT_SECURE_NO_WARNINGS 1 

#include "Heap.h"

void TestHp1()
{
	HP hp;
	HeapInit(&hp);
	
	int arr[] = { 27,15,19,18,28,34,65,49,25,37 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	
	for (int i = 0; i < sz; i++)
	{
		HeapPush(&hp, arr[i]);
	}

	HeapPrint(&hp);

	HeapPop(&hp);
	HeapPrint(&hp);

	/*int k = 5;
	while (k--)
	{
		printf("%d ", HeapTop(&hp));
		HeapPop(&hp);
	}*/

	HeapDestroy(&hp);
}

void TestHp2()
{
	int array[] = { 27, 15, 19, 18, 28, 34, 65, 49, 25, 37 };
	HP hp;
	HeapInit(&hp);
	for (int i = 0; i < sizeof(array) / sizeof(int); ++i)
	{
		HeapPush(&hp, array[i]);
	}

	while (!HeapEmpty(&hp))
	{
		printf("%d ", HeapTop(&hp));
		HeapPop(&hp);
	}

	HeapDestroy(&hp);
}

int main()
{
	TestHp1();
	//TestHp2();
	
	return 0;
}