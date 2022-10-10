#define _CRT_SECURE_NO_WARNINGS 1 

#include "List.h"

void TestList1()
{
	LTNode* plist = ListInit();// �ڱ�λ
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
	// ˫�������ȱ��
	// ������ֻʣ���ڱ�λʱ������Ϊ��
	// �����ʱ�����ɾ��������ڱ�λɾ��  
	// ListPopBack(plist);

	ListPrint(plist);
}

void TestList2()
{
	LTNode* plist = ListInit();// �ڱ�λ
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
	plist = NULL;// �ֶ��ÿ�
}

int main()
{
	//TestList1();
	TestList2();

	return 0;
}