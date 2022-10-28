#define _CRT_SECURE_NO_WARNINGS 1 

#include "SeqList.h"

// ����β�塢βɾ
void TestSL1()
{
	SL sl;
	SeqListInit(&sl);
	SeqListPushBack(&sl, 1);
	SeqListPushBack(&sl, 2);
	SeqListPushBack(&sl, 3);
	SeqListPushBack(&sl, 4);
	SeqListPushBack(&sl, 5);

	SeqListPopBack(&sl);
	SeqListPopBack(&sl);
	SeqListPopBack(&sl);
	SeqListPopBack(&sl);
	SeqListPopBack(&sl);
	// ����ӿ��ڲ����������ٴβ���ʱ������˳���ʱ������ᱼ��
	// ���ǽ�����ɾ���������ǲ��ᱼ���ģ���Ϊ��ʱ����˳���ʱ����Ȼ���ٵ��Ƕ�̬���ٵĿռ�
	// ����һ���ٴν��в��룬�ͷǷ������ˣ���ô��ʱ������(free)ʱ�������Χ�ռ���м�飬
	// ��⵽Խ���ˣ��ͻᱨ��

	// SeqListPopBack(&sl);
	// SeqListPushBack(&sl, 6);

	SeqListPrint(&sl);

	SeqListDestory(&sl);
}

// ��������
void TestSL2()
{
	SL sl;
	// SeqListInit(&sl);
	SeqListDestory(&sl);
}

// ����ͷ�塢ͷɾ
void TestSL3()
{
	SL sl;
	SeqListInit(&sl);
	SeqListPushFront(&sl, 1);
	SeqListPushFront(&sl, 2);
	SeqListPushFront(&sl, 3);
	SeqListPushFront(&sl, 4);
	SeqListPushFront(&sl, 5);
	SeqListPrint(&sl);

	SeqListPopBack(&sl);
	SeqListPopBack(&sl);
	SeqListPopBack(&sl);
	SeqListPopBack(&sl);
	SeqListPrint(&sl);

	SeqListPopBack(&sl);
	SeqListPopBack(&sl);

	
	SeqListDestory(&sl);
}

// ���Բ��ҡ�����λ��ɾ��������λ�ò��롢�޸�
void TestSL4()
{
	SL sl;
	SeqListInit(&sl);
	SeqListPushFront(&sl, 1);
	SeqListPushFront(&sl, 2);
	SeqListPushFront(&sl, 3);
	SeqListPushFront(&sl, 4);
	SeqListPushFront(&sl, 5);
	SeqListPrint(&sl);

	if (SeqListFind(&sl, 3))
	{
		SeqListInsert(&sl, SeqListFind(&sl, 3), 6);
	}
	SeqListPrint(&sl);

	if (SeqListFind(&sl, 4))
	{
		SeqListErase(&sl, SeqListFind(&sl, 4));
	}
	SeqListPrint(&sl);

	SeqListModify(&sl, 1, 3);
	SeqListPrint(&sl);


	SeqListPopBack(&sl);
	SeqListPopBack(&sl);


	SeqListDestory(&sl);
}

int main()
{
	//TestSL1();
	//TestSL2();
	//TestSL3();
	TestSL4();

	return 0;
}