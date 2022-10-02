#define _CRT_SECURE_NO_WARNINGS 1 

#include "SeqList.h"

// 测试尾插、尾删
void TestSeqList1()
{
	SL s1;
	SeqListInit(&s1);
	SeqListPushBack(&s1, 1);
	SeqListPushBack(&s1, 2);
	SeqListPushBack(&s1, 3);
	SeqListPushBack(&s1, 4);
	SeqListPushBack(&s1, 5);
	SeqListPrint(&s1);
	
	SeqListPopBack(&s1);
	SeqListPopBack(&s1);
	SeqListPopBack(&s1);
	SeqListPopBack(&s1);
	SeqListPopBack(&s1);
	SeqListPopBack(&s1);
	SeqListPopBack(&s1);
	SeqListPopBack(&s1);
	SeqListPrint(&s1);

	SeqListPushBack(&s1,6);
	SeqListPushBack(&s1,7);

	// 编译器也是人写的，总会有疏忽的时候
	// 当越界时，可能会检查不出来
	// 只有当销毁时，才会发现错误
	SeqListDestory(&s1);
}

// 测试头插、头删
void TestSeqList2()
{
	SL s1;
	SeqListInit(&s1);
	SeqListPushBack(&s1, 1);
	SeqListPushBack(&s1, 2);
	SeqListPushBack(&s1, 3);
	SeqListPushBack(&s1, 4);
	SeqListPushBack(&s1, 5);
	//SeqListPrint(&s1);

	SeqListPushFront(&s1, 10);
	SeqListPushFront(&s1, 20);
	SeqListPushFront(&s1, 30);
	SeqListPushFront(&s1, 40);// 程序会崩，越界了
	SeqListPrint(&s1);

	SeqListPopFront(&s1);
	SeqListPopFront(&s1);
	SeqListPopFront(&s1);
	SeqListPopFront(&s1);
	SeqListPrint(&s1);

	SeqListDestory(&s1);

}

// 测试指定位置插入
void TestSeqList3()
{
	SL s1;
	SeqListInit(&s1);
	SeqListPushBack(&s1, 1);
	SeqListPushBack(&s1, 2);
	SeqListPushBack(&s1, 3);
	SeqListPushBack(&s1, 4);
	SeqListPushBack(&s1, 5);
	SeqListPrint(&s1);

	SeqListInsert(&s1, 2, 30);
	SeqListPrint(&s1);

	int pos = SeqListFind(&s1, 4);
	if (pos != -1)
	{
		SeqListInsert(&s1, pos, 40);
	}
	SeqListPrint(&s1);
	SeqListInsert(&s1, 0, -1);
	SeqListInsert(&s1, (&s1)->sz, 8);
	SeqListPrint(&s1);


	SeqListDestory(&s1);
}

// 测试指定位置删除
void TestSeqList4()
{
	SL s1;
	SeqListInit(&s1);

	/*
	SeqListInsert可以被头插尾插复用
	*/
	SeqListPushBack(&s1, 1);
	SeqListPushBack(&s1, 2);
	SeqListPushBack(&s1, 3);
	SeqListPushBack(&s1, 4);
	SeqListPushBack(&s1, 5);
	SeqListPrint(&s1);
	
	SeqListPushFront(&s1, 10);
	SeqListPushFront(&s1, 20);
	SeqListPushFront(&s1, 30);
	SeqListPushFront(&s1, 40);
	SeqListPrint(&s1);

	// SeqListErase可以被头删尾删复用
	SeqListErase(&s1, 1);
	SeqListPrint(&s1);

	SeqListPopBack(&s1);
	SeqListPopBack(&s1);
	SeqListPopBack(&s1);

	SeqListPrint(&s1);

	int pos = SeqListFind(&s1, 10);

	if (pos != -1)
	{
		SeqListErase(&s1, pos);
	}
	SeqListPrint(&s1);


}

// 测试指定位置修改
void TestSeqList5()
{
	SL s1;
	SeqListInit(&s1);

	/*
	SeqListInsert可以被头插尾插复用
	*/
	SeqListPushBack(&s1, 1);
	SeqListPushBack(&s1, 2);
	SeqListPushBack(&s1, 3);
	SeqListPushBack(&s1, 4);
	SeqListPushBack(&s1, 5);
	SeqListPrint(&s1);

	
	SeqListModify(&s1, 1, 4);

	SeqListPrint(&s1);

	SeqListDestory(&s1);
}


int main()
{
	//TestSeqList1();
	//TestSeqList2();
	//TestSeqList3();
	//TestSeqList4();
	TestSeqList5();
	return 0;
}