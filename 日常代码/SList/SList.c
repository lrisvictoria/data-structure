#define _CRT_SECURE_NO_WARNINGS 1 

#include "SList.h"

// �����½ڵ�
SLTNode* BuyListNode(SLTDateType x)
{
	SLTNode* newnode = (SLTNode*)malloc(sizeof(SLTNode));
	if (newnode == NULL)
	{
		printf("malloc fail\n");
		exit(-1);// �ڴ�����ʧ�ܣ�˵������û�пռ��ˣ�ֱ���˳�����
	}
	newnode->data = x;
	newnode->next = NULL;

	return newnode;
}

// ��ӡ
void SListPrint(SLTNode* phead)
{
	SLTNode* cur = phead;
	while (cur != NULL)
	{
		printf("%d->", cur->data);
		cur = cur->next;
	}
	printf("NULL\n");
}

// β��
void SListPushBack(SLTNode** pphead, SLTDateType x)
{
	assert(pphead);// pphead��plist�ĵ�ַ���϶���Ϊ�գ���ֹ��������
	// �����½ڵ�
	SLTNode* newnode = BuyListNode(x);

	// ����û�нڵ㣬���½ڵ�
	if (*pphead == NULL)
	{
		*pphead = newnode;
	}
	else
	{
		// �ҵ�β���
		SLTNode* tail = *pphead;
		while (tail->next != NULL)
		{
			tail = tail->next;
		}
		// β��������½ڵ�
		tail->next = newnode;
	}	
}

// ͷ��
void SListPushFront(SLTNode** pphead, SLTDateType x)
{
	assert(pphead);

	SLTNode* newnode = BuyListNode(x);

	newnode->next = *pphead;// �½ڵ�����֮ǰplist�ĵ�ַ
	*pphead = newnode;// ͷָ�����Ϊnewnode
}

// βɾ
void SListPopBack(SLTNode** pphead)
{
	assert(pphead);

	// ���ᴦ��
	/*if (*pphead == NULL)
	{
		return;
	}*/

	// �������� һ���ڵ�
	assert(*pphead);

	if ((*pphead)->next == NULL)
	{
		free(*pphead);
		*pphead = NULL;
	}
	else// ���������Ͻڵ�
	{
		// plan1
		SLTNode* prev = NULL;// ��¼��һ���ڵ�ĵ�ַ
		SLTNode* tail = *pphead;

		//while (tail->next != NULL)// �����߼����ʽ��ֵΪ���پ���ѭ���Ƿ����ִ��
		while (tail->next)// ��ֵΪ��ָ�룬����ʽת��Ϊ0������ѭ��
		{
			prev = tail;
			tail = tail->next;
		}

		free(tail);// �ͷ�β���ռ�
		tail = NULL;
		// ��ǰһ���ڵ��next�ÿ�
		prev->next = NULL;
	}

	
	// plan2��
	//SLTNode* tail = *pphead;

	//while (tail->next->next)// �����ǰtail��next�ĵ�ַ������һ��nextΪ�գ���ֹͣ
	//{
	//	tail = tail->next;// ��β��㸳ֵΪ���һ���ڵ��next
	//}

	//free(tail->next);// �ͷ����һ���ڵ�
	//tail->next = NULL;// ���һ���ڵ��ÿ�
}

// ͷɾ
void SListPopFront(SLTNode** pphead)
{
	assert(pphead);

	// ���������
	assert(*pphead);
	
	// ����1�������Ͻڵ�
	SLTNode* newpphead = (*pphead)->next;
	free(*pphead);
	*pphead = newpphead;
}

// ����
SLTNode* SListFind(SLTNode* phead, SLTDateType x)
{
	SLTNode* cur = phead;
	while (cur)
	{
		if (cur->data == x)
		{
			return cur;
		}
		else
		{
			cur = cur->next;
		}
	}
	return NULL;// û�ҵ�
}

// ��posλ��֮ǰ����ڵ�
void SListInsert(SLTNode** pphead, SLTNode* pos, SLTDateType x)
{
	assert(pphead);
	assert(pos);
	SLTNode* newnode = BuyListNode(x);
	// ͷ��������⴦��
	if (*pphead == pos)
	{
		newnode->next = *pphead;// newnode����ͷ
		*pphead = newnode;// ͷ��Ϊnewnode
	}
	// ����λ�ò���
	else
	{
		// �ҵ�posǰһ��λ��
		SLTNode* posPrev = *pphead;
		while (posPrev->next != pos)
		{
			posPrev = posPrev->next;
		}
		posPrev->next = newnode;// ��posǰһ��λ�����ӵ�newnode
		newnode->next = pos;// newnode���ӵ�pos
	}

}

// pos��̫�ʺ��ڽڵ�ǰ���룬�ʺ��ڽڵ�����
// ��pos���� ����ڵ�

void SListInsertAfter(SLTNode* pos, SLTDateType x)
{
	assert(pos);

	SLTNode* newnode = BuyListNode(x);
	newnode->next = pos->next;
	pos->next = newnode; 
}

// ɾ��posλ�õĽڵ�
void SListErase(SLTNode** pphead, SLTNode* pos)
{
	assert(pphead);
	assert(pos);

	// ����ͷɾ
	if (*pphead == pos)
	{
		*pphead = pos->next;
		free(pos);
		// ֱ�ӵ���ͷɾ
		// SListPopFront(pos);
	}
	// �����������
	else
	{
		SLTNode* prev = *pphead;
		while (prev->next != pos)
		{
			prev = prev->next;
		}
		prev->next = pos->next;
		free(pos);
		pos = NULL;
	}
}

// ɾ��ָ��posλ�ú��һ���ڵ�
void SListEraseAfter(SLTNode** pphead, SLTNode* pos)
{
	assert(pos);

	assert(pos->next);// ɾ���Ĳ�����β�������λ��
	SLTNode* next = pos->next;// ����pos����һ���ڵ�
	pos->next = next->next;// ��pos��next��Ϊ��һ���ڵ��next
	free(next);// �ͷ�֮ǰpos����һ���ڵ�
	next = NULL;
}

void SListDestory(SLTNode** pphead)
{
	assert(pphead);
	
	SLTNode* cur = *pphead;
	while (cur)
	{
		SLTNode* next = cur->next;
		free(cur);
		cur = next;
	}

	*pphead = NULL;
}