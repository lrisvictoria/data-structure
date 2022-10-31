#define _CRT_SECURE_NO_WARNINGS 1 

// 27. �Ƴ�Ԫ��
// ˼·2���Ѳ�����ɾ���������ݷ����������У�������ԭ����

//int removeElement(int* nums, int numsSize, int val)
//{
//    if (numsSize == 0)
//        return 0;
//    int tmp[numsSize];
//    int dst = 0, src = 0;
//    for (int i = 0; i < numsSize; i++)
//    {
//        if (nums[i] != val)
//        {
//            tmp[dst++] = nums[i];
//        }
//    }
//    for (int i = 0; i < dst; i++)
//    {
//        nums[i] = tmp[i];
//    }
//    return dst;
//}

// ˼·3��˫ָ��

//int removeElement(int* nums, int numsSize, int val)
//{
//    int src = 0, dst = 0;
//
//    while (src < numsSize)
//    {
//        if (nums[src] != val)
//        {
//            nums[dst++] = nums[src];
//        }
//        src++;
//    }
//    return dst;
//}

// 26. ɾ�����������е��ظ���

//int removeDuplicates(int* nums, int numsSize)
//{
//    int dst = 0, src = 0;
//    while (src < numsSize)
//    {
//        if (nums[src] == nums[dst])
//        {
//            src++;
//        }
//        else
//        {
//            nums[++dst] = nums[src++];
//        }
//    }
//    return dst + 1;
//}

// 88. �ϲ�������������

void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n)
{
    int end1 = m - 1, end2 = n - 1, end = m + n - 1;
    while (end1 >= 0 && end2 >= 0)
    {
        if (nums1[end1] < nums2[end2])
        {
            nums1[end--] = nums2[end2--];
        }
        else
        {
            nums1[end--] = nums1[end1--];
        }
    }
    while (end2 >= 0)
    {
        nums1[end--] = nums2[end2--];
    }
}