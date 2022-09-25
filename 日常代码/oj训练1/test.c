#define _CRT_SECURE_NO_WARNINGS 1 


//������ 17.04.��ʧ������

//˼·1�����򣬿���һ�����ǲ���ǰһ����+1
//qsort ���� ->ʱ�临�Ӷ�O(N*log2^N) ������O(N)

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

//˼·4����һ��ֵx = 0��x�ȸ�0-n������ֵ���
//x�ٸ������е�����ֵ������x����ȱ���Ǹ�����
int missingNumber(int* nums, int numsSize)
{
    int ans = 0;
    for (int i = 0; i < numsSize + 1; i++)
    {
        ans ^= i;
    }
    for (int i = 0; i < numsSize; i++)
    {
        ans ^= nums[i];
    }
    return ans;
}
