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
		// ���ж��鲢��
		for (int i = 0; i < n - gap; i++)
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
		AdjustDown(a, n, 0);
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
	int begin = 0, end = n - 1;
	int mini = begin, maxi = end;

	while (begin < end)
	{
		for (int i = begin + 1; i <= end; i++)
		{
			// ��� i ��ֵ С�� begin(��Сֵλ��) ���ڴ�ֵ������ mini
			if (a[i] < a[mini])
			{
				mini = i;
			}

			// ��� i ��ֵ ���� end(���ֵλ��) ���ڴ�ֵ������maxi
			if (a[i] > a[maxi])
			{
				maxi = i;
			}

			// �ֱ𽻻� begin �� mini ��ֵ / end �� maxi �� ֵ
			// ����������⴦��
		}
		Swap(&a[begin], &a[mini]);
		if (begin == maxi)
		{
			maxi = mini;
		}
		Swap(&a[end], &a[maxi]);

		// ���� begin �� end
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