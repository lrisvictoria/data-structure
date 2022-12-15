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
	for (int i = 0; i < n - 1; i++)
	{
		// ����
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

		// � end + 1 λ��
		a[end + 1] = tmp;
	}
}

void ShellSort(int* a, int n)
{
	int gap = n;

	// �Ĳ�ѭ������һ��
	//// �����������һ��Ϊ��������
	//while (gap > 1)
	//{
	//	gap = gap / 3 + 1;
	//	// �����������У�����Ԥ����
	//	for (int j = 0; j < gap; j++)
	//	{
	//		// ���ڵ���
	//		for (int i = j; i < n - gap; i += gap)
	//		{
	//			// ���ڵ���Ԫ��
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

	// ����ѭ��
	
	while (gap > 1)
	{
		gap = gap / 3 + 1;

		// ���鲢��
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
	// ����ѣ�������
	for (int i = (n - 1 - 1) / 2; i >= 0; i--)
	{
		AdjustDown(a, n, i);
	}

	// ���򣬽�����ֵ�ŵ��ѵ�
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

	// ѡ 1 ����
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

// ��������˼·��࣬���ڵ������в�ͬ�汾
// ��߾ͽ�����뿪��

int partion1(int* a, int begin, int end)
{
	int mid = GetIndexMid(a, begin, end);
	Swap(&a[mid], &a[begin]);

	int left = begin, right = end;

	int key = left;

	while (left < right)
	{
		// �ұ�����
		// ��������һ����ֹ�ܳ�ȥ���Ҵ��� a[key] ��ֵ
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

void QuickSort(int* a, int begin, int end)
{
	if (begin >= end)
	{
		return;
	}

	// С��һ����Ŀʹ�� ֱ�Ӳ�������
	if ((end - begin + 1) < 15)
	{
		InsertSort(a + begin, end - begin + 1);
	}
	else
	{
		int key = partion1(a, begin, end);
		// �ݹ���������
		QuickSort(a, begin, key - 1);
		QuickSort(a, key + 1, end);
	}
}

// ����
//void QuickSort(int* a, int begin, int end)
//{
//	if (begin >= end)
//	{
//		return;
//	}
//
//	// С��һ����Ŀʹ�� ֱ�Ӳ�������
//	if ((end - begin + 1) < 15)
//	{
//		InsertSort(a + begin, end - begin + 1);
//	}
//	else
//	{
//		// ����ȡ�У�ȡ������Ҳ��С��ֵ
//		int mid = GetIndexMid(a, begin, end);
//		Swap(&a[mid], &a[begin]);
//
//		int left = begin, right = end;
//
//		int key = left;
//
//		while (left < right)
//		{
//			// �ұ�����
//			// ��������һ����ֹ�ܳ�ȥ���Ҵ��� a[key] ��ֵ
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
//		// �ı� key ��λ��
//		key = left;
//
//		// �ݹ���������
//		QuickSort(a, begin, key - 1);
//		QuickSort(a, key + 1, end);
//	}
//}

// �鲢����ǵݹ�
void MergeSortNonR(int* a, int n)
{
	int* tmp = (int*)malloc(sizeof(int) * n);
	if (tmp == NULL)
	{
		perror("malloc fail");
		exit(-1);
	}

	int rangeN = 1;
	for (int i = 0; i < n; i += rangeN)
	{
		int begin1 = i, end1 = i + rangeN - 1;
		int begin2 = i + rangeN, end2 = i + 2 * rangeN - 1;

		int j = i;
		

	}
}
