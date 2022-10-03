#define _CRT_SECURE_NO_WARNINGS 1 

#include "SList.h"

// 打印
void SListPrint(SLTNode* phead)
{
	SLTNode* cur = phead;
	while (cur != NULL)
	{
		printf("%d->", cur->data);
		cur = cur->next;
	}
}

// 尾插
void SListPushBack(SLTNode** pphead, SLTDateType x)
{
	// 建立新节点
	SLTNode* newnode = (SLTNode*)malloc(sizeof(SLTNode));
	newnode->data = x;
	newnode->next = NULL;

	// 链表没有节点，给新节点
	if (*pphead == NULL)
	{
		*pphead = newnode;
	}
	else
	{
		// 找到尾结点
		SLTNode* tail = *pphead;
		while (tail->next != NULL)
		{
			tail = tail->next;
		}
		// 尾结点链接新节点
		tail->next = newnode;
	}	
}