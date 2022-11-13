#define _CRT_SECURE_NO_WARNINGS 1 

// 有效的括号


//typedef int STDatatype;
//
//typedef struct Stack
//{
//	STDatatype* a;
//	int capacity;
//	int top;   // 初始为0，表示栈顶位置下一个位置下标
//}ST;
//
//void StackInit(ST* ps);
//void StackDestroy(ST* ps);
//void StackPush(ST* ps, STDatatype x);
//void StackPop(ST* ps);
//STDatatype StackTop(ST* ps);
//
//bool StackEmpty(ST* ps);
//int StackSize(ST* ps);
//
//
//void StackInit(ST* ps)
//{
//	// 结构体一定不为空
//	assert(ps);
//
//	ps->a = (STDatatype*)malloc(sizeof(STDatatype) * 4);
//	if (ps->a == NULL)
//	{
//		perror("malloc fail");
//		exit(-1);
//	}
//	ps->capacity = 4;
//	ps->top = 0;
//}
//
//void StackDestroy(ST* ps)
//{
//	assert(ps);
//
//	free(ps->a);
//	ps->a = NULL;
//	ps->capacity = ps->top = 0;
//}
//
//void StackPush(ST* ps, STDatatype x)
//{
//	assert(ps);
//
//	// 检查容量
//	if (ps->top == ps->capacity)
//	{
//		STDatatype* tmp = (STDatatype*)realloc(ps->a, sizeof(STDatatype) * ps->capacity * 2);
//		if (tmp == NULL)
//		{
//			perror("realloc fail");
//			exit(-1);
//		}
//		ps->a = tmp;
//		ps->capacity *= 2;
//	}
//	// 插入元素
//	// top 为栈顶的下一个元素
//	// 先插入再 ++ 
//	ps->a[ps->top++] = x;
//}
//
//void StackPop(ST* ps)
//{
//	assert(ps);
//
//	// 如果栈空，则不能删除
//	assert(!StackEmpty(ps));
//	ps->top--;
//}
//
//STDatatype StackTop(ST* ps)
//{
//	assert(ps);
//
//	assert(!StackEmpty(ps));
//
//	return ps->a[ps->top - 1];
//}
//
//bool StackEmpty(ST* ps)
//{
//	assert(ps);
//
//	return ps->top == 0;
//}
//
//int StackSize(ST* ps)
//{
//	assert(ps);
//
//	return ps->top;
//}
//
//bool isValid(char* s)
//{
//	ST st;
//	StackInit(&st);
//
//	while (*s)
//	{
//		// 左括号
//		if (*s == '(' || *s == '[' || *s == '{')
//		{
//			// 入栈
//			StackPush(&st, *s);
//			s++;
//		}
//		else
//		{
//			// 右括号匹配，栈为空
//			if (StackEmpty(&st))
//			{
//				// 防止内存泄漏
//				StackDestroy(&st);
//				return false;
//			}
//			// 取栈顶元素，并出栈
//			STDatatype top = StackTop(&st);
//			StackPop(&st);
//			if ((*s == ')' && top != '(')
//				|| (*s == ']' && top != '[')
//				|| (*s == '}' && top != '{'))
//			{
//				return false;
//			}
//			else
//			{
//				s++;
//			}
//		}
//	}
//	// 判断便利结束后，栈是否为空
//	bool ans = StackEmpty(&st);
//	// 销毁栈
//	StackDestroy(&st);
//	return ans;
//}

