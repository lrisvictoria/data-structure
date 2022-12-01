#define _CRT_SECURE_NO_WARNINGS 1 

#include "Sort.h"

void PrintArray(int* a, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}

void InsertSort(int* a, int n)
{
	// < n ��Խ��
	for (int i = 0; i < n - 1; i++)
	{
		// ����
		int end = i;
		int tmp = a[end + 1];
		while (end >= 0)
		{
			if (tmp < a[end])
			{
				a[end + 1] = a[end];
				end--;
			}
			else
			{
				break;
			}
		}
		a[end + 1] = tmp;
	}
}

void ShellSort(int* a, int n)
{
	int gap = n;
	// �����������һ��Ϊ��������
	while (gap > 1)
	{
		gap = gap / 3 + 1;
		// �����������У�����Ԥ����
		for (int j = 0; j < gap; j++)
		{
			// ���ڵ���
			for (int i = j; i < n - gap; i += gap)
			{
				// ���ڵ���Ԫ��
				int end = i;
				int tmp = a[end + gap];
				while (end >= 0)
				{
					if (tmp < a[end])
					{
						a[end + gap] = a[end];
						end -= gap;
					}
					else
					{
						break;
					}
				}
				a[end + gap] = tmp;
			}
		}
	}
}