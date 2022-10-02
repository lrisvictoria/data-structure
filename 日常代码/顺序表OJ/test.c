#define _CRT_SECURE_NO_WARNINGS 1 

// 27. 移除元素

// 思路1：找到所有的val，一次挪动数据覆盖删除
// 时间复杂度：O(N^2)
// 最坏的情况：数组中大部分值全部是val
// 空间复杂度：O(N)

//int removeElement(int* nums, int numsSize, int val)
//{
//    for (int i = 0; i < numsSize; i++)
//    {
//        if (nums[i] == val)
//        {
//            for (int j = i; j < numsSize - 1; j++)
//            {
//                nums[j] = nums[j + 1];
//            }
//            numsSize--;
//            i--;
//        }
//    }
//    return numsSize;
//}

// 能否将时间复杂度优化到O(N)?

// 思路2：依次遍历nums数组，把不是val的数据放到另一个数组中
// 再把tmp数组的值拷贝回去
// 时间复杂度：O(N) 空间复杂度：O(N)

//int removeElement(int* nums, int numsSize, int val)
//{
//    if (!numsSize)
//    {
//        return 0;
//    }
//
//    int newArr[numsSize];
//    int count = 0;
//    // 存入数据
//    for (int i = 0; i < numsSize; i++)
//    {
//        if (nums[i] != val)
//        {
//            newArr[count++] = nums[i];
//        }
//    }
//    // 改数据
//    for (int i = 0; i < count; i++)
//    {
//        nums[i] = newArr[i];
//    }
//
//    return count;
//}


// 能否将空间复杂度优化到O(1)？
// 思路3：双指针
// src查找!=val的数，找到了就把数据覆盖到dest处，src++，dest++
// 找到==val的数，src++，dest不动
// 直到src >= numsSize

//int removeElement(int* nums, int numsSize, int val)
//{
//    int dest = 0, src = 0;
//    while (src < numsSize)
//    {
//        if (nums[src] != val)
//        {
//            nums[dest] = nums[src];
//            dest++;
//        }
//        src++;
//    }
//    return dest;
//}

// 26. 删除有序数组中的重复项

// 思路1：遍历数组，如果此元素和下一个元素相等，则进行覆盖，数组长度-1
// 并回退重新判断，注意下边界问题
// 时间复杂度：O(N^2) 空间复杂度O(1)

//int removeDuplicates(int* nums, int numsSize)
//{
//    for (int i = 0; i < numsSize - 1; i++)
//    {
//        if (nums[i] == nums[i + 1])
//        {
//            for (int j = i; j < numsSize - 1; j++)
//            {
//                nums[j] = nums[j + 1];
//            }
//            numsSize--;
//            i--;// 回退
//        }
//    }
//    return numsSize;
//}

// 思路2：双指针
//
// 1. 三下标
// 给定i = 0和j = 0，i用来规定左边界，j用来找新的边界
// nums[i] == nums[j] 说明没有找到新的边界，j++
// nums[i] != nums[j] 找到新的边界，说明上一个数字的重复部分已经跳过
// 用dest记录i位置的元素，dest++，i到新的边界，i = j，j重新开始查找
// 最后由于j的越界问题，所以需额外处理最后一个元素
// 返回dest即可
// 时间复杂度：O(N) 空间复杂度：O(1)

//int removeDuplicates(int* nums, int numsSize)
//{
//    int i = 0, j = 1;
//    int dest = 0;
//    while (j < numsSize)
//    {
//        if (nums[i] == nums[j])
//        {
//            j++;
//        }
//        else
//        {
//            nums[dest++] = nums[i];
//            i = j;
//            j++;
//        }
//    }
//    nums[dest++] = nums[i];
//    return dest;
//}

// 2下标
// 给定fast = 0，slow = 0，fast用来遍历数组
// nums[slow] == nums[fast] --> fast++，说明没找到新的数字，fast++
// nums[slow] != nums[fast] --> nums[++slow] = nums[fast++]
// slow起始位置一定不是重复的数字，所以在1下标处放置新数字
// 最后返回dest + 1(前置++，没有包含0下标)
// 时间复杂度：O(N) 空间复杂度：O(1)

// for循环
//int removeDuplicates(int* nums, int numsSize)
//{
//    int j = 0;// slow
//    for (int i = 0; i < numsSize; i++)// fast
//    {
//        if (nums[i] != nums[j])
//        {
//            nums[++j] = nums[i];
//        }
//    }
//    return j + 1;
//}

// while循环
//int removeDuplicates(int* nums, int numsSize) {
//    int fast = 0;
//    int slow = 0;
//    while (fast < numsSize)
//    {
//        if (nums[slow] == nums[fast])
//        {
//            fast++;
//        }
//        else
//        {
//            nums[++slow] = nums[fast++];
//        }
//    }
//    return slow + 1;
//}

// 88. 合并两个有序数组

// 思路1：创建一个新数组，遍历两个数组，将元素按大小顺序放入新数组
// 没放完的元素，肯定比新数组中最大的数字大，在依次放入即可
// 时间复杂度：O(M + N) 空间复杂度：O(M + N)

//void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n)
//{
//    int* newArr = (int*)malloc((m + n) * sizeof(int));
//    int start1 = 0, start2 = 0;
//    int count = 0;
//    while (start1 < m && start2 < n)
//    {
//        if (nums1[start1] < nums2[start2])
//        {
//            newArr[count++] = nums1[start1++];
//        }
//        else
//        {
//            newArr[count++] = nums2[start2++];
//        }
//    }
//    if (start1 == m)
//    {
//        for (; start2 < n; start2++)
//        {
//            newArr[count++] = nums2[start2];
//        }
//    }
//    else
//    {
//        for (; start1 < m; start1++)
//        {
//            newArr[count++] = nums1[start1];
//        }
//    }
//    for (int i = 0; i < count; i++)
//    {
//        nums1[i] = newArr[i];
//    }

// 思路2：给定end1和end2下标，分别对应nums1有效数据最后一位和nums2最后一位
// 再给定一个end下标
// 将比较end1和end2对应元素，将大的从后往前重新放入nums1数组
// 注意遍历完成数组未放置完毕的情况
// 时间复杂度：O(M + N) 空间复杂度：O(1)
// 最坏情况：end1放置完毕，end2一个没放，当前总执行次数：M + N

void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n)
{
    int end1 = m - 1, end2 = n - 1;
    int end = m + n - 1;
    while (end1 >= 0 && end2 >= 0)
    {
        if (nums1[end1] > nums2[end2])
        {
            nums1[end--] = nums1[end1--];
        }
        else
        {
            nums1[end--] = nums2[end2--];
        }
    }
    while (end2 >= 0)
    {
        nums1[end--] = nums2[end2--];
    }
}
