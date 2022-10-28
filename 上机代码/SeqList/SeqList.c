#define _CRT_SECURE_NO_WARNINGS 1 

#include "SeqList.h"

void SeqListInit(SL* ps)
{
	assert(ps);
	ps->a = NULL;
	ps->sz = ps->capacity = 0;
}

void SeqListCheckCapacity(SL* ps)
{
	assert(ps);
	if (ps->capacity == ps->sz)
	{
		int newcapacity = ps->capacity == 0 ? 4 : ps->capacity * 2;
		SLDataType* tmp = (SLDataType*)realloc(ps->a, sizeof(SLDataType) * newcapacity);
		if (tmp == NULL)
		{
			perror("realloc fail");
			exit(-1);
		}
		ps->a = tmp;
		ps->capacity = newcapacity;
	}
}

void SeqListPushBack(SL* ps, SLDataType x)
{
	assert(ps);
	SeqListCheckCapacity(ps);
	ps->a[ps->sz++] = x;
}

void SeqListPopBack(SL* ps)
{
	assert(ps);

	assert(ps->sz > 0);
	ps->sz--;
}

void SeqListPushFront(SL* ps, SLDataType x)
{
	assert(ps);
	SeqListCheckCapacity(ps);

	int end = ps->sz - 1;
	while (end >= 0)
	{
		ps->a[end + 1] = ps->a[end];
		end--;
	}
	ps->a[0] = x;
	ps->sz++;
}

void SeqListPopFront(SL* ps)
{
	assert(ps);

	assert(ps->sz > 0);
	int start = 1;
	while (start <= ps->sz - 1)
	{
		ps->a[start - 1] = ps->a[start];
		start++;
	}
	ps->sz--;
}

void SeqListPrint(SL* ps)
{
	assert(ps);

	for (int i = 0; i < ps->sz; i++)
	{
		printf("%d ", ps->a[i]);
	}
	printf("\n");
}

void SeqListDestory(SL* ps)
{
	assert(ps);

	// ����ֻ��Ϊ���Ͻ�һЩ
	// ���˳�����������˳�ʼ������ô ps->a Ϊ��ָ��
	// �Ƿ����ٸ���û���⣬��Ϊ˳������ٺ󣬽ṹ��Ա������ͳ�ʼ������ͬ��

	if (ps->a)
	{
		free(ps->a);
		ps->a = NULL;
		ps->sz = ps->capacity = 0;
	}
}

// �ҵ��˷���xλ���±꣬û��û������-1
int SeqListFind(SL* ps, SLDataType x)
{
	assert(ps);

	assert(ps->sz > 0);

	for (int i = 0; i < ps->sz; i++)
	{
		if (ps->a[i] == x)
			return i;
	}
	return -1;
}

void SeqListInsert(SL* ps, int pos, SLDataType x)
{
	assert(ps);
	assert(pos >= 0 && pos <= ps->sz);

	SeqListCheckCapacity(ps);

	int end = ps->sz - 1;
	while (end >= pos)
	{
		ps->a[end + 1] = ps->a[end];
		end--;
	}
	ps->a[pos] = x;
	ps->sz++;
}

void SeqListErase(SL* ps, int pos)
{
	assert(ps);
	assert(pos >= 0 && pos <= ps->sz - 1);
	assert(ps->sz > 0);

	int start = pos + 1;
	while (start <= ps->sz - 1)
	{
		ps->a[start - 1] = ps->a[start];
		start++;
	}

	ps->sz--;

}
void SeqListModify(SL* ps, int pos, int x)
{
	assert(ps);
	assert(pos >= 0 && pos <= ps->sz - 1);
	assert(ps->sz > 0);

	ps->a[pos] = x;
}