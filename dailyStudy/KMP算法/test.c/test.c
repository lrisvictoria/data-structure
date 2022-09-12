#define _CRT_SECURE_NO_WARNINGS 1 
//KMP
/*
str������
sub���Ӵ�
pos����ʼƥ���λ��
*/

#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <stdlib.h>

void GetNext(int* next, const char* sub)
{
	int lenSub = strlen(sub);
	next[0] = -1;
	next[1] = 0;
	int i = 2;//��ʼλ��
	int k = 0;//ǰһ���k
	
	while (i < lenSub)
	{
		if ((k == -1) || sub[i - 1] == sub[k])
		{
			next[i] = k + 1;
			i++;
			k++;
		}
		else
		{
			k = next[k];
		}
	}
}
int KMP(const char* str, const char* sub, int pos)
{
	assert(str && sub);
	int i = pos;//��ʼƥ���λ��
	int j = 0;//��¼�Ӵ��±�
	int lenStr = strlen(str), lenSub = strlen(sub);

	int* next = (int*)malloc(lenSub * sizeof(int));
	assert(next);

	GetNext(next, sub);

	while (i < lenStr && j < lenSub)
	{
		if (j == -1 || str[i] == sub[j])
		{
			i++;
			j++;
		}
		else
		{
			j = next[j];
		}
	}
	free(next);
	if (j >= lenSub)
	{
		return i - j;
	}
	return -1;
}

int main()
{
	printf("%d\n", KMP("ababcabcdabcde","abcd", 0));
	return 0;
}