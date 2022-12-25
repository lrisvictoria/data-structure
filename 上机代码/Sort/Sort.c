#define _CRT_SECURE_NO_WARNINGS 1 

#include "Sort.h"
#include "Stack.h"

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
	for (int i = 0; i < n - 1; i++)
	{
		// 单趟
		int end = i;
		int tmp = a[end + 1];

		while (end >= 0)
		{
			if (a[end] > tmp)
			{
				a[end + 1] = a[end];
				end--;
			}
			else
			{
				break;
			}
		}

		// 填到 end + 1 位置
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

		// 三组并排
		for (int i = 0; i < n - gap; i++)
		{
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
		AdjustDown(a, n, i);
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
	/*int begin = 0, end = n - 1;

	while (begin < end)
	{
		int mini = begin, maxi = begin;

		for (int i = begin + 1; i <= end; i++)
		{
			if (a[i] < a[mini])
			{
				mini = i;
			}

			if (a[i] > a[maxi])
			{
				maxi = i;
			}
		}

		Swap(&a[begin], &a[mini]);
		if (begin == maxi)
		{
			maxi = mini;
		}
		Swap(&a[end], &a[maxi]);
		begin++;
		end--;
	}*/

	// 选 1 个数
	int begin = 0;

	while (begin < n)
	{
		int mini = begin;

		for (int i = begin + 1; i < n; i++)
		{
			if (a[i] < a[mini])
			{
				mini = i;
			}
		}

		Swap(&a[begin], &a[mini]);
		begin++;
	}
}

void BubbleSort(int* a, int n)
{
	for (int j = 0; j < n - 1; j++)
	{
		int flag = 1;
		for (int i = 0; i < n - j - 1; i++)
		{
			if (a[i] > a[i + 1])
			{
				Swap(&a[i], &a[i + 1]);
				flag = 0;
			}
		}
		if (flag)
		{
			break;
		}
	}
}

int GetIndexMid(int* a, int begin, int end)
{
	int mid = (begin + end) >> 1;

	if (a[begin] < a[mid])
	{
		if (a[mid] < a[end])
		{
			return mid;
		}
		else if (a[begin] > a[end])
		{
			return begin;
		}
		else
		{
			return end;
		}
	}
	else // a[begin] >= a[mid]
	{
		if (a[mid] > a[end])
		{
			return mid;
		}
		else if (a[end] > a[begin])
		{
			return begin;
		}
		else
		{
			return end;
		}
	}
}

// 快排总体思路差不多，对于单趟排有不同版本
// 这边就将其分离开来

int partion1(int* a, int begin, int end)
{
	int mid = GetIndexMid(a, begin, end);
	Swap(&a[mid], &a[begin]);

	int left = begin, right = end;

	int key = left;

	while (left < right)
	{
		// 右边先走
		// 两个条件一个防止跑出去，找大于 a[key] 的值
		while (left < right && a[right] >= a[key])
		{
			right--;
		}

		while (left < right && a[left] <= a[key])
		{
			left++;
		}

		Swap(&a[left], &a[right]);
	}

	Swap(&a[left], &a[key]);
	key = left;

	return key;
}

// 挖坑法
int partion2(int* a, int begin, int end)
{
	int mid = GetIndexMid(a, begin, end);

	Swap(&a[begin], &a[mid]);

	int left = begin, right = end;
	int key = a[left];

	int hole = left;

	while (left < right)
	{
		// 右边找小，填到左边坑里面
		while (left < right && a[right] >= key)
		{
			right--;
		}

		a[hole] = a[right];
		hole = right;

		// 左边找大，填到右边坑里面
		while (left < right && a[left] <= key)
		{
			left++;
		}

		a[hole] = a[left];;
		hole = left;
	}

	a[hole] = key;

	// 最后 left 和 right 都在坑上
	return hole;
}

int partion3(int* a, int begin, int end)
{
	int mid = GetIndexMid(a, begin, end);
	Swap(&a[begin], &a[mid]);

	int prev = begin;
	int cur = begin + 1;
	int key = begin;

	while (cur <= end)
	{
		// 找到比 key 小的值时，跟 ++prev 位置交换，
		// 小的往前翻，大的往后翻

		// 重复数据不会交换
		if (a[cur] < a[key] && ++prev != cur)
			Swap(&a[cur], &a[prev]);

		// 重复数据会交换
		/*if (a[cur] < a[key])
			Swap(&a[++prev], &a[cur]);*/

			// cur 必定会走一步
		cur++;
	}

	Swap(&a[prev], &a[key]);

	//return prev;

	key = prev;

	return key;
}

void QuickSort(int* a, int begin, int end)
{
	if (begin >= end)
	{
		return;
	}

	// 小于一定数目使用 直接插入排序
	if ((end - begin + 1) < 15)
	{
		InsertSort(a + begin, end - begin + 1);
	}
	else
	{
		int key = partion3(a, begin, end);
		// 递归左右区间
		QuickSort(a, begin, key - 1);
		QuickSort(a, key + 1, end);
	}
}

// 快排
//void QuickSort(int* a, int begin, int end)
//{
//	if (begin >= end)
//	{
//		return;
//	}
//
//	// 小于一定数目使用 直接插入排序
//	if ((end - begin + 1) < 15)
//	{
//		InsertSort(a + begin, end - begin + 1);
//	}
//	else
//	{
//		// 三数取中，取出不大也不小的值
//		int mid = GetIndexMid(a, begin, end);
//		Swap(&a[mid], &a[begin]);
//
//		int left = begin, right = end;
//
//		int key = left;
//
//		while (left < right)
//		{
//			// 右边先走
//			// 两个条件一个防止跑出去，找大于 a[key] 的值
//			while (left < right && a[right] >= a[key])
//			{
//				right--;
//			}
//
//			while (left < right && a[left] <= a[key])
//			{
//				left++;
//			}
//
//			Swap(&a[left], &a[right]);
//		}
//
//		Swap(&a[left], &a[key]);
//
//		// 改变 key 的位置
//		key = left;
//
//		// 递归左右区间
//		QuickSort(a, begin, key - 1);
//		QuickSort(a, key + 1, end);
//	}
//}

// 如果使用队列的话相当于广度优先便利，先进先出，一层一层排

// 快排非递归
void QuickSortNorR(int* a, int begin, int end)
{
	ST st;
	StackInit(&st);

	// 压栈
	StackPush(&st, begin);
	StackPush(&st, end);

	while (!StackEmpty(&st))
	{
		// 后进先出，先出 right
		int right = StackTop(&st);
		StackPop(&st);

		int left = StackTop(&st);
		StackPop(&st);

		// 先取左区间，后取右区间
		// 所以先入右区间再入左区间
		// 如果区间内只有1个元素，则无需入栈

		int key = partion3(a, left , right);

		if (key + 1 < right)
		{
			StackPush(&st, key + 1);
			StackPush(&st, right);
		}

		if (left < key - 1)
		{
			StackPush(&st, left);
			StackPush(&st, key - 1);
		}
	}

	StackDestroy(&st);
}

void _MergeSort(int* a, int begin, int end, int* tmp)
{
	if (begin >= end)
	{
		return;
	}
	
	int mid = (begin + end) >> 1;

	_MergeSort(a, begin, mid, tmp);
	_MergeSort(a, mid + 1, end, tmp);

	int begin1 = begin, end1 = mid;
	int begin2 = mid + 1, end2 = end;
	
	/*
	* 此种做法 cnt 从 begin 开始
	* memset 从 begin 位置开始，一共拷贝 end - begin + 1 个元素
	* 和下面做法道理相同
	*/
	// int cnt = begin;
	
	/*
	* 此种做法 cnt 从 0 开始
	* 开始拷贝的位置从 begin 开始
	* cnt 最终的长度就是 [begin, end] 之间的长度
	* 没问题
	*/

	int cnt = 0; 

	while (begin1 <= end1 && begin2 <= end2)
	{
		// 保持稳定性
		if (a[begin1] <= a[begin2])
		{
			tmp[cnt++] = a[begin1++];
		}
		else
		{
			tmp[cnt++] = a[begin2++];
		}
	}

	while (begin1 <= end1) tmp[cnt++] = a[begin1++];
	while (begin2 <= end2) tmp[cnt++] = a[begin2++];

	// memcpy(a + begin, tmp + begin, sizeof(int) * (end - begin + 1));
	for (int i = begin, j = 0; i <= end; i++, j++)
	{
		a[i] = tmp[j];
	}
}

void MergeSort(int* a, int n)
{
	int* tmp = (int*)malloc(sizeof(int) * n);
	if (tmp == NULL)
	{
		perror("mallol fail");
		return;
	}

	_MergeSort(a, 0, n - 1, tmp);
}

// 归并排序非递归 - 不修正区间
//void MergeSortNonR(int* a, int n)
//{
//	int* tmp = (int*)malloc(sizeof(int) * n);
//	if (tmp == NULL)
//	{
//		perror("malloc fail");
//		exit(-1);
//	}
//
//	int rangeN = 1;
//	while (rangeN < n)
//	{
//		for (int i = 0; i < n; i += 2 * rangeN)
//		{
//			int begin1 = i, end1 = i + rangeN - 1;
//			int begin2 = i + rangeN, end2 = i + 2 * rangeN - 1;
//
//			int j = i;
//
//			if (end1 >= n)
//			{
//				break;
//			}
//			else if (begin2 >= n)
//			{
//				break;
//			}
//			else if (end2 >= n)
//			{
//				end2 = n - 1;
//				//break;
//			}
//
//			while (begin1 <= end1 && begin2 <= end2)
//			{
//				// 保持稳定性
//				if (a[begin1] <= a[begin2])
//				{
//					tmp[j++] = a[begin1++];
//				}
//				else
//				{
//					tmp[j++] = a[begin2++];
//				}
//			}
//
//			while (begin1 <= end1) tmp[j++] = a[begin1++];
//			while (begin2 <= end2) tmp[j++] = a[begin2++];
//
//			memcpy(a + i, tmp + i, sizeof(int) * (end2 - i + 1));
//		}
//		rangeN *= 2;
//	}
//
//	free(tmp);
//	tmp = NULL;
//}

// 归并非递归 - 修正区间
void MergeSortNonR(int* a, int n)
{
	int* tmp = (int*)malloc(sizeof(int) * n);
	if (tmp == NULL)
	{
		perror("malloc fail");
		exit(-1);
	}

	int rangeN = 1;

	while (rangeN < n)
	{
		for (int i = 0; i < n; i += 2 * rangeN)
		{
			int begin1 = i, end1 = i + rangeN - 1;
			int begin2 = i + rangeN, end2 = i + 2 * rangeN - 1;

			int j = i;
			// 修正区间
			if (end1 >= n)
			{
				end1 = n - 1;
				// begin2 和 end2 修正为不存在的区间
				begin2 = n;
				end2 = n - 1;
			}
			else if (begin2 >= n)
			{
				begin2 = n;
				end2 = n - 1;
			}		
			else if (end2 >= n)
			{
				end2 = n - 1;
			}

			while (begin1 <= end1 && begin2 <= end2)
			{
				if (a[begin1] <= a[begin2])
				{
					tmp[j++] = a[begin1++];
				}
				else
				{
					tmp[j++] = a[begin2++];
				}
			}
			while (begin1 <= end1)
			{
				tmp[j++] = a[begin1++];
			}
			while (begin2 <= end2)
			{
				tmp[j++] = a[begin2++];
			}
			// 可以局部拷贝
			//memcpy(a + i, tmp + i, sizeof(int) * (end2 - i + 1));
		}
		memcpy(a, tmp, sizeof(int) * n);
		rangeN *= 2;
	}
	free(tmp);
	tmp = NULL;
}
