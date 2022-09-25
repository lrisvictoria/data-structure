#define _CRT_SECURE_NO_WARNINGS 1 
#include <stdio.h>
#include <assert.h>
#include <string.h>
//字符串匹配算法 BF 

/*
str：主串
sub：子串
返回值：返回子串在主串当中的下标，如果不存在返回-1
*/

int BF(char* str, char* sub)
{
	assert(str && sub);//断言

	if (str == NULL || sub == NULL)//主串或子串为空，直接返回
	{
		return -1;
	}

	int lenStr = strlen(str), lenSub = strlen(sub);
	int i = 0, j = 0;

	while (i < lenStr && j < lenSub)//i，j同时为真，否则会越界访问，i >=lenStr为子串不可能存在于主串的情况，在下面会返回-1
	{
		if (str[i] == sub[j])
		{
			i++;
			j++;
		}
		else
		{
			i = i - j + 1;//一定要先执行，否则j会置0
			j = 0;//j重新回到开头位置
		}
	}
	if (j >= lenSub)//j走完了子串
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
