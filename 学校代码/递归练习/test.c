#define _CRT_SECURE_NO_WARNINGS 1 

#include <stdio.h>

int sum(int num)
{
	if (num <= 0)
		return 0;
	else
		return num + sum(num - 1);
}
int main()
{
	int ret = sum(100);
	printf("%d\n", ret);
	return 0;
}
