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
		// 链表为空，所以头尾都等于新节点
		if (phead == NULL)
		{
			ptail = phead = newnode;
		}
		else
		{
			ptail->next = newnode;
			ptail = newnode; // 尾变成新的头
		}
	}
	return phead;
}

void SLTPrint(SLTNode* phead)
{
	// 这里的 phead 和创建链表返回的 phead 是不一样的
	// 因为这里是局部变量，它出作用域销毁，但是它们都指向 Plist
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
	// 找尾
	// 这样可不可行？
	// 对不对？
	// 当然不对，看板书
	/*while (tail != NULL)
	{
		tail = tail->next;
	}
	tail = newnode;*/

	// 正确写法
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
		// 法1
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
//	// 法2
//	while (tail->next->next)
//	{
//		tail = tail->next;
//	}
//	free(tail->next);
//	tail->next = NULL;
//}

// 单链表真正的优势是头插、头删

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

	// 法2
	SLTNode* next = (*pphead)->next;
	free(*pphead);
	*pphead = next;
}

SLTNode* SLTFind(SLTNode* phead, SLTDataType x)
{
	SLTNode* cur = phead;
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

void SLTInsertAfter(SLTNode* pos, SLTDataType x)
{
	assert(pos);
	SLTNode* newnode = BuySLTNode(x);
	// 链接的时候看看清楚，小心成环！！！
	newnode->next = pos->next;
	pos->next = newnode;
}

void SLTEraseAfter(SLTNode* pos)
{
	assert(pos);

	if (pos->next == NULL)
	{
		return;
	}
	else
	{
		SLTNode* nextNode = pos->next;
		pos->next = nextNode->next;
		free(nextNode);
		// 小心野指针错误
		// 这个其实也挺好理解的，想一下就可以
		// 我就不多赘述了，写这个的时候已经详细写过了
		/*free(pos->next);
		pos->next = pos->next->next;*/
	}
}


void SLTInsert(SLTNode** pphead, SLTNode* pos, SLTDataType x)
{
	assert(pos);

	if (*pphead == NULL)
	{
		SLTPushFront(pphead, x);
	}
	else
	{
		SLTNode* newnode = BuySLTNode(x);
		SLTNode* prev = *pphead;
		while (prev->next != pos)
		{
			prev = prev->next;
		}
		newnode->next = pos;
		prev->next = newnode;
	}
}
 
void SLTErase(SLTNode** pphead, SLTNode* pos)
{
	// 这里只要断言 pos 就可以了
	// 因为如果 *pphead 为空，那么 pos 一定找不到为空
	assert(pos);

	if (pos == *pphead)
	{
		SLTPopFront(pphead);
	}
	else
	{
		SLTNode* prev = *pphead;
		while (prev->next != pos)
		{
			prev = prev->next;
		}
		prev->next = pos->next;
		free(pos);
	}
}

void SLTDestory(SLTNode** pphead)
{
	SLTNode* cur = *pphead;
	while (cur)
	{
		SLTNode* next = cur->next;
		free(cur);
		cur = next;
	}
}