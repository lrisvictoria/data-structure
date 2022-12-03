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

	while (begin < end)
	{
		// mini 和 maxi 需要一直更新
		// 每次从 begin 开始，筛选出最大值的下标和最小值的下标
		int mini = begin, maxi = begin;
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
		}

		// 分别交换 begin 和 mini 的值 / end 和 maxi 的 值
		// 特殊情况特殊处理
		
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

void BubbleSort(int* a, int n)
{
	for (int j = 0; j < n - 1; j++)
	{
		int exchange = 0;
		// 单趟
		for (int i = 0; i < n - 1 - j; i++)
		{
			if (a[i] > a[i + 1])
			{
				Swap(&a[i], &a[i + 1]);
				exchange = 1;
			}
			
			// 如果一趟排序中第一次没有交换，说明本趟有序
			// 直接跳转到下一趟
			if (exchange == 0)
			{
				break;
			}
		}
	}
}

// 快排
void QuickSort(int* a, int begin, int end)
{
	// 如果 l > r 那么没必要递归，直接返回
	if (begin >= end)
	{
		return;
	}

	int left = begin;
	int right = end;
	int keyi = left;

	// 一次没必要递归
	while (left < right)
	{
		// 防止越界，右边大于等于 keyi 值就 --
		while (left < right && a[right] >= a[keyi])
		{
			right--;
		}

		// 防止越界，左边小于等于 keyi 值就 ++
		while (left < right && a[left] <= a[keyi])
		{
			left++;
		}
		
		// 此时停下来，一定是交换位置的地方
		Swap(&a[left], &a[right]);
	}

	// 一次完后，交换 left 和 keyi 下标对应的值
	// L 和 R 相遇的位置一定小于 keyi
	Swap(&a[left], &a[keyi]);
	
	// left 变成新的 keyi
	keyi = left;

	// 分别递归左边和右边
	QuickSort(a, begin, keyi - 1);
	QuickSort(a, keyi + 1, end);
}