#define _CRT_SECURE_NO_WARNINGS 1 

#include "SList.h"

// ����β�塢βɾ
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

// ����ͷ�塢ͷɾ
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

	// ɾ����
	/*SLTPopFront(&plist);
	SLTPrint(plist);*/

}

// ��������λ�ú���롢ɾ��
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

	// ������޷�ɾ��
	/*if (SListFind(plist, 3))
	{
		SLTEraseAfter(SListFind(plist, 3));
	}*/
}

// ��������λ��ǰ���롢ɾ��
void TestSList4()
{
	SLTNode* plist = NULL;

	SLTPushBack(&plist, 1);
	SLTPushBack(&plist, 2);
	SLTPushBack(&plist, 3);
	SLTPrint(plist);

	// �� 2 λ��ǰ����
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