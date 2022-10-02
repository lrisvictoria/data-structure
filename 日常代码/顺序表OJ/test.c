#define _CRT_SECURE_NO_WARNINGS 1 

// 27. �Ƴ�Ԫ��

// ˼·1���ҵ����е�val��һ��Ų�����ݸ���ɾ��
// ʱ�临�Ӷȣ�O(N^2)
// �������������д󲿷�ֵȫ����val
// �ռ临�Ӷȣ�O(N)

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

// �ܷ�ʱ�临�Ӷ��Ż���O(N)?

// ˼·2�����α���nums���飬�Ѳ���val�����ݷŵ���һ��������
// �ٰ�tmp�����ֵ������ȥ
// ʱ�临�Ӷȣ�O(N) �ռ临�Ӷȣ�O(N)

//int removeElement(int* nums, int numsSize, int val)
//{
//    if (!numsSize)
//    {
//        return 0;
//    }
//
//    int newArr[numsSize];
//    int count = 0;
//    // ��������
//    for (int i = 0; i < numsSize; i++)
//    {
//        if (nums[i] != val)
//        {
//            newArr[count++] = nums[i];
//        }
//    }
//    // ������
//    for (int i = 0; i < count; i++)
//    {
//        nums[i] = newArr[i];
//    }
//
//    return count;
//}


// �ܷ񽫿ռ临�Ӷ��Ż���O(1)��
// ˼·3��˫ָ��
// src����!=val�������ҵ��˾Ͱ����ݸ��ǵ�dest����src++��dest++
// �ҵ�==val������src++��dest����
// ֱ��src >= numsSize

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

// 26. ɾ�����������е��ظ���

// ˼·1���������飬�����Ԫ�غ���һ��Ԫ����ȣ�����и��ǣ����鳤��-1
// �����������жϣ�ע���±߽�����
// ʱ�临�Ӷȣ�O(N^2) �ռ临�Ӷ�O(1)

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
//            i--;// ����
//        }
//    }
//    return numsSize;
//}

// ˼·2��˫ָ��
//
// 1. ���±�
// ����i = 0��j = 0��i�����涨��߽磬j�������µı߽�
// nums[i] == nums[j] ˵��û���ҵ��µı߽磬j++
// nums[i] != nums[j] �ҵ��µı߽磬˵����һ�����ֵ��ظ������Ѿ�����
// ��dest��¼iλ�õ�Ԫ�أ�dest++��i���µı߽磬i = j��j���¿�ʼ����
// �������j��Խ�����⣬��������⴦�����һ��Ԫ��
// ����dest����
// ʱ�临�Ӷȣ�O(N) �ռ临�Ӷȣ�O(1)

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

// 2�±�
// ����fast = 0��slow = 0��fast������������
// nums[slow] == nums[fast] --> fast++��˵��û�ҵ��µ����֣�fast++
// nums[slow] != nums[fast] --> nums[++slow] = nums[fast++]
// slow��ʼλ��һ�������ظ������֣�������1�±괦����������
// ��󷵻�dest + 1(ǰ��++��û�а���0�±�)
// ʱ�临�Ӷȣ�O(N) �ռ临�Ӷȣ�O(1)

// forѭ��
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

// whileѭ��
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

// 88. �ϲ�������������

// ˼·1������һ�������飬�����������飬��Ԫ�ذ���С˳�����������
// û�����Ԫ�أ��϶������������������ִ������η��뼴��
// ʱ�临�Ӷȣ�O(M + N) �ռ临�Ӷȣ�O(M + N)

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

// ˼·2������end1��end2�±꣬�ֱ��Ӧnums1��Ч�������һλ��nums2���һλ
// �ٸ���һ��end�±�
// ���Ƚ�end1��end2��ӦԪ�أ�����ĴӺ���ǰ���·���nums1����
// ע������������δ������ϵ����
// ʱ�临�Ӷȣ�O(M + N) �ռ临�Ӷȣ�O(1)
// ������end1������ϣ�end2һ��û�ţ���ǰ��ִ�д�����M + N

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
