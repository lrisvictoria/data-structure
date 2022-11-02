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


// ˼��һ�£��ܲ�����ôд��
//typedef struct ListNode
//{
//	SLTDataType data;
//	SLTNode* next;
//}SLTNode;

// ���ǲ�����ģ���Ϊ����Խṹ�������ı���Ϊ
// struct ListNode
//{
//	SLTDataType data;
//	struct ListNode* next;
//}SLTNode;
//typedef struct ListNode SLTNode;
// ����֮ǰ SLTNode ��δ������
// ���Բ�����ôʹ��

SLTNode* BuySLTNode(SLTDataType x);
SLTNode* CreateSList(int n);
void SLTPrint(SLTNode* phead);

void SLTPushBack(SLTNode** pphead, SLTDataType x);
void SLTPopBack(SLTNode** pphead);
void SLTPushFront(SLTNode** pphead, SLTDataType x);
void SLTPopFront(SLTNode** pphead);