#define _CRT_SECURE_NO_WARNINGS 1 

#include <stdio.h>
#include <stdlib.h>

//面试题 17.04.消失的数字

//思路1：排序，看后一个数是不是前一个数+1
//qsort 快排 ->时间复杂度O(N*log2^N) 不满足O(N)
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


//思路2：0+1+2+3+...+n - (a[0] + a[1] + a[2]... + a[n - 1])
//时间复杂度O(N) 空间复杂度：O(1)
//int missingNumber(int* nums, int numsSize)
//{
//    int sum = 0;
//    for (int i = 0; i < numsSize; i++)
//    {
//        sum += nums[i];
//    }
//    return ((numsSize * (numsSize + 1)) / 2) - sum;
//}

//思路3：建立一个数组，在对应下标写下对应元素
//那个位置没有写，那么就说明是这个数
//空间复杂度O(N) 时间复杂度：O(N)

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

//思路4：给一个值x = 0，x先跟0-n的所有值异或
//x再跟数组中的所有值异或，最后x就是缺的那个数字
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


//189. 轮转数组
//思路1：暴力求解
//qosrt排序后，判断前后两个值是否为1
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

//思路2：创建数组，以空间换时间
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

//思路3：三步翻转法
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