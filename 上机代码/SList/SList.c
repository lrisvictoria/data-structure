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
	// 如果表空，需要特殊处理
	if (*pphead == NULL)
	{
		*pphead = newnode;
	}
	else
	{
		// 找尾，正常操作
		SLTNode* tail = *pphead;
		while (tail->next)
		{
			tail = tail->next;
		}
		// 现在找到尾了
		tail->next = newnode;
	}
}

void SLTPopBack(SLTNode** pphead)
{
	// 首先需要判断表是否为空
	assert(*pphead);
	// 单个节点删除
	if ((*pphead)->next == NULL)
	{
		free(*pphead);
		*pphead = NULL;
	}
	else
	{
		// 多个节点删除
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

// 单链表在pos位置之后插入x
// 分析思考为什么不在pos位置之前插入？
void SLTInsertAfter(SLTNode* pos, SLTDataType x)
{
	assert(pos);

	SLTNode* next = pos->next;
	SLTNode* newnode = BuySLTNode(x);
	pos->next = newnode;
	newnode->next = next;
}

// 单链表删除pos位置之后的值
// 分析思考为什么不删除pos位置？
void SLTEraseAfter(SLTNode* pos)
{
	assert(pos);
	// 如果只有一个节点不能这么删
	assert(pos->next);
	SLTNode* next = pos->next;
	SLTNode* nextNext = next->next;
	free(next);
	next = NULL;
	pos->next = nextNext;
}


// 在pos之前插入x
void SLTInsert(SLTNode** pphead, SLTNode* pos, SLTDataType x)
{
	assert(pos);
	SLTNode* newnode = BuySLTNode(x);
	// 头插情况特殊处理
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

// 删除pos位置
void SLTErase(SLTNode** pphead, SLTNode* pos)
{
	assert(*pphead);

	// 处理头删情况
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