#define _CRT_SECURE_NO_WARNINGS 1 

#include "List.h"

// 初始化
LTNode* ListInit()
{
	LTNode* phead = (LTNode*)malloc(sizeof(LTNode));
	// 双向带头循环链表的prev指向next，next指向prev
	// 但是这里只有一个节点，所以只能让它自己指向自己
	if (phead == NULL)
	{
		perror("ListInit");
		exit(-1);
	}
	phead->next = phead;
	phead->prev = phead;
	
	return phead;
}

// 创建新节点
LTNode* BuyListNode(LTDataType x)
{
	LTNode* newnode = (LTNode*)malloc(sizeof(LTNode));
	if (newnode == NULL)
	{
		perror("ListPushBack");
		exit(-1);
	}
	newnode->data = x;
	newnode->next = NULL;
	newnode->prev = NULL;

	return newnode;
}
// 打印
void ListPrint(LTNode* phead)
{
	assert(phead);

	LTNode* cur = phead->next;

	while (cur != phead)
	{
		printf("%d->", cur->data);
		cur = cur->next;
	}
	printf("\n");
}

// 尾插
void ListPushBack(LTNode* phead, LTDataType x)
{
	assert(phead);// 一定不为空-->有哨兵位

	//LTNode* tail = phead->prev;// 尾就是prev，由于是双向循环链表，所以头的prev就是尾
	//LTNode* newnode = BuyListNode(x);

	//// phead              tail            newnode
	//tail->next = newnode;
	//newnode->prev = tail;
	//newnode->next = phead;
	//phead->prev = newnode;

	ListInsert(phead, x);
}

// 尾删
void ListPopBack(LTNode* phead)
{
	assert(phead);
	assert(phead->next != phead);// 防止把哨兵位删掉 
	/*LTNode* tail = phead->prev; 
	LTNode* tailprev = tail->prev;
	free(tail);
	
	phead->prev = tailprev;
	tailprev->next = phead;*/

	ListErase(phead->prev);
}

// 另一种写法
//void ListPopBack(LTNode* phead)
//{
//	assert(phead);
//	assert(phead->next != phead);// 防止把哨兵位删掉 
//	LTNode* tail = phead->prev; 
//	
//	phead->prev = tail->prev;
//	tail->prev->next = phead;
//	
//	free(tail); 	
//}

// 头插
void ListPushFront(LTNode* phead, LTDataType x)
{
	assert(phead);
	/*LTNode* newnode = BuyListNode(x);
	LTNode* next = phead->next;
	
	phead->next = newnode;
	newnode->prev = phead;
	
	newnode->next = next;
	next->prev = newnode;*/

	ListInsert(phead->next, x);
}

// 头删
void ListPopFront(LTNode* phead)
{
	assert(phead);

	/*LTNode* next = phead->next;
	LTNode* nextNext = next->next;

	phead->next = nextNext;
	nextNext->prev = phead;
	free(next);*/

	ListErase(phead->next);
}

// 查找
LTNode* ListFind(LTNode* phead, LTDataType x)
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

// 在pos位置之前插入
void ListInsert(LTNode* pos, LTDataType x)
{
	assert(pos);

	LTNode* newnode = BuyListNode(x);

	LTNode* posPrev = pos->prev;

	newnode->prev = posPrev;
	posPrev->next = newnode;

	newnode->next = pos;
	pos->prev = newnode;
}

// 在pos位置删除
void ListErase(LTNode* pos)
{
	assert(pos);
	LTNode* posPrev = pos->prev;
	LTNode* posNext = pos->next;

	posPrev->next = posNext;
	posNext->prev = posPrev;

	free(pos);
	pos = NULL;
}

// 销毁
void ListDestroy(LTNode* phead)
{
	assert(phead);

	LTNode* cur = phead->next;
	while (cur != phead)
	{
		LTNode* next = cur->next;
		free(cur);
		cur = next;
	}

	free(phead);// 只销毁了形参，没有销毁实参
	phead = NULL;
}