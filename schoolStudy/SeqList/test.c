#define _CRT_SECURE_NO_WARNINGS 1 

#include <stdio.h>

#define DataType int 
#define MaxSize 10

typedef struct
{
	DataType List[MaxSize];
	int sz;
}SeqList;

SeqList s;//创建一个结构体变量

//顺序表初始化
void ListInitiate(SeqList* L)
{
	L-> sz = 0;
}

//顺序表插入元素
int ListInsert(SeqList* L, int i, DataType x)//成功返回1，失败返回0，在第i个位置插入x
{
	int j = 0;
	if (L->sz >= MaxSize)
	{
		printf("顺序表已满，无法插入\n");
		return 0;//插入失败
	}
	else if (i < 0 || i >L->sz)
	{
		printf("参数i不合法\n");
		return 0;
	}
	else//插入元素
	{
		//从后向前依次移动
		for (j = L->sz; j > i; j--)
		{
			L->List[j] = L->List[j - 1];
		}
		L->List[i] = x;//插入x
		L->sz++;//当前顺表元素个数增加
		return 1;
	}
}

//顺序表删除元素
int ListDelete(SeqList* L, int i, DataType* x)//从第i个位置删除，并将数据保存到x中，成功返回1，失败返回0
{
	int j = 0;
	if (L->sz <= 0)
	{
		printf("顺序表无元素可删\n");
		return 0;
	}
	else if (i < 0 || i > L->sz - 1)
	{
		printf("参数i不合法\n");
		return 0;
	}
	else//删除
	{
		*x = L->List[i];//保存删除的元素到x中
		//从前向后依次前移
		for (j = i + 1; j <= L->sz - 1; j++)
		{
			L->List[j - 1] = L->List[j];
		}
		L->sz--;//元素个数减少
		return 1;
	}
}
int main()
{
	ListInitiate(&s);
	ListInsert(&s, 0, 18);
	ListInsert(&s, 1, 1);
	ListInsert(&s, 0, 7);

	int x = 0;//保存我删除的数据
	ListDelete(&s, 1, &x);
	return 0;
}