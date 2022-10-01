#define _CRT_SECURE_NO_WARNINGS 1 

#include "SeqList.h"

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

// дһ������ͨѶ¼�Ĳ˵�
void menu()
{
	printf("************************************\n");
	printf("**********  ��ѡ����Ĳ���:>  ********\n");
	printf("**********  1��ͷ��  2��ͷɾ  ********\n");
	printf("**********  3��β��  4��βɾ  ********\n");
	// ...
	print("************************************\n");
}

int main()
{
	//TestSeqList1();
	TestSeqList2();

	return 0;
}