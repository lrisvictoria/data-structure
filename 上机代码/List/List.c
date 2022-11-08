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
	// 创建哨兵位
	LTNode* phead = BuyListNode(-1);
	phead->next = phead;
	phead->prev = phead;

	return phead;
}

void LTPrint(LTNode* phead)
{
	// phead 一定不为空，所以需要断言
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

// 任意位置插入
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

// 任意位置删除
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

// 有些教科书和学校会把哨兵位中的 data 记作链表的长度
// 这样可以吗？
// 实际上不行，当双向链表中存储的是整形的时候是可以的
// 但是如果存储字符，一旦长度超过127，就不行了，会重新变成-128
// 同样的浮点数也不行

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
