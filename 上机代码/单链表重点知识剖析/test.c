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

	SLTPrint(plist);
}

int main()
{
	TestSList1();
}