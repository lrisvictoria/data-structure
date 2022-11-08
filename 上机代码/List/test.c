#define _CRT_SECURE_NO_WARNINGS 1 

#include "List.h"

// ����β��βɾ
void TestList1()
{
	LTNode* plist = LTInit();

	LTPushBack(plist, 1);
	LTPushBack(plist, 2);
	LTPushBack(plist, 3);
	LTPushBack(plist, 4);
	LTPrint(plist);

	LTPopBack(plist);
	LTPrint(plist);
	LTPopBack(plist);
	LTPrint(plist);
	LTPopBack(plist);
	LTPrint(plist);
	LTPopBack(plist);
	LTPrint(plist);

	// LTPopBack(plist);
}

// ����ͷ��ͷɾ
void TestList2()
{
	LTNode* plist = LTInit();

	LTPushFront(plist, 1);
	LTPushFront(plist, 2);
	LTPushFront(plist, 3);
	LTPushFront(plist, 4);
	LTPrint(plist);

	LTPopFront(plist);
	LTPrint(plist);
	LTPopFront(plist);
	LTPrint(plist);
	LTPopFront(plist);
	LTPrint(plist);
	LTPopFront(plist);
	LTPrint(plist);

	// LTPopFront(plist);
}

void TestList3()
{
	LTNode* phead = LTInit();
	LTPushFront(phead, 1);
	LTPushFront(phead, 2);
	LTPushFront(phead, 3);
	LTPushFront(phead, 4);
	LTPrint(phead);

	LTNode* pos = LTFind(phead, 3);
	if (pos)
	{
		pos->data = 6;
	}
	LTPrint(phead);

	pos = LTFind(phead, 6);
	// 6 λ��ǰ��һ�� 3
	if (pos)
	{
		LTInsert(pos, 3);
	}
	LTPrint(phead);

	pos = LTFind(phead, 2);
	if (pos)
	{
		LTErase(pos);
	}
	LTPrint(phead);

	LTDestroy(phead);
	phead = NULL;
}

// ���Ը���
void TestList4()
{
	LTNode* plist = LTInit();
	LTPushFront(plist, 1);
	LTPushBack(plist, 2);
	LTPushBack(plist, 3);
	LTPushFront(plist, 4);
	LTPrint(plist);

	LTPopBack(plist);
	LTPrint(plist);

	LTPopFront(plist);
	LTPrint(plist);
}

int main()
{
	// TestList1();
	// TestList2();
	// TestList3();
	TestList4();

	
	return 0;
}