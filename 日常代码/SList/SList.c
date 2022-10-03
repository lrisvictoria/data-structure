#define _CRT_SECURE_NO_WARNINGS 1 

#include "SList.h"

// ��ӡ
void SListPrint(SLTNode* phead)
{
	SLTNode* cur = phead;
	while (cur != NULL)
	{
		printf("%d->", cur->data);
		cur = cur->next;
	}
}

// β��
void SListPushBack(SLTNode** pphead, SLTDateType x)
{
	// �����½ڵ�
	SLTNode* newnode = (SLTNode*)malloc(sizeof(SLTNode));
	newnode->data = x;
	newnode->next = NULL;

	// ����û�нڵ㣬���½ڵ�
	if (*pphead == NULL)
	{
		*pphead = newnode;
	}
	else
	{
		// �ҵ�β���
		SLTNode* tail = *pphead;
		while (tail->next != NULL)
		{
			tail = tail->next;
		}
		// β��������½ڵ�
		tail->next = newnode;
	}	
}