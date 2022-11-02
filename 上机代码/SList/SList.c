#define _CRT_SECURE_NO_WARNINGS 1 

#include "SList.h"

SLTNode* BuySLTNode(SLTDataType x)
{
	SLTNode* newnode = (SLTNode*)malloc(sizeof(SLTNode));
	if (newnode == NULL)
	{
		perror("malloc fail");
		exit(-1);
	}
	newnode->data = x;
	newnode->next = NULL;

	return newnode;
}

void SLTPrint(SLTNode* phead)
{
	SLTNode* cur = phead;
	while (cur != NULL)
	{
		printf("%d->", cur->data);
		cur = cur->next;
	}
	printf("NULL");
	printf("\n");
}

void SLTPushBack(SLTNode** pphead, SLTDataType x)
{
	SLTNode* newnode = BuySLTNode(x);
	// �����գ���Ҫ���⴦��
	if (*pphead == NULL)
	{
		*pphead = newnode;
	}
	else
	{
		// ��β����������
		SLTNode* tail = *pphead;
		while (tail->next)
		{
			tail = tail->next;
		}
		// �����ҵ�β��
		tail->next = newnode;
	}
}

void SLTPopBack(SLTNode** pphead)
{
	// ������Ҫ�жϱ��Ƿ�Ϊ��
	assert(*pphead);
	// �����ڵ�ɾ��
	if ((*pphead)->next == NULL)
	{
		free(*pphead);
		*pphead = NULL;
	}
	else
	{
		// ����ڵ�ɾ��
		SLTNode* prev = NULL;
		SLTNode* tail = *pphead;
		while (tail->next)
		{
			prev = tail;
			tail = tail->next;
		}
		free(tail);
		prev->next = NULL;
	}
}

void SLTPushFront(SLTNode** pphead, SLTDataType x)
{
	SLTNode* newnode = BuySLTNode(x);
	newnode->next = *pphead;
	*pphead = newnode;
}

void SLTPopFront(SLTNode** pphead)
{
	assert(*pphead);
	SLTNode* next = (*pphead)->next;
	free(*pphead);
	*pphead = next;
}

SLTNode* SListFind(SLTNode* plist, SLTDataType x)
{
	SLTNode* cur = plist;
	while (cur)
	{
		if (cur->data == x)
		{
			return cur;
		}
		cur = cur->next;
	}
	return NULL;
}

// ��������posλ��֮�����x
// ����˼��Ϊʲô����posλ��֮ǰ���룿
void SLTInsertAfter(SLTNode* pos, SLTDataType x)
{
	assert(pos);

	SLTNode* next = pos->next;
	SLTNode* newnode = BuySLTNode(x);
	pos->next = newnode;
	newnode->next = next;
}

// ������ɾ��posλ��֮���ֵ
// ����˼��Ϊʲô��ɾ��posλ�ã�
void SLTEraseAfter(SLTNode* pos)
{
	assert(pos);
	// ���ֻ��һ���ڵ㲻����ôɾ
	assert(pos->next);
	SLTNode* next = pos->next;
	SLTNode* nextNext = next->next;
	free(next);
	next = NULL;
	pos->next = nextNext;
}


// ��pos֮ǰ����x
void SLTInsert(SLTNode** pphead, SLTNode* pos, SLTDataType x)
{
	assert(pos);
	SLTNode* newnode = BuySLTNode(x);
	// ͷ��������⴦��
	if (pos->next == NULL)
	{
		newnode->next = pos;
		*pphead = newnode;
	}
	else
	{
		SLTNode* posPrev = *pphead;
		while (posPrev->next != pos)
		{
			posPrev = posPrev->next;
		}
		posPrev->next = newnode;
		newnode->next = pos;
	}
}

// ɾ��posλ��
void SLTErase(SLTNode** pphead, SLTNode* pos)
{
	assert(*pphead);

	// ����ͷɾ���
	if (pos->next == NULL)
	{
		free(pos);
		pos = NULL;
	}
	else
	{
		SLTNode* posPrev = *pphead;

		while (posPrev->next != pos)
		{
			posPrev = posPrev->next;
		}
		posPrev->next = pos->next;
		free(pos);
		pos = NULL;
	}
}