#define _CRT_SECURE_NO_WARNINGS 1 

//什么是数据结构
//比如我们实现一些项目，需要在内存中将数据存储起来
//通讯录，要把每个人信息存起来

//存储方式 - 数组
//实际上也可以是链表，树，哈希表等等等

//选取什么数据结构写项目更加合适

//时间复杂度衡量一个算法的快慢
//空间复杂度衡量一个算法运行所需要的额外空间

//现在主要关注时间复杂度

//实操

//算法的时间复杂度是一个数学里面带有未知数的函数表达式
//比如冒泡排序，对100w个数排序
//10年前2核cpu，2g内存的机器
//今天8核cpu，8g内存的机器


//环境不同，具体运行时间就不同
//主要算执行次数

//比如算法1 100w个数排序 跑了100w次
//算法2 100w个数排序，跑了100w * 100w次

//脱离环境比较

//void Func1(int N)
//{
//	int count = 0;
//	for (int i = 0; i < N; ++i)
//	{
//		for (int j = 0; j < N; ++j)
//		{
//			++count;
//		}
//	}
//	for (int k = 0; k < 2 * N; ++k)
//	{
//		++count;
//	}
//	int M = 10;
//	while (M--)
//	{
//		++count;
//	}
//	printf("%d\n", count);
//}

//++cont执行了多少次？
//时间复杂度的函数式
//F(N) = N * N + 2 * N + 10

//给予不同的数值就会有不同的值

//再来观察一个细节
//比如N = 10 F(N) = 130 N^2 = 100        |
//N =100 F(N) = 10210 N^2 = 10000       |
//N = 1000 F(N) = 1002010 N^2 = 1000000  影响减小

//N越大，后两项对结果的影响越小
//那么一般我们计算算法算了多少次，那么零头就不太需要关注

//于是我们时间复杂度并不需要精确的计算执行次数，只要大概的执行次数

//大O渐进表示法

//当前代码时间复杂度：0(N^2)  N^2这一项能代表大概的结果

//void Func2(int N)
//{
//	int count = 0;
//	for (int k = 0; k < 2 * N; ++k)
//	{
//		++count;
//	}
//	int M = 10;
//	while (M--)
//	{
//		++count;
//	}
//	printf("%d\n", count);
//}

//时间复杂度0(N)
//2N + 10
//N越大10影响越小，去掉
//当N无限大时，2N和N无区别
//为O(N)


//void Func3(int N, int M)
//{
//	int count = 0;
//	for (int k = 0; k < M; ++k)
//	{
//		++count;
//	}
//	for (int k = 0; k < N; ++k)
//	{
//		++count;
//	}
//	printf("%d\n", count);
//}

//时间复杂度：O(M + N)
//一般情况下时间复杂度计算时未知数都是用N
//但是也可以是M、K等其他的

//如果M远大于N --> O(M)
//N远大于M --> O(N)
//M和N差不多大N --> O(M)/O(N)

//void Func4(int N)
//{
//	int count = 0;
//	for (int k = 0; k < 100; ++k)
//	{
//		++count;
//	}
//	printf("%d\n", count);
//}

//时间复杂度：O(1)
//时间复杂度用常数1替代所有常数

//比如平常题目中要求优化到O(1)
//不是代表算法运行1次，是常数次

const char* strchr(const char* str, int character);

