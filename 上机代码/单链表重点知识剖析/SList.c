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

SLTNode* CreateSList(int n)
{
	SLTNode* phead = NULL, *ptail = NULL;
	for (int i = 0; i < n; i++)
	{
		SLTNode* newnode = BuySLTNode(i);
		// ����Ϊ�գ�����ͷβ�������½ڵ�
		if (phead == NULL)
		{
			ptail = phead = newnode;
		}
		else
		{
			ptail->next = newnode;
			ptail = newnode; // β����µ�ͷ
		}
	}
	return phead;
}

void SLTPrint(SLTNode* phead)
{
	// ����� phead �ʹ��������ص� phead �ǲ�һ����
	// ��Ϊ�����Ǿֲ��������������������٣��������Ƕ�ָ�� Plist
	SLTNode* cur = phead;

	while (cur != NULL)
	{
		printf("[%d|%p]->", cur->data);
		cur = cur->next;
	}
	printf("NULL");
	printf("\n");
}

void SLTPushBack(SLTNode** pphead, SLTDataType x)
{
	SLTNode* newnode = BuySLTNode(x);
	// ��β
	// �����ɲ����У�
	// �Բ��ԣ�
	// ��Ȼ���ԣ�������
	/*while (tail != NULL)
	{
		tail = tail->next;
	}
	tail = newnode;*/

	// ��ȷд��
	if (*pphead == NULL)
	{
		*pphead = newnode;
	}
	else
	{
		SLTNode* tail = *pphead;
		while (tail->next != NULL)
		{
			tail = tail->next;
		}
		tail->next = newnode;
	}
}

void SLTPopBack(SLTNode** pphead)
{
	assert(*pphead);
	
	if ((*pphead)->next == NULL)
	{
		free(*pphead);
		*pphead = NULL;
	}
	else
	{
		SLTNode* tail = *pphead;
		SLTNode* prev = NULL;
		// ��1
		while (tail->next)
		{
			prev = tail;
			tail = tail->next;
		}
		free(tail);
		prev->next = NULL;
	}
}

//void SLTPopBack(SLTNode** pphead)
//{
//	assert(*pphead);
//
//	SLTNode* tail = *pphead;
//	// ��2
//	while (tail->next->next)
//	{
//		tail = tail->next;
//	}
//	free(tail->next);
//	tail->next = NULL;
//}

// ������������������ͷ�塢ͷɾ

void SLTPushFront(SLTNode** pphead, SLTDataType x)
{
	SLTNode* newnode = BuySLTNode(x);
	newnode->next = *pphead;
	*pphead = newnode;
}

void SLTPopFront(SLTNode** pphead)
{
	assert(*pphead);
	/*
	SLTNode* cur = *pphead;
	*pphead = (*pphead)->next;
	free(cur);
	*/

	// ��2
	SLTNode* next = (*pphead)->next;
	free(*pphead);
	*pphead = next;
}