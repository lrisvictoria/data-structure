#pragma once

#include <stdio.h>
#include <stdlib.h>

typedef int SLTDateType;

typedef struct SListNode
{
	int data;
	struct SListNode* next;
}SLTNode;

// ¥Ú”°
void SListPrint(SLTNode* phead);

// Œ≤≤Â
void SListPushBack(SLTNode** pphead, SLTDateType x);