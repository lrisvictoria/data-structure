#define _CRT_SECURE_NO_WARNINGS 1 

#include "SList.h"

// 测试尾插、尾删
void TestSList1()
{
	SLTNode* plist = NULL;

	SLTPushBack(&plist, 1);
	SLTPushBack(&plist, 2);
	SLTPushBack(&plist, 3);
	SLTPrint(plist);

	SLTPopBack(&plist);
	SLTPrint(plist);
	SLTPopBack(&plist);
	SLTPrint(plist);
	SLTPopBack(&plist);
	SLTPrint(plist);

	SLTPopBack(&plist);

}

// 测试头插、头删
void TestSList2()
{
	SLTNode* plist = NULL;

	SLTPushFront(&plist, 1);
	SLTPushFront(&plist, 2);
	SLTPushFront(&plist, 3);
	SLTPushFront(&plist, 4);
	SLTPrint(plist);

	SLTPopFront(&plist);
	SLTPrint(plist);
	SLTPopFront(&plist);
	SLTPrint(plist);
	SLTPopFront(&plist);
	SLTPrint(plist);
	SLTPopFront(&plist);
	SLTPrint(plist);

	// 删多了
	/*SLTPopFront(&plist);
	SLTPrint(plist);*/

}

// 测试任意位置后插入、删除
void TestSList3()
{
	SLTNode* plist = NULL;
	SLTPushBack(&plist, 1);
	SLTPushBack(&plist, 2);
	SLTPushBack(&plist, 3);
	SLTPrint(plist);

	if (SListFind(plist, 2))
	{
		SLTInsertAfter(SListFind(plist, 2), 6);
	}
	SLTPrint(plist);

	if (SListFind(plist, 2))
	{
		SLTEraseAfter(SListFind(plist, 2));
	}
	SLTPrint(plist);

	// 此情况无法删除
	/*if (SListFind(plist, 3))
	{
		SLTEraseAfter(SListFind(plist, 3));
	}*/
}

// 测试任意位置前插入、删除
void TestSList4()
{
	SLTNode* plist = NULL;

	SLTPushBack(&plist, 1);
	SLTPushBack(&plist, 2);
	SLTPushBack(&plist, 3);
	SLTPrint(plist);

	// 在 2 位置前插入
	if (SListFind(plist, 2))
	{
		SLTInsert(&plist, SListFind(plist, 2), 6);
	}
	SLTPrint(plist);

	if (SListFind(plist, 2))
	{
		SLTErase(&plist, SListFind(plist, 2));
	}
	SLTPrint(plist);
}

int main()
{
	//TestSList1();
	//TestSList2();
	//TestSList3();
	TestSList4();

}