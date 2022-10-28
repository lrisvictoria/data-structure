#define _CRT_SECURE_NO_WARNINGS 1 

#include "SeqList.h"

// 测试尾插、尾删
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
	// 如果接口内不做出处理，再次插入时，销毁顺序表时，程序会奔溃
	// 但是仅仅是删除并销毁是不会奔溃的，因为此时销毁顺序表时，仍然销毁的是动态开辟的空间
	// 但是一旦再次进行插入，就非法访问了，那么到时候销毁(free)时，会对周围空间进行检查，
	// 检测到越界了，就会报错

	// SeqListPopBack(&sl);
	// SeqListPushBack(&sl, 6);

	SeqListPrint(&sl);

	SeqListDestory(&sl);
}

// 测试销毁
void TestSL2()
{
	SL sl;
	// SeqListInit(&sl);
	SeqListDestory(&sl);
}

// 测试头插、头删
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

// 测试查找、任意位置删除、任意位置插入、修改
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