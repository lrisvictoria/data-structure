#pragma once

/*
* c++�д�ͷ˫��ѭ������������ʽΪList����������Ҳ�������������ʽ
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

// ��ʼ��
LTNode* ListInit();// ʹ�÷���ֵ����

// ��ӡ
void ListPrint(LTNode* phead);

// β��
void ListPushBack(LTNode* phead, LTDataType x);

// βɾ
void ListPopBack(LTNode* phead);

// ͷ��
void ListPushFront(LTNode* phead, LTDataType x);

// ͷɾ
void ListPopFront(LTNode* phead);