// 栈实现队列
//typedef int QDataType;
//
//typedef struct QueueNode
//{
//	QDataType data;
//	struct QueueNode* next;
//}QNode;
//
//typedef struct Queue
//{
//	QNode* head;
//	QNode* tail;
//	int sz;
//}Queue;
//
//void QueueInit(Queue* pq);
//void QueueDestroy(Queue* pq);
//void QueuePush(Queue* pq, QDataType x);
//void QueuePop(Queue* pq);
//QDataType QueueFront(Queue* pq);
//QDataType QueueBack(Queue* pq);
//bool QueueEmpty(Queue* pq);
//int QueueSize(Queue* pq);
//
//void QueueInit(Queue* pq)
//{
//	assert(pq);
//
//	pq->head = pq->tail = NULL;
//	pq->sz = 0;
//}
//
//void QueueDestroy(Queue* pq)
//{
//	assert(pq);
//
//	QNode* cur = pq->head;
//
//	while (cur)
//	{
//		QNode* next = cur->next;
//		free(cur);
//		cur = next;
//	}
//
//	pq->head = pq->tail = NULL;
//	pq->sz = 0;
//}
//
//// 尾插
//void QueuePush(Queue* pq, QDataType x)
//{
//	assert(pq);
//
//	QNode* newnode = (QNode*)malloc(sizeof(QNode));
//	if (newnode == NULL)
//	{
//		perror("malloc fail");
//		exit(-1);
//	}
//	else
//	{
//		newnode->data = x;
//		newnode->next = NULL;
//	}
//
//	// 尾插
//	if (pq->tail == NULL)
//	{
//		pq->head = pq->tail = newnode;
//	}
//	else
//	{
//		pq->tail->next = newnode;
//		pq->tail = pq->tail->next;
//	}
//
//	pq->sz++;
//}
//
//void QueuePop(Queue* pq)
//{
//	assert(pq);
//
//	assert(!QueueEmpty(pq));
//	// 一个节点时删除的特殊情况
//	// 需要将头尾都变为空
//	if (pq->head->next == NULL)
//	{
//		free(pq->head);
//		pq->head = pq->tail = NULL;
//	}
//	else
//	{
//		QNode* newhead = pq->head->next;
//		free(pq->head);
//		pq->head = newhead;
//	}
//
//	pq->sz--;
//}
//
//QDataType QueueFront(Queue* pq)
//{
//	assert(pq);
//	assert(!QueueEmpty(pq));
//
//	return pq->head->data;
//}
//
//QDataType QueueBack(Queue* pq)
//{
//	assert(pq);
//	assert(!QueueEmpty(pq));
//
//	return pq->tail->data;
//}
//
//bool QueueEmpty(Queue* pq)
//{
//	assert(pq);
//
//	return pq->head == NULL && pq->tail == NULL;
//}
//
//int QueueSize(Queue* pq)
//{
//	assert(pq);
//
//	/*QNode* cur = pq->head;
//	int size = 0;
//	while (cur)
//	{
//		cur = cur->next;
//		++size;
//	}
//	return size;*/
//
//	return pq->sz;
//}
//
//// ------------------------上方为队列实现---------------------------
//
//typedef struct
//{
//	Queue q1;
//	Queue q2;
//} MyStack;
//
//
//MyStack* myStackCreate()
//{
//	MyStack* obj = (MyStack*)malloc(sizeof(MyStack));
//	QueueInit(&obj->q1);
//	QueueInit(&obj->q2);
//
//	return obj;
//}
//
//void myStackPush(MyStack* obj, int x)
//{
//	if (!QueueEmpty(&obj->q1))
//		QueuePush(&obj->q1, x);
//	else
//		QueuePush(&obj->q2, x);
//}
//
//int myStackPop(MyStack* obj)
//{
//	QNode* empty = &obj->q1;
//	QNode* unempty = &obj->q2;
//	if (!QueueEmpty(&obj->q1))
//	{
//		unempty = &obj->q1;
//		empty = &obj->q2;
//	}
//	while (QueueSize(unempty) > 1)
//	{
//		QueuePush(empty, QueueFront(unempty));
//		QueuePop(unempty);
//	}
//	int top = QueueFront(unempty);
//	QueuePop(unempty);
//	return top;
//}
//
//int myStackTop(MyStack* obj)
//{
//	if (!QueueEmpty(&obj->q1))
//		return QueueBack(&obj->q1);
//	else
//		return QueueBack(&obj->q2);
//}
//
//bool myStackEmpty(MyStack* obj)
//{
//	return QueueEmpty(&obj->q1) && QueueEmpty(&obj->q2);
//}
//
//void myStackFree(MyStack* obj)
//{
//	QueueDestroy(&obj->q1);
//	QueueDestroy(&obj->q2);
//	free(obj);
//}

