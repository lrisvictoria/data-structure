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

// ��ӡ
void SListPrint(SLTNode* phead);

// β��
void SListPushBack(SLTNode** pphead, SLTDateType x);

// ͷ��
void SListPushFront(SLTNode** pphead, SLTDateType x);

// βɾ
void SListPopBack(SLTNode** pphead);

// ͷɾ
void SListPopFront(SLTNode** pphead);

// ����
SLTNode* SListFind(SLTNode* phead, SLTDateType x);

// ��posλ��֮ǰ����һ���ڵ� 
void SListInsert(SLTNode** pphead, SLTNode* pos, SLTDateType x);

// ��posλ��֮�����һ���ڵ�
void SListInsertAfter(SLTNode* pos, SLTDateType x);

// ��ָ��λ��ɾ��һ���ڵ�
void SListErase(SLTNode** phead, SLTNode* pos, SLTDateType x);

// ����
void SListDestory(SLTNode** pphead);