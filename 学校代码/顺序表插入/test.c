#define _CRT_SECURE_NO_WARNINGS 

#include <stdio.h>

//
#define DataType int
#define MaxSize 7

typedef struct
{
	DataType List[MaxSize];
	int size;
}SeqList;

SeqList s;//创建一个结构体变量

//1.初始化函数
void ListInitiate(SeqList* L)
{
	L->size = 0;
}

int ListInset(SeqList* L, int i, DataType x)
{
	int j;
	if (L->size >= MaxSize)
	{
		printf("顺序表已满无法插入\n");
		return 0;
	}
	else if (i < 0 || i > L->size)
	{
		printf("参数i不合法!\n");
		return 0;
	}
	else
	{
		for (j = L->size; j > i; j--)
		{
			L->List[j] = L->List[j - 1];
		}
		L->List[i] = x;
		L->size++;
		return 1;
	}
}

int main()
{
	ListInitiate(&s);
	ListInset(&s, 0, 7);
	ListInset(&s, 1, 6);

	return 0;
}

