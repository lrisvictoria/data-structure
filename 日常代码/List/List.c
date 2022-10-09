#define _CRT_SECURE_NO_WARNINGS 1 

#include "List.h"

// ��ʼ��
LTNode* ListInit()
{
	LTNode* phead = (LTNode*)malloc(sizeof(LTNode));
	// ˫���ͷѭ�������prevָ��next��nextָ��prev
	// ��������ֻ��һ���ڵ㣬����ֻ�������Լ�ָ���Լ�
	if (phead == NULL)
	{
		perror("ListInit");
		exit(-1);
	}
	phead->next = phead;
	phead->prev = phead;
	
	return phead;
}

// �����½ڵ�
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
// ��ӡ
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

// β��
void ListPushBack(LTNode* phead, LTDataType x)
{
	assert(phead);// һ����Ϊ��-->���ڱ�λ

	LTNode* tail = phead->prev;// β����prev��������˫��ѭ����������ͷ��prev����β
	LTNode* newnode = BuyListNode(x);

	// phead              tail            newnode
	tail->next = newnode;
	newnode->prev = tail;
	newnode->next = phead;
	phead->prev = newnode;

}

// βɾ
void ListPopBack(LTNode* phead)
{
	assert(phead);
	assert(phead->next != phead);// ��ֹ���ڱ�λɾ�� 
	LTNode* tail = phead->prev; 
	LTNode* tailprev = tail->prev;
	free(tail);
	
	tailprev->next = phead;
	phead->prev = tailprev;
}

// ��һ��д��
//void ListPopBack(LTNode* phead)
//{
//	assert(phead);
//	assert(phead->next != phead);// ��ֹ���ڱ�λɾ�� 
//	LTNode* tail = phead->prev; 
//	
//	phead->prev = tail->prev;
//	tail->prev->next = phead;
//	
//	free(tail); 	
//}

// ͷ��
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

// ͷɾ
void ListPopFront(LTNode* phead)
{
	  
}