/**
 * Your MyStack struct will be instantiated and called as such:
 * MyStack* obj = myStackCreate();
 * myStackPush(obj, x);

 * int param_2 = myStackPop(obj);

 * int param_3 = myStackTop(obj);

 * bool param_4 = myStackEmpty(obj);

 * myStackFree(obj);
*/

// 队列实现栈
//typedef int STDatatype;
//
//typedef struct Stack
//{
//	STDatatype* a;
//	int capacity;
//	int top;   // 初始为0，表示栈顶位置下一个位置下标
//}ST;
//
//void StackInit(ST* ps);
//void StackDestroy(ST* ps);
//void StackPush(ST* ps, STDatatype x);
//void StackPop(ST* ps);
//STDatatype StackTop(ST* ps);
//
//bool StackEmpty(ST* ps);
//int StackSize(ST* ps);
//
//void StackInit(ST* ps)
//{
//	assert(ps);
//	ps->a = (STDatatype*)malloc(sizeof(STDatatype) * 4);
//	if (ps->a == NULL)
//	{
//		perror("malloc fail");
//		exit(-1);
//	}
//	ps->capacity = 4;
//	ps->top = 0;
//}
//
//void StackDestroy(ST* ps)
//{
//	assert(ps);
//	free(ps->a);
//	ps->a = NULL;
//	ps->capacity = ps->top = 0;
//}
//
//void StackPush(ST* ps, STDatatype x)
//{
//	assert(ps);
//	if (ps->top == ps->capacity)
//	{
//		STDatatype* tmp = (STDatatype*)realloc(ps->a, sizeof(STDatatype) * ps->capacity * 2);
//		if (tmp == NULL)
//		{
//			perror("realloc fail");
//			exit(-1);
//		}
//		ps->a = tmp;
//		ps->capacity *= 2;
//	}
//	ps->a[ps->top++] = x;
//}
//
//void StackPop(ST* ps)
//{
//	assert(ps);
//	assert(!StackEmpty(ps));
//	ps->top--;
//}
//
//STDatatype StackTop(ST* ps)
//{
//	assert(ps);
//	assert(!StackEmpty(ps));
//	return ps->a[ps->top - 1];
//}
//
//bool StackEmpty(ST* ps)
//{
//	assert(ps);
//	return ps->top == 0;
//}
//
//int StackSize(ST* ps)
//{
//	assert(ps);
//	return ps->top;
//}
//
//typedef struct
//{
//	ST pushST;
//	ST popST;
//} MyQueue;
//
//
//MyQueue* myQueueCreate()
//{
//	MyQueue* queue = (MyQueue*)malloc(sizeof(MyQueue));
//	StackInit(&queue->pushST);
//	StackInit(&queue->popST);
//
//	return queue;
//}
//
//void myQueuePush(MyQueue* obj, int x)
//{
//	assert(obj);
//
//	StackPush(&obj->pushST, x);
//}
//
//// 声明
//bool myQueueEmpty(MyQueue* obj);
//int myQueuePeek(MyQueue* obj);
//
//int myQueuePop(MyQueue* obj)
//{
//	assert(obj);
//	assert(!myQueueEmpty(obj));
//
//	int peek = myQueuePeek(obj);
//	StackPop(&obj->popST);
//
//	return peek;
//}
//
//// 返回队头元素
//int myQueuePeek(MyQueue* obj)
//{
//	assert(obj);
//
//	assert(!myQueueEmpty(obj));
//
//	if (StackEmpty(&obj->popST))
//	{
//		while (!StackEmpty(&obj->pushST))
//		{
//			// 将元素全部倒入 popST 中
//			int pushEle = StackTop(&obj->pushST);
//			StackPush(&obj->popST, pushEle);
//			// 出栈 pushST 中元素
//			StackPop(&obj->pushST);
//		}
//	}
//	// 出栈popST的第一个元素
//	int peek = StackTop(&obj->popST);
//
//	return peek;
//}
//
//bool myQueueEmpty(MyQueue* obj)
//{
//	assert(obj);
//
//	return StackEmpty(&obj->pushST) && StackEmpty(&obj->popST);
//}
//
//void myQueueFree(MyQueue* obj)
//{
//	assert(obj);
//
//	StackDestroy(&obj->pushST);
//	StackDestroy(&obj->popST);
//	free(obj);
//}

