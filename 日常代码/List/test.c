#define _CRT_SECURE_NO_WARNINGS 1 

#include "List.h"

void TestList1()
{
	LTNode* plist = ListInit();// 哨兵位
	ListPushBack(plist, 1);
	ListPushBack(plist, 2);
	ListPushBack(plist, 3);
	ListPushBack(plist, 4);
	ListPushBack(plist, 5);
	ListPrint(plist);

	ListPopBack(plist);
	ListPopBack(plist);
	ListPopBack(plist);
	ListPopBack(plist);
	ListPopBack(plist);
	// 双向链表的缺点
	// 当链表只剩下哨兵位时，链表为空
	// 如果这时候进行删除，会把哨兵位删掉  
	// ListPopBack(plist);

	ListPrint(plist);
}

void TestList2()
{
	LTNode* plist = ListInit();// 哨兵位
	ListPushFront(plist, 1);
	ListPushFront(plist, 2);
	ListPushFront(plist, 3);
	ListPushFront(plist, 4);
	ListPushFront(plist, 5);
	ListPrint(plist);

	ListPushBack(plist, 1);
	ListPushBack(plist, 2);
	ListPushBack(plist, 3);
	ListPushBack(plist, 4);
	ListPushBack(plist, 5);
	ListPrint(plist);

	LTNode* pos = ListFind(plist, 2);
	if (pos)
	{
		ListErase(pos);
	}
	ListPrint(plist);

	ListDestroy(plist);
	plist = NULL;// 手动置空
}

int main()
{
	//TestList1();
	TestList2();

	return 0;
}