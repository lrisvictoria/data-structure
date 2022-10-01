#define _CRT_SECURE_NO_WARNINGS 1 

#include "SeqList.h"

// ��ʼ��
void SeqListInit(SL* ps)
{
	ps->a = NULL;
	ps->sz = ps->capacity = 0;
}

// �������
void SeqListCheckCapacity(SL* ps)
{
	// ˳���û�пռ�or˳���ռ䲻��
	if (ps->sz == ps->capacity)
	{
		// û���ݣ����ĸ����Σ��ռ䲻�㣬������
		int newcapacity = ps->capacity == 0 ? 4 : ps->capacity * 2;
		// realloc����ʼ��ַΪ��ָ��ʱ����mallocһ��Ч��
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

// β��
void SeqListPushBack(SL* ps, SLDataType x)
{
	SeqListCheckCapacity(ps);// �������
	// �ռ��㹻��ֱ����β������
	ps->a[ps->sz] = x;
	ps->sz++;
}

// βɾ
void SeqListPopBack(SL* ps)
{
	// ���ᴦ��
	//if (ps->sz > 0)// ��������Ӧ
	//{
	//	//ps->a[ps->sz - 1] = 0 ;// ����Ҫ��sz��ʶ˳����Ԫ�ظ���
	//	ps->sz--;
	//} 
	
	// ��������
	assert(ps->sz > 0);// ֱ����ֹ���򣬱���
	ps->sz--;
}

// ͷ��
void SeqListPushFront(SL* ps, SLDataType x)
{
	SeqListCheckCapacity(ps);// �������

	// Ų������
	int end = ps->sz - 1; 
	while (end >= 0)// һֱŲ��0�±�
	{
		ps->a[end + 1] = ps->a[end];
		end--;
	}
	ps->a[0] = x;
	ps->sz++;
}

// ͷɾ
void SeqListPopFront(SL* ps)
{
	assert(ps->sz > 0);

	// Ų������
	int begin = 1;
	while (begin <= ps->sz - 1)
	{
		ps->a[begin - 1] = ps->a[begin];
		begin++;
	}
	//memmove(ps->a, ps->a + 1, (ps->sz - 1) * sizeof(SLDataType));

	ps->sz--;
}

// ��ӡ
void SeqListPrint(SL* ps)
{
	for (int i = 0; i < ps->sz; i++)
	{
		printf("%d ", ps->a[i]);
	}
	printf("\n");
}

// ���� 
void SeqListDestory(SL* ps)
{
	free(ps->a);
	ps->a = NULL;
	ps->sz = ps->capacity = 0;
}