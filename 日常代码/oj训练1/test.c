#define _CRT_SECURE_NO_WARNINGS 1 

#include <stdio.h>
#include <stdlib.h>

//������ 17.04.��ʧ������

//˼·1�����򣬿���һ�����ǲ���ǰһ����+1
//qsort ���� ->ʱ�临�Ӷ�O(N*log2^N) ������O(N)
//int cmp(const void* e1, const void* e2)
//{
//	return *(int*)e1 - *(int*)e2;
//}
//
//int missingNumber(int* nums, int numsSize)
//{
//	int ans = 0;
//	qsort(nums, numsSize, sizeof(int), cmp);
//	for (int i = 0; i < numsSize - 1; i++)
//	{
//		if ((nums[i + 1] - nums[i]) != 1)
//		{
//			return i + 1;
//		}
//	}
//	return ans;
//}


//˼·2��0+1+2+3+...+n - (a[0] + a[1] + a[2]... + a[n - 1])
//ʱ�临�Ӷ�O(N) �ռ临�Ӷȣ�O(1)
//int missingNumber(int* nums, int numsSize)
//{
//    int sum = 0;
//    for (int i = 0; i < numsSize; i++)
//    {
//        sum += nums[i];
//    }
//    return ((numsSize * (numsSize + 1)) / 2) - sum;
//}

//˼·3������һ�����飬�ڶ�Ӧ�±�д�¶�ӦԪ��
//�Ǹ�λ��û��д����ô��˵���������
//�ռ临�Ӷ�O(N) ʱ�临�Ӷȣ�O(N)

//int missingNumber(int* nums, int numsSize)
//{
//    int res = 0;
//    int* newArr = (int*)calloc((numsSize + 1), sizeof(int));
//    for (int i = 0; i < numsSize; i++)
//    {
//        newArr[nums[i]] = nums[i];
//    }
//    for (int i = 0; i < numsSize + 1; i++)
//    {
//        if (newArr[i] == 0 && i)
//        {
//            return i;
//        }
//    }
//    return res;
//}

//˼·4����һ��ֵx = 0��x�ȸ�0-n������ֵ���
//x�ٸ������е�����ֵ������x����ȱ���Ǹ�����
//int missingNumber(int* nums, int numsSize)
//{
//    int ans = 0;
//    for (int i = 0; i < numsSize + 1; i++)
//    {
//        ans ^= i;
//    }
//    for (int i = 0; i < numsSize; i++)
//    {
//        ans ^= nums[i];
//    }
//    return ans;
//}


//189. ��ת����
//˼·1���������
//qosrt������ж�ǰ������ֵ�Ƿ�Ϊ1
//void rotate(int* nums, int numsSize, int k)
//{
//    if (k >= numsSize)
//    {
//        k %= numsSize;
//    }
//    for (int i = 0; i < k; i++)
//    {
//        int tmp = nums[numsSize - 1];
//        for (int j = numsSize - 1; j >= 1; j--)
//        {
//            nums[j] = nums[j - 1];
//        }
//        nums[0] = tmp;
//    }
//}

//˼·2���������飬�Կռ任ʱ��
//void rotate(int* nums, int numsSize, int k)
//{
//    int newArr[numsSize];
//    for (int i = 0; i < numsSize; i++)
//    {
//        newArr[(i + k) % numsSize] = nums[i];
//    }
//    for (int i = 0; i < numsSize; i++)
//    {
//        nums[i] = newArr[i];
//    }
//}

//˼·3��������ת��
void Reverse(int* nums, int left, int right)
{
    while (left < right)
    {
        int tmp = nums[left];
        nums[left] = nums[right];
        nums[right] = tmp;
        left++;
        right--;
    }
}
void rotate(int* nums, int numsSize, int k)
{
    if (k >= numsSize)
        k %= numsSize;
    Reverse(nums, 0, numsSize - k - 1);
    Reverse(nums, numsSize - k, numsSize - 1);
    Reverse(nums, 0, numsSize - 1);
}