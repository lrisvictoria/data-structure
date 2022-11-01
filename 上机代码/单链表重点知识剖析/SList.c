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
		// ����Ϊ�գ�����ͷβ�������½ڵ�
		if (phead == NULL)
		{
			ptail = phead = newnode;
		}
		else
		{
			ptail->next = newnode;
			ptail = newnode; // β����µ�ͷ
		}
	}
	return phead;
}

void SLTPrint(SLTNode* phead)
{
	// ����� phead �ʹ��������ص� phead �ǲ�һ����
	// ��Ϊ�����Ǿֲ��������������������٣��������Ƕ�ָ�� Plist
	SLTNode* cur = phead;

	while (cur != NULL)
	{
		printf("%d->", cur->data);
		cur = cur->next;
	}
	printf("NULL");
}