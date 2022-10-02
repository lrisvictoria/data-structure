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