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