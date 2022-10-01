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


// �ܷ񽫿ռ临�Ӷ��Ż���O(1)��

int removeElement(int* nums, int numsSize, int val)
{
    int src = 0, dest = 0;
    while (src < numsSize)
    {
        if (nums[src] != val)
        {
            nums[dest] = nums[src];
            dest++;
            src++;
        }
        else
        {
            src++;
        }
    }
    return dest;
}