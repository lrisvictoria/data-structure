#pragma once

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <stdbool.h>

//typedef char LTDataType;
//typedef double LTDataType;
typedef int LTDataType;

typedef struct ListNode
{
	struct ListNode* next;
	struct ListNode* prev;
	LTDataType data;
}LTNode;

LTNode* BuyListNode(LTDataType x);
LTNode* LTInit();

void LTPrint(LTNode* phead);
void LTPushBack(LTNode* phead, LTDataType x);
void LTPopBack(LTNode* phead);

void LTPushFront(LTNode* phead, LTDataType x);
void LTPopFront(LTNode* phead);

LTNode* LTFind(LTNode* phead, LTDataType x);

// 任意位置插入
void LTInsert(LTNode* pos, LTDataType x);
// 任意位置删除
void LTErase(LTNode* pos);

bool LTEmpty(LTNode* phead);
size_t LTSize(LTNode* phead);
void LTDestroy(LTNode* phead);


