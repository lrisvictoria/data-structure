#pragma once

/*
* c++中带头双向循环链表命名方式为List，所以我们也采用这个命名方式
*/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int LTDataType;

typedef struct ListNode
{
	LTDataType data;
	struct ListNode* next;
	struct ListNode* prev;
}LTNode;

// 初始化
LTNode* ListInit();// 使用返回值处理

// 打印
void ListPrint(LTNode* phead);

// 尾插
void ListPushBack(LTNode* phead, LTDataType x);

// 尾删
void ListPopBack(LTNode* phead);

// 头插
void ListPushFront(LTNode* phead, LTDataType x);

// 头删
void ListPopFront(LTNode* phead);