#include <graphics.h>
#include <stdio.h>

#define MaxSize 10
#define DataType int

typedef struct
{
	DataType List[MaxSize];
	int sz;
}SeqList;

SeqList s;

// 1. 初始化
void ListInitiate(SeqList* L)
{
	L->sz = 0;
}

// 2. 求长度
int ListLength(SeqList L)
{
	return L.sz;
}

// 3. 插入
int ListInsert(SeqList* L, int i, DataType x)
{
	if (i < 0 || i > MaxSize)
	{
		printf("overflow\n");
		return -1;
	}
	if (i > L->sz)
	{
		printf("no suitable\n");
		return -2;
	}
	int j = 0;
	for (j = L->sz; j > i; j--)
	{
		L->List[j] = L->List[j - 1];
	}
	L->List[j] = x;
	L->sz++;
}

// 4. 删除
int ListDelete(SeqList* L, int i, DataType* x)
{
	int j;
	*x = L->List[i];
	for (j = i; j < L->sz; j++)
	{
		L->List[j] = L->List[j + 1];
	}
	L->sz--;
	return 1;
}

// 5. 取元素
int ListGet(SeqList L, int i, DataType* x)
{
	*x = L.List[i];
	return 1;
}

void show()
{
	cleardevice();// 清屏
	for (int i = 0 ; i < MaxSize; i++)
	{
		circle(50 + 75 * i, 100, 30);
		xyprintf(50 + 75 * i, 100, "%d", s.List[i]);
	}
}

int main()
{
	initgraph(800, 600);// 设定背景为800*600
	setcolor(BLUE);
	setbkcolor(WHITE);
	setrendermode(RENDER_MANUAL);// 渲染
	setbkmode(TRANSPARENT);// 设定背景为透明
	
	ListInitiate(&s);
	show();
	getch();
	ListInsert(&s, 0 , 11);
	show();
	getch();
	ListInsert(&s, 0, 5);
	show();
	getch();
	ListInsert(&s, 0, 7);
	show();
	getch();
	
	int x;
	ListDelete(&s, 1, &x);
	show();
	getch();
	return 0;
}
