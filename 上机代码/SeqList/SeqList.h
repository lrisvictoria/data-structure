#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

typedef int SLDataType;

// 动态顺序表
typedef struct SeqList
{
	SLDataType* a;
	int sz;// 表示数组中存储了多少个数据
	int capacity;// 数组实际能存数据的空间容量是多大
}SL;

void SeqListInit(SL* ps);
void SeqListCheckCapacity(SL* ps);
void SeqListPushBack(SL* ps, SLDataType x);
void SeqListPopBack(SL* ps);
void SeqListPushFront(SL* ps, SLDataType x);
void SeqListPopFront(SL* ps);
void SeqListPrint(SL* ps);
void SeqListDestory(SL* ps);

// 找到了返回x位置下标，没有没到返回-1
int SeqListFind(SL* ps, SLDataType x);// 查找
void SeqListInsert(SL* ps, int pos, SLDataType x);// 指定下标位置插入
void SeqListErase(SL* ps, int pos);// 删除pos位置的数据
void SeqListModify(SL* ps, int pos, int x);// 修改pos位置的数据