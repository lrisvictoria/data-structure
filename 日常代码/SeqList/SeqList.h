#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#define N 1000
typedef int SLDataType;

// 动态顺序表
typedef struct SeqList
{
	SLDataType* a;
	int sz;// 表示数组中存储了多少个数据
	int capacity;// 数组实际能存数据的空间容量是多大
}SL;

/*
 * 为什么使用这种命名风格？ 
 * 为了对应C++ STL中的命名风格
 * 方便后续学习STL
 */

// 接口函数
// 接口，就是和别人对接的
void SeqListInit(SL* ps);// 初始化
void SeqListCheckCapacity(SL* ps);// 检查增容
void SeqListPushBack(SL* ps, SLDataType x);// 尾插
void SeqListPopBack(SL* ps);// 尾删
void SeqListPushFront(SL* ps, SLDataType x);// 头插
void SeqListPopFront(SL* ps);// 头删
void SeqListPrint(SL* ps);// 打印
void SeqListDestory(SL* ps);// 销毁
// ...

// 找到了返回x位置下标，没有没到返回-1
int SeqListFind(SL* ps, SLDataType x);// 查找
void SeqListInsert(SL* ps, int pos, SLDataType x);// 指定下标位置插入
void SeqListErase(SL* ps, int pos);// 删除pos位置的数据
void SeqListModify(SL* ps, int pos, int x);// 修改pos位置的数据