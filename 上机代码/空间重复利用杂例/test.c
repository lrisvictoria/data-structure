#define _CRT_SECURE_NO_WARNINGS 1 

#include <stdio.h>

void Func1()
{
	int a = 0;
	printf("%p\n", &a);
}

void Func2()
{
	int b = 0;
	printf("%p\n", &b);
}

int main()
{
	Func1();
	Func2();

	return 0;
}

// Func1 中 a 的地址和 Func2 中 b 的地址相同
// 调用 Func1 结束后，Fuc1 空间被释放
// 调用 Func2 时，创建的函数栈帧正好和 Func1 同一个位置
// 因为 Func1 和 Func2 一样，都是开辟了一个局部变量
// 由此证明空间是可以重复利用的！！！
// 证明这个结论后，我们就可以知晓为什么斐波那契数列的空间复杂度为 O(N)