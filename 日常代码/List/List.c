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

	//LTNode* tail = phead->prev;// β����prev��������˫��ѭ����������ͷ��prev����β
	//LTNode* newnode = BuyListNode(x);

	//// phead              tail            newnode
	//tail->next = newnode;
	//newnode->prev = tail;
	//newnode->next = phead;
	//phead->prev = newnode;

	ListInsert(phead, x);
}

// βɾ
void ListPopBack(LTNode* phead)
{
	assert(phead);
	assert(phead->next != phead);// ��ֹ���ڱ�λɾ�� 
	/*LTNode* tail = phead->prev; 
	LTNode* tailprev = tail->prev;
	free(tail);
	
	phead->prev = tailprev;
	tailprev->next = phead;*/

	ListErase(phead->prev);
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
	/*LTNode* newnode = BuyListNode(x);
	LTNode* next = phead->next;
	
	phead->next = newnode;
	newnode->prev = phead;
	
	newnode->next = next;
	next->prev = newnode;*/

	ListInsert(phead->next, x);
}

// ͷɾ
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

// ����
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

// ��posλ��֮ǰ����
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

// ��posλ��ɾ��
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

// ����
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

	free(phead);// ֻ�������βΣ�û������ʵ��
	phead = NULL;
}