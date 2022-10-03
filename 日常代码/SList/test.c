#define _CRT_SECURE_NO_WARNINGS 1 

#include "SList.h"

// ����β�塢���ڵ��ͷ��
void TestList1()
{
	SLTNode* plist = NULL;
	SListPushBack(&plist, 1);
	SListPushBack(&plist, 2);
	SListPushBack(&plist, 3);
	SListPushBack(&plist, 4);
	SListPushBack(&plist, 5);

	SListPrint(plist);

	SListPushFront(&plist, 1);
	SListPushFront(&plist, 2);
	SListPushFront(&plist, 3);
	SListPushFront(&plist, 4);
	SListPushFront(&plist, 5);

	SListPrint(plist);

}

// ����ͷ�塢βɾ
void TestList2()
{
	SLTNode* plist = NULL;

	SListPushFront(&plist, 1);
	SListPushFront(&plist, 2);
	SListPushFront(&plist, 3);
	SListPushFront(&plist, 4);
	SListPushFront(&plist, 5);

	SListPrint(plist);

	SListPopBack(&plist);
	SListPopBack(&plist);
	SListPopBack(&plist);
	SListPopBack(&plist);
	SListPopBack(&plist);
	//SListPopBack(&plist);

	SListPrint(plist);

}

// ����ͷɾ
void TestList3()
{
	SLTNode* plist = NULL;

	SListPushFront(&plist, 1);
	SListPushFront(&plist, 2);
	SListPushFront(&plist, 3);
	SListPushFront(&plist, 4);
	SListPushFront(&plist, 5);

	SListPrint(plist);
	
	SListPopFront(&plist);
	SListPrint(plist);

	SListPopFront(&plist);
	SListPrint(plist);

	SListPopFront(&plist);
	SListPrint(plist);

	SListPopFront(&plist);
	SListPrint(plist);

	SListPopFront(&plist);
	SListPrint(plist);

}


//void TestList4()
//{
//	SLTNode* plist = NULL;
//
//	SListPushFront(&plist, 1);
//	SListPushFront(&plist, 2);
//	SListPushFront(&plist, 3);
//	SListPushFront(&plist, 2);
//	SListPushFront(&plist, 5);
//
//	SLTNode* pos = SListFind(plist, 2);
//	int i = 1;
//	while (pos)
//	{
//		printf("��%d��pos�ڵ㣺%p->%d\n", i++, pos, pos->data); 
//		pos = SListFind(pos->next, 2);
//	}
//
//	// �޸� 3->30
//	pos = SListFind(plist, 3);
//	if (pos)
//	{
//		pos->data = 30;
//	}
//	SListPrint(plist);
//}

void TestList5()
{
	SLTNode* plist = NULL;

	SListPushFront(&plist, 1);
	SListPushFront(&plist, 2);
	SListPushFront(&plist, 3);
	SListPushFront(&plist, 2);
	SListPushFront(&plist, 5);

	// 3ǰ�����һ��30
	SLTNode* pos = SListFind(plist, 3);
	if (pos)
	{
		SListInsert(&plist, pos, 30);
	}
	SListPrint(plist);

	// 5ǰ�����һ��10
	pos = SListFind(plist, 5);
	if (pos)
	{
		SListInsert(&plist, pos, 10);
	}
	SListPrint(plist);
}

int main()
{
	//TestList1();
	//TestList2();
	//TestList3();
	TestList5();

	return 0;
}