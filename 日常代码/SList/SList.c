#define _CRT_SECURE_NO_WARNINGS 1 

#include "SList.h"

// 创建新节点
SLTNode* BuyListNode(SLTDateType x)
{
	SLTNode* newnode = (SLTNode*)malloc(sizeof(SLTNode));
	if (newnode == NULL)
	{
		printf("malloc fail\n");
		exit(-1);// 内存申请失败，说明几乎没有空间了，直接退出程序
	}
	newnode->data = x;
	newnode->next = NULL;

	return newnode;
}

// 打印
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

// 尾插
void SListPushBack(SLTNode** pphead, SLTDateType x)
{
	// 建立新节点
	SLTNode* newnode = BuyListNode(x);

	// 链表没有节点，给新节点
	if (*pphead == NULL)
	{
		*pphead = newnode;
	}
	else
	{
		// 找到尾结点
		SLTNode* tail = *pphead;
		while (tail->next != NULL)
		{
			tail = tail->next;
		}
		// 尾结点链接新节点
		tail->next = newnode;
	}	
}

// 头插
void SListPushFront(SLTNode** pphead, SLTDateType x)
{
	SLTNode* newnode = BuyListNode(x);

	newnode->next = *pphead;// 新节点链接之前plist的地址
	*pphead = newnode;// 头指针更改为newnode
}

// 尾删
void SListPopBack(SLTNode** pphead)
{
	// 温柔处理
	/*if (*pphead == NULL)
	{
		return;
	}*/

	// 暴力处理 一个节点
	assert(*pphead);

	if ((*pphead)->next == NULL)
	{
		free(*pphead);
		*pphead = NULL;
	}
	else// 两个及以上节点
	{
		// plan1
		SLTNode* prev = NULL;// 记录上一个节点的地址
		SLTNode* tail = *pphead;

		//while (tail->next != NULL)// 计算逻辑表达式的值为真或假决定循环是否继续执行
		while (tail->next)// 当值为空指针，被隐式转换为0，结束循环
		{
			prev = tail;
			tail = tail->next;
		}

		free(tail);// 释放尾结点空间
		tail = NULL;
		// 将前一个节点的next置空
		prev->next = NULL;
	}

	
	// plan2：
	//SLTNode* tail = *pphead;

	//while (tail->next->next)// 如果当前tail的next的地址访问下一个next为空，则停止
	//{
	//	tail = tail->next;// 将尾结点赋值为最后一个节点的next
	//}

	//free(tail->next);// 释放最后一个节点
	//tail->next = NULL;// 最后一个节点置空
}

void SListPopFront(SLTNode** pphead)
{
	// 处理空链表
	assert(*pphead);
	
	// 处理1个及以上节点
	SLTNode* newpphead = (*pphead)->next;
	free(*pphead);
	*pphead = newpphead;
}

// 查找
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
	return NULL;// 没找到
}

// 在pos位置之前插入节点
void SListInsert(SLTNode** pphead, SLTNode* pos, SLTDateType x)
{
	SLTNode* newnode = BuyListNode(x);
	// 头插情况特殊处理
	if (*pphead == pos)
	{
		newnode->next = *pphead;// newnode链接头
		*pphead = newnode;// 头变为newnode
	}
	// 其他位置插入
	else
	{
		// 找到pos前一个位置
		SLTNode* posPrev = *pphead;
		while (posPrev->next != pos)
		{
			posPrev = posPrev->next;
		}
		posPrev->next = newnode;// 将pos前一个位置链接到newnode
		newnode->next = pos;// newnode连接到pos
	}

}

// pos不太适合在节点前插入，适合在节点后插入
// 在pos的后面插入
//void SListInsertAfter(SLTNode* pos, SLTDateType x)
//{
//
//}