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

	LTNode* tail = phead->prev;// 尾就是prev，由于是双向循环链表，所以头的prev就是尾
	LTNode* newnode = BuyListNode(x);

	// phead              tail            newnode
	tail->next = newnode;
	newnode->prev = tail;
	newnode->next = phead;
	phead->prev = newnode;

}

// 尾删
void ListPopBack(LTNode* phead)
{
	assert(phead);
	assert(phead->next != phead);// 防止把哨兵位删掉 
	LTNode* tail = phead->prev; 
	LTNode* tailprev = tail->prev;
	free(tail);
	
	tailprev->next = phead;
	phead->prev = tailprev;
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
	LTNode* newnode = BuyListNode(x);
	LTNode* next = phead->next;
	
	phead->next = newnode;
	newnode->prev = phead;
	
	newnode->next = next;
	next->prev = newnode;
}

// 头删
void ListPopFront(LTNode* phead)
{
	  
}