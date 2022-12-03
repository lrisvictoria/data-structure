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

	while (begin < end)
	{
		// mini �� maxi ��Ҫһֱ����
		// ÿ�δ� begin ��ʼ��ɸѡ�����ֵ���±����Сֵ���±�
		int mini = begin, maxi = begin;
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
		}

		// �ֱ𽻻� begin �� mini ��ֵ / end �� maxi �� ֵ
		// ����������⴦��
		
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

void BubbleSort(int* a, int n)
{
	for (int j = 0; j < n - 1; j++)
	{
		int exchange = 0;
		// ����
		for (int i = 0; i < n - 1 - j; i++)
		{
			if (a[i] > a[i + 1])
			{
				Swap(&a[i], &a[i + 1]);
				exchange = 1;
			}
			
			// ���һ�������е�һ��û�н�����˵����������
			// ֱ����ת����һ��
			if (exchange == 0)
			{
				break;
			}
		}
	}
}

// ����
void QuickSort(int* a, int begin, int end)
{
	// ��� l > r ��ôû��Ҫ�ݹ飬ֱ�ӷ���
	if (begin >= end)
	{
		return;
	}

	int left = begin;
	int right = end;
	int keyi = left;

	// һ��û��Ҫ�ݹ�
	while (left < right)
	{
		// ��ֹԽ�磬�ұߴ��ڵ��� keyi ֵ�� --
		while (left < right && a[right] >= a[keyi])
		{
			right--;
		}

		// ��ֹԽ�磬���С�ڵ��� keyi ֵ�� ++
		while (left < right && a[left] <= a[keyi])
		{
			left++;
		}
		
		// ��ʱͣ������һ���ǽ���λ�õĵط�
		Swap(&a[left], &a[right]);
	}

	// һ����󣬽��� left �� keyi �±��Ӧ��ֵ
	// L �� R ������λ��һ��С�� keyi
	Swap(&a[left], &a[keyi]);
	
	// left ����µ� keyi
	keyi = left;

	// �ֱ�ݹ���ߺ��ұ�
	QuickSort(a, begin, keyi - 1);
	QuickSort(a, keyi + 1, end);
}