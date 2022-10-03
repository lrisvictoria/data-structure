#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int SLTDateType;

typedef struct SListNode
{
	int data;
	struct SListNode* next;
}SLTNode;

// 打印
void SListPrint(SLTNode* phead);

// 尾插
void SListPushBack(SLTNode** pphead, SLTDateType x);

// 头插
void SListPushFront(SLTNode** pphead, SLTDateType x);

// 尾删
void SListPopBack(SLTNode** pphead);

// 头删
void SListPopFront(SLTNode** pphead);

// 查找
SLTNode* SListFind(SLTNode* phead, SLTDateType x);

// 在pos位置之前插入一个节点 
void SListInsert(SLTNode** pphead, SLTNode* pos, SLTDateType x);

// 在pos位置之后插入一个节点
void SListInsertAfter(SLTNode* pos, SLTDateType x);

// 在指定位置删除一个节点
void SListErase(SLTNode** phead, SLTNode* pos, SLTDateType x);

// 销毁
void SListDestory(SLTNode** pphead);