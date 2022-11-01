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
}