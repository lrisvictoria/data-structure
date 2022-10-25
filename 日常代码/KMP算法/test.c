#define _CRT_SECURE_NO_WARNINGS 1 
//KMP
/*
str：主串
sub：子串
pos：开始匹配的位置
*/

#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <stdlib.h>

void GetNextVal(int* next, const char* sub)
{
	int i = 2;
	int lenSub = strlen(sub);
	
	while (i < lenSub)
	{
		if (sub[i] == sub[next[i]])
		{
			next[i] = next[next[i]];
		}
		i++;
	}
}
void GetNext(int* next, const char* sub)
{
	assert(next && sub);
	int lenSub = strlen(sub);
	next[0] = -1;
	if (lenSub == 1)
	{
		return;
	}
	next[1] = 0;
	int i = 2;//开始位置
	int k = 0;//前一项的k
	
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

	GetNextVal(next, sub);
}
int KMP(const char* str, const char* sub, int pos)
{
	assert(str && sub);
	int i = pos;//开始匹配的位置
	int j = 0;//记录子串下标
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
	printf("%d\n", KMP("abc", "c", 0));
	return 0;
}
