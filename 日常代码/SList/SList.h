#pragma once

#include <stdio.h>
#include <stdlib.h>

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