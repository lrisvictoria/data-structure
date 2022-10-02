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
	//SeqListCheckCapacity(ps);// �������
	//// �ռ��㹻��ֱ����β������
	//ps->a[ps->sz] = x;
	//ps->sz++;
	SeqListInsert(ps, ps->sz, x);
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
	//assert(ps->sz > 0);// ֱ����ֹ���򣬱���
	//ps->sz--;

	SeqListErase(ps, ps->sz - 1);
}

// ͷ��
void SeqListPushFront(SL* ps, SLDataType x)
{
	//SeqListCheckCapacity(ps);// �������

	//// Ų������
	//int end = ps->sz - 1; 
	//while (end >= 0)// һֱŲ��0�±�
	//{
	//	ps->a[end + 1] = ps->a[end];
	//	end--;
	//}
	//ps->a[0] = x;
	//ps->sz++;

	SeqListInsert(ps, 0, x);
}

// ͷɾ
void SeqListPopFront(SL* ps)
{
	//assert(ps->sz > 0);

	//// Ų������
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

// ����
int SeqListFind(SL* ps, SLDataType x)
{
	// ֻҪ�ҵ�һ���Ϳ���
	for (int i = 0; i < ps->sz; i++)
	{
		if (ps->a[i] == x)
		{
			return i;
		}
	}
	return -1;
} 

// ָ��pos�±�λ�ò���
void SeqListInsert(SL* ps, int pos, SLDataType x)
{
	// ���ᴦ��
	//if (pos > ps->sz || pos < 0)
	//{
	//	printf("pos invaild\n");
	//	return;
	//}
	
	// ��������
	// ���Ա��ʽΪ�棬�ల����
	// Ϊ�٣�ֱ�ӱ���
	// ���������ʽֻҪ��һ���������������㱨��
	assert(pos >= 0 && pos <= ps->sz);

	SeqListCheckCapacity(ps);// �������

	int end = ps->sz - 1;
	// �Ӻ���ǰ�������Ų
	while (end >= pos)
	{
		ps->a[end + 1] = ps->a[end];
		end--;
	}

	ps->a[pos] = x;
	ps->sz++;
}

// ɾ��posλ�õ�����
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

// �޸�posλ�õ�����
void SeqListModify(SL* ps, int pos, int x)
{
	assert(pos >= 0 || pos <= ps->sz - 1);

	ps->a[pos] = x;
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