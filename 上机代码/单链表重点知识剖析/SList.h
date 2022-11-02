#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int SLTDataType;

typedef struct ListNode
{
	SLTDataType data;
	struct ListNode* next;
}SLTNode;


// 思考一下，能不能这么写？
//typedef struct ListNode
//{
//	SLTDataType data;
//	SLTNode* next;
//}SLTNode;

// 这是不允许的，因为上面对结构重命名的本质为
// struct ListNode
//{
//	SLTDataType data;
//	struct ListNode* next;
//}SLTNode;
//typedef struct ListNode SLTNode;
// 在这之前 SLTNode 还未被定义
// 所以不能这么使用

SLTNode* BuySLTNode(SLTDataType x);
SLTNode* CreateSList(int n);
void SLTPrint(SLTNode* phead);

void SLTPushBack(SLTNode** pphead, SLTDataType x);
void SLTPopBack(SLTNode** pphead);
void SLTPushFront(SLTNode** pphead, SLTDataType x);
void SLTPopFront(SLTNode** pphead);