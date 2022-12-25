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

// �ڿӷ�
int partion2(int* a, int begin, int end)
{
	int mid = GetIndexMid(a, begin, end);

	Swap(&a[begin], &a[mid]);

	int left = begin, right = end;
	int key = a[left];

	int hole = left;

	while (left < right)
	{
		// �ұ���С�����߿�����
		while (left < right && a[right] >= key)
		{
			right--;
		}

		a[hole] = a[right];
		hole = right;

		// ����Ҵ���ұ߿�����
		while (left < right && a[left] <= key)
		{
			left++;
		}

		a[hole] = a[left];;
		hole = left;
	}

	a[hole] = key;

	// ��� left �� right ���ڿ���
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
		// �ҵ��� key С��ֵʱ���� ++prev λ�ý�����
		// С����ǰ�����������

		// �ظ����ݲ��ύ��
		if (a[cur] < a[key] && ++prev != cur)
			Swap(&a[cur], &a[prev]);

		// �ظ����ݻύ��
		/*if (a[cur] < a[key])
			Swap(&a[++prev], &a[cur]);*/

			// cur �ض�����һ��
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

	// С��һ����Ŀʹ�� ֱ�Ӳ�������
	if ((end - begin + 1) < 15)
	{
		InsertSort(a + begin, end - begin + 1);
	}
	else
	{
		int key = partion3(a, begin, end);
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

// ���ʹ�ö��еĻ��൱�ڹ�����ȱ������Ƚ��ȳ���һ��һ����

// ���ŷǵݹ�
void QuickSortNorR(int* a, int begin, int end)
{
	ST st;
	StackInit(&st);

	// ѹջ
	StackPush(&st, begin);
	StackPush(&st, end);

	while (!StackEmpty(&st))
	{
		// ����ȳ����ȳ� right
		int right = StackTop(&st);
		StackPop(&st);

		int left = StackTop(&st);
		StackPop(&st);

		// ��ȡ�����䣬��ȡ������
		// ������������������������
		// ���������ֻ��1��Ԫ�أ���������ջ

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
	* �������� cnt �� begin ��ʼ
	* memset �� begin λ�ÿ�ʼ��һ������ end - begin + 1 ��Ԫ��
	* ����������������ͬ
	*/
	// int cnt = begin;
	
	/*
	* �������� cnt �� 0 ��ʼ
	* ��ʼ������λ�ô� begin ��ʼ
	* cnt ���յĳ��Ⱦ��� [begin, end] ֮��ĳ���
	* û����
	*/

	int cnt = 0; 

	while (begin1 <= end1 && begin2 <= end2)
	{
		// �����ȶ���
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

// �鲢����ǵݹ� - ����������
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
//				// �����ȶ���
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

// �鲢�ǵݹ� - ��������
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
			// ��������
			if (end1 >= n)
			{
				end1 = n - 1;
				// begin2 �� end2 ����Ϊ�����ڵ�����
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
			// ���Ծֲ�����
			//memcpy(a + i, tmp + i, sizeof(int) * (end2 - i + 1));
		}
		memcpy(a, tmp, sizeof(int) * n);
		rangeN *= 2;
	}
	free(tmp);
	tmp = NULL;
}
