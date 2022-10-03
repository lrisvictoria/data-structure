#define _CRT_SECURE_NO_WARNINGS 1 

#include "SList.h"

void TestList1()
{
	SLTNode* plist = NULL;
	SListPushBack(&plist, 1);
	SListPushBack(&plist, 2);
	SListPushBack(&plist, 3);
	SListPushBack(&plist, 4);
	SListPushBack(&plist, 5);

	SListPrint(plist);
}

int main()
{
	TestList1();

	return 0;
}