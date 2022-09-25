#define _CRT_SECURE_NO_WARNINGS 1 

#include <stdio.h>

#define DataType int 
#define MaxSize 10

typedef struct
{
	DataType List[MaxSize];
	int sz;
}SeqList;

SeqList s;//����һ���ṹ�����

//˳����ʼ��
void ListInitiate(SeqList* L)
{
	L-> sz = 0;
}

//˳������Ԫ��
int ListInsert(SeqList* L, int i, DataType x)//�ɹ�����1��ʧ�ܷ���0���ڵ�i��λ�ò���x
{
	int j = 0;
	if (L->sz >= MaxSize)
	{
		printf("˳����������޷�����\n");
		return 0;//����ʧ��
	}
	else if (i < 0 || i >L->sz)
	{
		printf("����i���Ϸ�\n");
		return 0;
	}
	else//����Ԫ��
	{
		//�Ӻ���ǰ�����ƶ�
		for (j = L->sz; j > i; j--)
		{
			L->List[j] = L->List[j - 1];
		}
		L->List[i] = x;//����x
		L->sz++;//��ǰ˳��Ԫ�ظ�������
		return 1;
	}
}

//˳���ɾ��Ԫ��
int ListDelete(SeqList* L, int i, DataType* x)//�ӵ�i��λ��ɾ�����������ݱ��浽x�У��ɹ�����1��ʧ�ܷ���0
{
	int j = 0;
	if (L->sz <= 0)
	{
		printf("˳�����Ԫ�ؿ�ɾ\n");
		return 0;
	}
	else if (i < 0 || i > L->sz - 1)
	{
		printf("����i���Ϸ�\n");
		return 0;
	}
	else//ɾ��
	{
		*x = L->List[i];//����ɾ����Ԫ�ص�x��
		//��ǰ�������ǰ��
		for (j = i + 1; j <= L->sz - 1; j++)
		{
			L->List[j - 1] = L->List[j];
		}
		L->sz--;//Ԫ�ظ�������
		return 1;
	}
}
int main()
{
	ListInitiate(&s);
	ListInsert(&s, 0, 18);
	ListInsert(&s, 1, 1);
	ListInsert(&s, 0, 7);

	int x = 0;//������ɾ��������
	ListDelete(&s, 1, &x);
	return 0;
}