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

SeqList s;//����һ���ṹ�����

//1.��ʼ������
void ListInitiate(SeqList* L)
{
	L->size = 0;
}

int ListInset(SeqList* L, int i, DataType x)
{
	int j;
	if (L->size >= MaxSize)
	{
		printf("˳��������޷�����\n");
		return 0;
	}
	else if (i < 0 || i > L->size)
	{
		printf("����i���Ϸ�!\n");
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

