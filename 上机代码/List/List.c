#define _CRT_SECURE_NO_WARNINGS 1 

#include "List.h"

LTNode* BuyListNode(LTDataType x)
{
	LTNode* newnode = (LTNode*)malloc(sizeof(LTNode));
	if (newnode == NULL)
	{
		perror("malloc fail");
		exit(-1);
	}
	newnode->data = x;
	newnode->next = NULL;
	newnode->prev = NULL;
	return newnode;
}

LTNode* LTInit()
{
	// �����ڱ�λ
	LTNode* phead = BuyListNode(-1);
	phead->next = phead;
	phead->prev = phead;

	return phead;
}

void LTPrint(LTNode* phead)
{
	// phead һ����Ϊ�գ�������Ҫ����
	assert(phead);
	LTNode* cur = phead->next;
	while (cur != phead)
	{
		printf("%d ", cur->data);
		cur = cur->next;
	}
	printf("\n");
}

void LTPushBack(LTNode* phead, LTDataType x)
{
	assert(phead);

	/*
	LTNode* newnode = BuyListNode(x);
	LTNode* tail = phead->prev;
	
	tail->next = newnode;
	newnode->prev = tail;

	newnode->next = phead;
	phead->prev = newnode;*/

	LTInsert(phead, x);
}

void LTPopBack(LTNode* phead)
{
	assert(phead);
	assert(phead->next != phead);

	/*
	LTNode* tail = phead->prev;
	LTNode* tailPrev = tail->prev;

	tailPrev->next = phead;
	phead->prev = tailPrev;

	free(tail);*/

	LTErase(phead->prev);
}

void LTPushFront(LTNode* phead, LTDataType x)
{
	assert(phead);
	
	/*
	LTNode* newnode = BuyListNode(x);
	
	newnode->next = phead->next;
	phead->next->prev = newnode;

	phead->next = newnode;
	newnode->prev = phead;*/

	LTInsert(phead->next, x);

}

void LTPopFront(LTNode* phead)
{
	assert(phead);
	assert(phead->next != phead);

	/*LTNode* first = phead->next;
	LTNode* second = first->next;

	phead->next = second;
	second->prev = phead;

	free(first);*/

	LTErase(phead->next);
}

LTNode* LTFind(LTNode* phead, LTDataType x)
{
	assert(phead);

	LTNode* cur = phead->next;

	while (cur != phead)
	{
		if (cur->data == x)
		{
			return cur;
		}
		cur = cur->next;
	}
	return NULL;
}

// ����λ�ò���
void LTInsert(LTNode* pos, LTDataType x)
{
	assert(pos);
	
	LTNode* posPrev = pos->prev;
	LTNode* newnode = BuyListNode(x);

	newnode->next = pos;
	pos->prev = newnode;

	posPrev->next = newnode;
	newnode->prev = posPrev;
}

// ����λ��ɾ��
void LTErase(LTNode* pos)
{
	assert(pos);
	
	LTNode* posPrev = pos->prev;
	LTNode* posNext = pos->next;

	free(pos);

	posPrev->next = posNext;
	posNext->prev = posPrev;
}

bool LTEmpty(LTNode* phead)
{
	assert(phead);

	return phead->next == phead;
}

// ��Щ�̿����ѧУ����ڱ�λ�е� data ��������ĳ���
// ����������
// ʵ���ϲ��У���˫�������д洢�������ε�ʱ���ǿ��Ե�
// ��������洢�ַ���һ�����ȳ���127���Ͳ����ˣ������±��-128
// ͬ���ĸ�����Ҳ����

size_t LTSize(LTNode* phead)
{
	assert(phead);

	size_t size = 0;
	LTNode* cur = phead->next;

	while (cur != phead)
	{
		++size;
		cur = cur->next;
	}

	return size;
}

void LTDestroy(LTNode* phead)
{
	assert(phead);

	LTNode* cur = phead->next;

	while (cur != phead)
	{
		LTNode* next = cur->next;
		free(cur);
		cur = next;
	}

	free(phead);
}
