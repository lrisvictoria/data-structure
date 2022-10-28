#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

typedef int SLDataType;

// ��̬˳���
typedef struct SeqList
{
	SLDataType* a;
	int sz;// ��ʾ�����д洢�˶��ٸ�����
	int capacity;// ����ʵ���ܴ����ݵĿռ������Ƕ��
}SL;

void SeqListInit(SL* ps);
void SeqListCheckCapacity(SL* ps);
void SeqListPushBack(SL* ps, SLDataType x);
void SeqListPopBack(SL* ps);
void SeqListPushFront(SL* ps, SLDataType x);
void SeqListPopFront(SL* ps);
void SeqListPrint(SL* ps);
void SeqListDestory(SL* ps);

// �ҵ��˷���xλ���±꣬û��û������-1
int SeqListFind(SL* ps, SLDataType x);// ����
void SeqListInsert(SL* ps, int pos, SLDataType x);// ָ���±�λ�ò���
void SeqListErase(SL* ps, int pos);// ɾ��posλ�õ�����
void SeqListModify(SL* ps, int pos, int x);// �޸�posλ�õ�����