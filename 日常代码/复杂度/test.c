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
//在字符串里查找字符

//大概写法

//while (*str)
//{
//	if (*str == character)
//		return str;
//	else
//		++str;
//}

//比如字符串为 hello world空格
//假设查找的是h 1

//假设查找的是w N/2
//假设查找的是d N

//分三种情况

//时间复杂度是一个悲观的预期，当一个算法随着输入不同
//时间复杂度不同，时间复杂度做一个悲观的预期
//看最坏的情况

//认为时间复杂度是O(N)
//相当于结果只会有惊喜，因为我们使用的是最坏情况

//冒泡排序的时间复杂度
//void BubbleSort(int* a, int n)
//{
//	assert(a);
//	for (size_t end = n; end > 0; --end)
//	{
//		int exchange = 0;
//		for (size_t i = 1; i < end; ++i)
//		{
//			if (a[i - 1] > a[i])
//			{
//				Swap(&a[i - 1], &a[i]);
//				exchange = 1;
//			}
//		}
//		if (exchange == 0)
//			break;
//	}
//}
//等差数列
//N - 1
//N - 2
//N - 3
//...
//N*(N-1)/2
//看阶数最高的一项
//F(N) = O(N^2)

//二分查找算法的时间复杂度？

//int BinarySearch(int* a, int n, int x)
//{
//	assert(a);
//	int begin = 0;
//	int end = n - 1;
//	while (begin < end)
//	{
//		int mid = begin + ((end - begin) >> 1);
//		if (a[mid] < x)
//			begin = mid + 1;
//		else if (a[mid] > x)
//			end = mid;
//		else
//			return mid;
//	} 
//	return -1;
//}

//算时间复杂度不能只看是几层循环，而要去看他的思想

//时间复杂度：O(N) //err

//O*(log2^N)//log 2底N

//最好的情况：O(1)
//最坏的情况：
//反着推导
//当查找完毕，把它当成一张纸 
//当left == right时，这为1次
//查找完成后每展开依次就是2次，
//然后次数就是2^n，从最里面一层开始，每一层展开都*2
//1*2*2*2..=N
//2^X = N
//X = log2^N

//正向推导
//分隔空间
//N/2/2/2...=1
//2^X = N 

//时间复杂度O(log2^N)

//二分查找算法是一个非常牛的算法
//N个数中查找，大概查找次数
//1000     10
//100w     20
//10亿     30

//想象一下用二分查找，查找我们中国同胞
//2^31约等于20亿
//也就相当于我们最差情况下只要31次就能查找到这个人
//缺点就是二分查找需要有序，排序的代价高，放到内存中也很大


//递归计算阶乘的时间复杂度？

//long long Factorial(size_t N)
//{
//	return N < 2 ? N : Factorial(N - 1) * N;
//}

//递归算法：递归次数*每次递归调用的次数
//O(N)
 

// 计算斐波那契递归Fibonacci的时间复杂度？
//long long Fibonacci(size_t N)
//{
//	return N < 2 ? N : Fibonacci(N - 1) + Fibonacci(N - 2);
//}

//相当于细胞分裂的过程
//假设每一层都是满的，则从2^0逐渐到2^n-1
//Fib(N) =2^0 + 2^1 + 2^2 + ...+ 2^(N-1) - X
//X是因为右边一些递归部分会提前结束
//前部分和为2^N -1

//当数据够大时，X远小于2^N
//时间复杂度：0(2^N)



//空间复杂度
//空间复杂度算的是变量的个数
//也是大O渐进表示法


//void BubbleSort(int* a, int n)
//{
//	assert(a);
//	for (size_t end = n; end > 0; --end)
//	{
//		int exchange = 0;
//		for (size_t i = 1; i < end; ++i)
//		{
//			if (a[i - 1] > a[i])
//			{
//				Swap(&a[i - 1], &a[i]);
//				exchange = 1;
//			}
//		}
//		if (exchange == 0)
//			break;
//	}
//}

//O(1)
//三个变量一个exchange，一个end，一个i，每次i空间销毁，下次还是使用这块空间

//long long* Fibonacci(size_t n)
//{
//	if (n == 0)
//		return NULL;
//	long long* fibArray =
//		(long long*)malloc((n + 1) * sizeof(long long));
//	fibArray[0] = 0;
//	fibArray[1] = 1; for (int i = 2; i <= n; ++i)
//	{
//		fibArray[i] = fibArray[i - 1] + fibArray[i - 2];
//	}
//	return fibArray;
//}

//空间复杂度O(N)

//long long Factorial(size_t N)
//{
//	return N < 2 ? N : Factorial(N - 1) * N;
//}
//空间复杂度O(N)
//递归的深度为N，建立了N个栈帧
//每个递归的变量看做O(1)

//斐波那契数列递归算法的空间复杂度
long long Fibonacci(size_t N)
{
	return N < 2 ? N : Fibonacci(N - 1) + Fibonacci(N - 2);
}
//O(N)
//空间是可以重复利用的，不累计的
//时间是一去不复返的，累计的

//递归的深度是n - 1，为O(N)
//斐波那契额数列会先算Fib(N-1)再算Fib(N-2)
//算Fib(N-1)会一条直线直接算下去，然后递归回去
//当Fib(N-1)的递归调用完毕之后，调用另外一遍的递归
//使用的是同一块空间，空间重复使用了

//递归是一条路递归完了回去递归另外一条路