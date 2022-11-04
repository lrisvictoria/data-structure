#define _CRT_SECURE_NO_WARNINGS 1 

#include "SList.h"

// �ȹ���һ���򵥵������˽�����Ľṹ

//void TestSList1()
//{
//	// ����1 ��Ϊʲô���ýṹ����������ڵ㣿
//
//	SLTNode* n1 = malloc();
//	SLTNode* n2 = malloc();
//	n1->next = n2;
//
//	// Ҳ�����ӣ�Ϊʲô�����ԣ�
//	SLTNode n3;
//	SLTNode n4;
//	n3.next = &n4;
//
//	// 
//}

void TestSList1()
{
	//SLTNode* n1 = BuySLTNode(1);
	//SLTNode* n2 = BuySLTNode(2);
	//SLTNode* n3 = BuySLTNode(3);
	//SLTNode* n4 = BuySLTNode(4);

	//// ������Ҫ������߼��ṹ������ṹ
	//n1->next = n2;
	//n2->next = n3;
	//n3->next = n4;
	//n4->next = NULL;

	// ��������Ҳ��̫�ã������Ҫ����һ�� n ���ڵ�������أ�
	// ���Կ������⹹��һ������

	int n = 10;

	SLTNode* plist = CreateSList(n);

	SLTPushBack(plist, 100);
	SLTPushBack(plist, 100);
	SLTPushBack(plist, 100);


	SLTPrint(plist);
}

void TestSList2()
{
	SLTNode* plist = NULL;
	SLTPushBack(&plist, 100);
	SLTPushBack(&plist, 100);
	SLTPushBack(&plist, 100);
	SLTPrint(plist);

	SLTPopBack(&plist);
	SLTPrint(plist);
	SLTPopBack(&plist);
	SLTPrint(plist);
	SLTPopBack(&plist);
	SLTPrint(plist);


	SLTPushFront(&plist, 1);
	SLTPushFront(&plist, 2);
	SLTPushFront(&plist, 3);

	SLTPopFront(&plist);
	SLTPrint(plist);
	SLTPopFront(&plist);
	SLTPrint(plist); 
	SLTPopFront(&plist);
	SLTPrint(plist);

}

void TestSList3()
{
	SLTNode* plist = NULL;
	SLTPushBack(&plist, 1);
	SLTPushBack(&plist, 2);
	SLTPushBack(&plist, 3);
	SLTPrint(plist);

	SLTNode* pos = SLTFind(plist, 3);
	SLTInsertAfter(pos, 30);
	SLTPrint(plist);

	pos = SLTFind(plist, 3);
	SLTInsert(&plist, pos, 60);
	SLTPrint(plist);

	pos = SLTFind(plist, 3);
	SLTErase(&plist, pos);
	SLTPrint(plist);

	pos = SLTFind(plist, 2);
	SLTEraseAfter(pos);
	SLTPrint(plist);
}

int main()
{
	//TestSList1();
	//TestSList2();
	TestSList3();
}