/**
 * Your MyQueue struct will be instantiated and called as such:
 * MyQueue* obj = myQueueCreate();
 * myQueuePush(obj, x);

 * int param_2 = myQueuePop(obj);

 * int param_3 = myQueuePeek(obj);

 * bool param_4 = myQueueEmpty(obj);

 * myQueueFree(obj);
*/

// 622. 设计循环队列

typedef struct {
    int* a;
    int front;
    int rear;
    int k;
} MyCircularQueue;


MyCircularQueue* myCircularQueueCreate(int k) {
    MyCircularQueue* obj = (MyCircularQueue*)malloc(sizeof(MyCircularQueue));
    // 多开一个，解决判满的问题
    obj->a = (int*)malloc(sizeof(int) * (k + 1));
    obj->front = obj->rear = 0;
    // 满的时候能存储数据个数，空间大小应该是k+1
    obj->k = k;

    return obj;
}

bool myCircularQueueIsEmpty(MyCircularQueue* obj) {
    assert(obj);
    return obj->rear == obj->front;
}

bool myCircularQueueIsFull(MyCircularQueue* obj) {
    assert(obj);
    return ((obj->rear + 1) % (obj->k + 1)) == obj->front;
}

bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) {
    assert(obj);

    if (myCircularQueueIsFull(obj))
        return false;

    obj->a[obj->rear++] = value;
    if (obj->rear == obj->k + 1)
        obj->rear = 0;

    return true;

    // if(myCircularQueueIsFull(obj))
    //     return false;

    // obj->a[obj->rear++] = value;
    // obj->rear %= (obj->k+1);
    // return true;
}

bool myCircularQueueDeQueue(MyCircularQueue* obj) {
    assert(obj);

    if (myCircularQueueIsEmpty(obj))
        return false;

    obj->front++;
    obj->front %= (obj->k + 1);
    return true;
}

int myCircularQueueFront(MyCircularQueue* obj) {
    assert(obj);
    if (myCircularQueueIsEmpty(obj))
        return -1;
    else
        return obj->a[obj->front];
}

int myCircularQueueRear(MyCircularQueue* obj) {
    assert(obj);
    if (myCircularQueueIsEmpty(obj))
        return -1;
    else
        return obj->a[(obj->rear + obj->k) % (obj->k + 1)];
}

void myCircularQueueFree(MyCircularQueue* obj) {
    free(obj->a);
    free(obj);
}

/**
 * Your MyCircularQueue struct will be instantiated and called as such:
 * MyCircularQueue* obj = myCircularQueueCreate(k);
 * bool param_1 = myCircularQueueEnQueue(obj, value);

 * bool param_2 = myCircularQueueDeQueue(obj);

 * int param_3 = myCircularQueueFront(obj);

 * int param_4 = myCircularQueueRear(obj);

 * bool param_5 = myCircularQueueIsEmpty(obj);

 * bool param_6 = myCircularQueueIsFull(obj);

 * myCircularQueueFree(obj);
*/