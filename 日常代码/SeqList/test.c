#define _CRT_SECURE_NO_WARNINGS 1 

#include "SeqList.h"

// ����β�塢βɾ
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

	// ������Ҳ����д�ģ��ܻ��������ʱ��
	// ��Խ��ʱ�����ܻ��鲻����
	// ֻ�е�����ʱ���Żᷢ�ִ���
	SeqListDestory(&s1);
}

// ����ͷ�塢ͷɾ
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
	SeqListPushFront(&s1, 40);// ��������Խ����
	SeqListPrint(&s1);

	SeqListPopFront(&s1);
	SeqListPopFront(&s1);
	SeqListPopFront(&s1);
	SeqListPopFront(&s1);
	SeqListPrint(&s1);

	SeqListDestory(&s1);

}

// ����ָ��λ�ò���
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

// ����ָ��λ��ɾ��
void TestSeqList4()
{
	SL s1;
	SeqListInit(&s1);

	/*
	SeqListInsert���Ա�ͷ��β�帴��
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

	// SeqListErase���Ա�ͷɾβɾ����
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

// ����ָ��λ���޸�
void TestSeqList5()
{
	SL s1;
	SeqListInit(&s1);

	/*
	SeqListInsert���Ա�ͷ��β�帴��
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