#define _CRT_SECURE_NO_WARNINGS 1 
#include <stdio.h>
#include <assert.h>
#include <string.h>
//�ַ���ƥ���㷨 BF 

/*
str������
sub���Ӵ�
����ֵ�������Ӵ����������е��±꣬��������ڷ���-1
*/

int BF(char* str, char* sub)
{
	assert(str && sub);//����

	if (str == NULL || sub == NULL)//�������Ӵ�Ϊ�գ�ֱ�ӷ���
	{
		return -1;
	}

	int lenStr = strlen(str), lenSub = strlen(sub);
	int i = 0, j = 0;

	while (i < lenStr && j < lenSub)//i��jͬʱΪ�棬�����Խ����ʣ�i >=lenStrΪ�Ӵ������ܴ����������������������᷵��-1
	{
		if (str[i] == sub[j])
		{
			i++;
			j++;
		}
		else
		{
			i = i - j + 1;//һ��Ҫ��ִ�У�����j����0
			j = 0;//j���»ص���ͷλ��
		}
	}
	if (j >= lenSub)//j�������Ӵ�
	{
		return i - j;
	}
	return -1;
}

int main()
{
	printf("%d\n", BF("ababcabcdabcde", "abcd"));//5
	printf("%d\n", BF("ababcabcdabcde", "abcdf"));//-1
	printf("%d\n", BF("ababcabcdabcde", "ab"));//0
	return 0;
}
