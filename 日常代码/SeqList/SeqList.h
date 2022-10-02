#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#define N 1000
typedef int SLDataType;

// ��̬˳���
typedef struct SeqList
{
	SLDataType* a;
	int sz;// ��ʾ�����д洢�˶��ٸ�����
	int capacity;// ����ʵ���ܴ����ݵĿռ������Ƕ��
}SL;

/*
 * Ϊʲôʹ������������� 
 * Ϊ�˶�ӦC++ STL�е��������
 * �������ѧϰSTL
 */

// �ӿں���
// �ӿڣ����Ǻͱ��˶Խӵ�
void SeqListInit(SL* ps);// ��ʼ��
void SeqListCheckCapacity(SL* ps);// �������
void SeqListPushBack(SL* ps, SLDataType x);// β��
void SeqListPopBack(SL* ps);// βɾ
void SeqListPushFront(SL* ps, SLDataType x);// ͷ��
void SeqListPopFront(SL* ps);// ͷɾ
void SeqListPrint(SL* ps);// ��ӡ
void SeqListDestory(SL* ps);// ����
// ...

// �ҵ��˷���xλ���±꣬û��û������-1
int SeqListFind(SL* ps, SLDataType x);// ����
void SeqListInsert(SL* ps, int pos, SLDataType x);// ָ���±�λ�ò���
void SeqListErase(SL* ps, int pos);// ɾ��posλ�õ�����
void SeqListModify(SL* ps, int pos, int x);// �޸�posλ�õ�����