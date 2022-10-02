#define _CRT_SECURE_NO_WARNINGS 1 

#include "SeqList.h"

// 初始化
void SeqListInit(SL* ps)
{
	ps->a = NULL;
	ps->sz = ps->capacity = 0;
}

// 检查增容
void SeqListCheckCapacity(SL* ps)
{
	// 顺序表没有空间or顺序表空间不足
	if (ps->sz == ps->capacity)
	{
		// 没扩容，扩四个整形；空间不足，扩两倍
		int newcapacity = ps->capacity == 0 ? 4 : ps->capacity * 2;
		// realloc在起始地址为空指针时，和malloc一样效果
		SLDataType* tmp = (SLDataType*)realloc(ps->a, newcapacity * sizeof(SLDataType));
		if (tmp == NULL)
		{
			printf("realloc fail\n");
			exit(-1);
		}
		ps->a = tmp;
		ps->capacity = newcapacity;
	}
}

// 尾插
void SeqListPushBack(SL* ps, SLDataType x)
{
	//SeqListCheckCapacity(ps);// 检查增容
	//// 空间足够，直接在尾部插入
	//ps->a[ps->sz] = x;
	//ps->sz++;
	SeqListInsert(ps, ps->sz, x);
}

// 尾删
void SeqListPopBack(SL* ps)
{
	// 温柔处理
	//if (ps->sz > 0)// 不做出反应
	//{
	//	//ps->a[ps->sz - 1] = 0 ;// 不需要，sz标识顺序表的元素个数
	//	ps->sz--;
	//} 
	
	// 暴力处理
	//assert(ps->sz > 0);// 直接终止程序，报错
	//ps->sz--;

	SeqListErase(ps, ps->sz - 1);
}

// 头插
void SeqListPushFront(SL* ps, SLDataType x)
{
	//SeqListCheckCapacity(ps);// 检查增容

	//// 挪动数据
	//int end = ps->sz - 1; 
	//while (end >= 0)// 一直挪到0下标
	//{
	//	ps->a[end + 1] = ps->a[end];
	//	end--;
	//}
	//ps->a[0] = x;
	//ps->sz++;

	SeqListInsert(ps, 0, x);
}

// 头删
void SeqListPopFront(SL* ps)
{
	//assert(ps->sz > 0);

	//// 挪动数据
	//int begin = 1;
	//while (begin <= ps->sz - 1)
	//{
	//	ps->a[begin - 1] = ps->a[begin];
	//	begin++;
	//}
	////memmove(ps->a, ps->a + 1, (ps->sz - 1) * sizeof(SLDataType));

	//ps->sz--;
	SeqListErase(ps, 0);
}

// 查找
int SeqListFind(SL* ps, SLDataType x)
{
	// 只要找到一个就可以
	for (int i = 0; i < ps->sz; i++)
	{
		if (ps->a[i] == x)
		{
			return i;
		}
	}
	return -1;
} 

// 指定pos下标位置插入
void SeqListInsert(SL* ps, int pos, SLDataType x)
{
	// 温柔处理
	//if (pos > ps->sz || pos < 0)
	//{
	//	printf("pos invaild\n");
	//	return;
	//}
	
	// 暴力处理
	// 断言表达式为真，相安无事
	// 为假，直接报错
	// 这两个表达式只要有一个不满足条件，便报错
	assert(pos >= 0 && pos <= ps->sz);

	SeqListCheckCapacity(ps);// 检查增容

	int end = ps->sz - 1;
	// 从后往前依次向后挪
	while (end >= pos)
	{
		ps->a[end + 1] = ps->a[end];
		end--;
	}

	ps->a[pos] = x;
	ps->sz++;
}

// 删除pos位置的数据
void SeqListErase(SL* ps, int pos)
{
	assert(pos >= 0 && pos <= ps->sz - 1);  
	
	int begin = pos + 1;
	while (begin < ps->sz)
	{
		ps->a[begin - 1] = ps->a[begin];
		begin++;
	}
	ps->sz--;
}

// 修改pos位置的数据
void SeqListModify(SL* ps, int pos, int x)
{
	assert(pos >= 0 || pos <= ps->sz - 1);

	ps->a[pos] = x;
}

// 打印
void SeqListPrint(SL* ps)
{
	for (int i = 0; i < ps->sz; i++)
	{
		printf("%d ", ps->a[i]);
	}
	printf("\n");
}

// 销毁 
void SeqListDestory(SL* ps)
{
	free(ps->a);
	ps->a = NULL;
	ps->sz = ps->capacity = 0;
}