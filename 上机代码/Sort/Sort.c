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
	// < n 会越界
	for (int i = 0; i < n - 1; i++)
	{
		// 单趟
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

	// 四层循环，简化一下
	//// 完整排序，最后一次为插入排序
	//while (gap > 1)
	//{
	//	gap = gap / 3 + 1;
	//	// 对于整个序列，进行预排序
	//	for (int j = 0; j < gap; j++)
	//	{
	//		// 对于单组
	//		for (int i = j; i < n - gap; i += gap)
	//		{
	//			// 对于单个元素
	//			int end = i;
	//			int tmp = a[end + gap];
	//			while (end >= 0)
	//			{
	//				if (tmp < a[end])
	//				{
	//					a[end + gap] = a[end];
	//					end -= gap;
	//				}
	//				else
	//				{
	//					break;
	//				}
	//			}
	//			a[end + gap] = tmp;
	//		}
	//	}
		//PrintArray(a, n);
	//}

	// 三层循环
	while (gap > 1)
	{
		gap = gap / 3 + 1;
		// 进行多组并排
		for (int i = 0; i < n - gap; i++)
		{
			// 对于单个元素
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

void Swap(int* p1, int* p2)
{
	int tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}

void AdjustDown(int* a, int n, int parent)
{
	int child = 2 * parent + 1;

	while (child < n)
	{
		if (child + 1 < n && a[child + 1] > a[child])
		{
			child++;
		}
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

void HeapSort(int* a, int n)
{
	// 建大堆，排升序
	for (int i = (n - 1 - 1) / 2; i >= 0; i--)
	{
		AdjustDown(a, n, 0);
	}

	// 排序，将最大的值放到堆底
	int end = n - 1;
	while (end > 0)
	{
		Swap(&a[0], &a[end]);
		AdjustDown(a, end, 0);
		end--;
	}
}

void SelectSort(int* a, int n)
{
	int begin = 0, end = n - 1;
	int mini = begin, maxi = end;

	while (begin < end)
	{
		for (int i = begin + 1; i <= end; i++)
		{
			// 如果 i 处值 小于 begin(最小值位置) 所在处值，更新 mini
			if (a[i] < a[mini])
			{
				mini = i;
			}

			// 如果 i 处值 大于 end(最大值位置) 所在处值，更新maxi
			if (a[i] > a[maxi])
			{
				maxi = i;
			}

			// 分别交换 begin 和 mini 的值 / end 和 maxi 的 值
			// 特殊情况特殊处理
		}
		Swap(&a[begin], &a[mini]);
		if (begin == maxi)
		{
			maxi = mini;
		}
		Swap(&a[end], &a[maxi]);

		// 更新 begin 和 end
		begin++;
		end--;
	}
}

//int PartSort3(int* a, int begin, int end)
//{
//	int prev = begin;
//	int cur = begin + 1;
//	int keyi = begin;
//
//	while (cur <= end)
//	{
//		if (a[cur] < a[keyi])
//		{
//			Swap(&a[++prev], &a[cur]);
//		}
//
//		++cur;
//	}
//	Swap(&a[prev], &a[keyi]);
//	keyi = prev;
//	return prev;
//}